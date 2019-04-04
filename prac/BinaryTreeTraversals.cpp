#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
struct Node {
  int key;
  int s; // only used by Schorr-Waite
  Node *l, *r;
  Node(int key, Node *l, Node *r) : key(key), l(l), r(r), s(0) {}
  void visit() const {
    printf("%d\n", key);
  }
};
enum Type { PREORDER, INORDER, POSTORDER };
/*
preorder模拟栈版：栈中存放的节点`x`表示之后待遍历`x`的子树。
*/
void preorder(Node *p)
{
  if (p) {
    p->visit();
    preorder(p->l);
    preorder(p->r);
  }
}
/*
inorder模拟栈版：栈中存放的节点`x`表示`x`待访问，且之后遍历`x`的右子树。
*/
void inorder(Node *p)
{
  if (p) {
    inorder(p->l);
    p->visit();
    inorder(p->r);
  }
}
void postorder(Node *p)
{
  if (p) {
    postorder(p->l);
    postorder(p->r);
    p->visit();
  }
}
void preorder_stack(Node *p)
{
  stack<Node *> s;
  for(;;) {
    while (p) {
      p->visit();
      if (p->r)
        s.push(p->r);
      p = p->l;
    }
    if (s.empty()) break;
    p = s.top();
    s.pop();
  }
}
void inorder_stack(Node *p)
{
  stack<Node *> s;
  for(;;) {
    while (p) {
      s.push(p);
      p = p->l;
    }
    if (s.empty()) break;
    p = s.top();
    s.pop();
    p->visit();
    p = p->r;
  }
}
/*
栈中存放的节点`x`表示两种阶段之一：
1. 当前在访问`x`左子树，之后待遍历`x`的右子树，然后访问`x`。
2. 当前在访问`x`的右子树，之后待访问`x`。
祖先节点进入阶段2的时刻晚于后裔节点。
外层循环开始处即`while (p) {`行，以下两个条件之一满足：
1. `p`非NULL，需要遍历`p`子树，栈上存放`p`的所有祖先。
2. `p`为NULL，栈上是栈顶及栈顶的所有祖先，下一个访问的是栈顶。
遍历一棵子树的方式是沿着左孩子链接下溯并把沿途节点都压栈，直到遇到NULL。
若遇到的最后一个节点`x`有右孩子`y`，则当前指针置为`y`，`x`及`x`的一些连续的祖先进入阶段2；
否则(第二个while循环实现这一复杂逻辑)说明`x`已在阶段2，访问`x`，
同时`x`一些连续的祖先也进入阶段2了，也需要访问并从栈中弹出。
*/
void postorder_stack(Node *p)
{
  stack<Node *> s;
  for(;;) {
    while (p) {
      s.push(p);
      p = p->l;
    }
    while (! s.empty() && s.top()->r == p) {
      p = s.top();
      s.pop();
      p->visit();
    }
    if (s.empty()) break;
    p = s.top()->r;
  }
}
void postorder2_stack(Node *p)
{
  stack<Node *> s;
  for(;;) {
    while (p) {
      if (p->r)
        s.push(p->r);
      s.push(p);
      p = p->l;
    }
    if (s.empty()) break;
    p = s.top();
    s.pop();
    if (! s.empty() && p->r == s.top()) {
      s.pop();
      s.push(p);
      p = p->r;
    } else {
      p->visit();
      p = NULL;
    }
  }
}
/*
按层级顺序访问，使用队列进行BFS
*/
void level_order(Node *p)
{
  queue<Node *> q;
  if (p) {
    q.push(p);
    while (! q.empty()) {
      p = q.front();
      q.pop();
      p->visit();
      if (p->l)
        q.push(p->l);
      if (p->r)
        q.push(p->r);
    }
  }
}
/*
preorder或inorder可以实现O(1)额外空间的遍历，
方法是把右孩子为空的节点的右孩子改造成中序后继的线索指针。
*/
void morris_traversal(Node *p, Type t)
{
  while (p) {
    Node *q = p->l;
    if (q) {
      while (q->r && q->r != p) q = q->r;
      if (q->r == p)
        q->r = NULL;
      else {
        if (t == PREORDER)
          p->visit();
        q->r = p;
        p = p->l;
        continue;
      }
    } else if (t == PREORDER)
      p->visit();
    if (t == INORDER)
      p->visit();
    p = p->r;
  }
}
// morris_postorder_traversal的辅助函数
void reverse_right_chain(Node *x, Node *y)
{
  Node *p = x, *q = x->r, *r;
  while (p != y) {
    r = q->r;
    q->r = p;
    p = q;
    q = r;
  }
}
/*
增量构造线索进行post-order遍历比较复杂
*/
void morris_postorder_traversal(Node *p)
{
  Node aux;
  aux.l = p;
  aux.r = NULL;
  p = &aux;
  while (p) {
    Node *q = p->l;
    if (q) {
      while (q->r && q->r != p) q = q->r;
      if (q->r == p) {
        reverse_right_chain(p->l, q);
        for (Node *r = q; ; r = r->r) {
          r->visit();
          if (r == p->l) break;
        }
        reverse_right_chain(q, p->l);
        q->r = NULL;
      } else {
        q->r = p;
        p = p->l;
        continue;
      }
    }
    p = p->r;
  }
}
/* Schorr-Waite graph marking algorithm
 *
 * 该算法需要在节点信息里额外维护一个域 s，表示遍历过程中的访问次数，有如下几种取值：
 * 0: 尚未访问
 * 1: 访问过1次(preorder)，尚未遍历其左右子树
 * 2: 访问过2次(inorder)，已遍历其左子树，尚未遍历其右子树
 * 3: 访问过3次(postorder)，已遍历其左右子树
 *
 * 访问到 x 时，其祖先节点及它们的子树遍历进度(在遍历左子树还是右子树)是通过栈维护的。
 * 该算法把祖先节点下溯的指针翻转，再通过设置一个父节点指针 p 以把祖先节点组织为一个链。
 * 通过 s 可以知道各祖先节点当前在遍历左子树还是右子树。
 *
 * 若注释掉代码中的 x->s = 0; 则在算法执行完后遍历到的节点的 s 值为3，可以判断节点是否被访问过。
 *
 * 该算法可用于遍历一般的有向图，也需要注释掉 x->s = 0。带有 q 个指针域的节点将被访问 q+1 次。
 */
void schorr_waite(Node *x, Type t)
{
  if (! x) return;
  Node *y, *p = NULL;
  for(;;) {
    if ((int)t == (int)x->s)
      x->visit();
    if (x->s < 2) {
      x->s++;
      y = x->s == 1 ? x->l : x->r;
      if (y && y->s == 0) {
        (x->s == 1 ? x->l : x->r) = p;
        p = x;
        x = y;
      }
    } else {
      x->s = 0;               // reset to 0
      if (! p) return;
      y = x;
      x = p;
      if (x->s == 1)
        p = x->l, x->l = y;
      else
        p = x->r, x->r = y;
    }
  }
}
// http://www.cs.cornell.edu/courses/cs312/2007fa/lectures/lec21-schorr-waite.pdf
// 下面是一种变体，也可用于一般有向图，每个节点都有两个指针域
// 原始的Schorr-Waite在下溯时把指针和 p 交换，上溯时再交换回来
// 该方法使用四指针置换和三指针置换来统一几种逻辑判断
void schorr_waite_alternative(Node *p, Type t)
{
  Node *q = (Node *)-1;
  while (p != (Node *)-1) {
    if ((int)t == (int)p->s)
      p->visit();
    p->s++;
    if (p->s == 3 || p->l && p->l->s == 0) {
      Node *r = p->l;
      p->l = p->r;
      p->r = q;
      q = p;
      p = r;
    } else {
      Node *r = p->l;
      p->l = p->r;
      p->r = q;
      q = r;
    }
  }
}
// Lindstrom-Dwyer algorithm
// Schorr-Waite的变体，对于二叉树，上面 schorr_waite_alternative 的代码可以进一步简化
// 考察条件 p->s == 3 || p->l && p->l->s == 0
// 若 p->s != 3 则有 1 <= p->s && p->s <= 2
// 此时 p->l 为原节点的左子树或右子树，因为是树，不存在其他节点的指向它们
// 因此 p->l 若非 NULL 则必有 p->l->s != 0
// 该条件只有在 p->l == NULL 时不成立。即使不成立，我们依然可以套用四指针置换
// 但需要把 p(此时为NULL) 设为 q，把 q 设为 NULL
// 之后 s 仅用于判断节点访问次数，不再参与逻辑控制
// 如果不在乎一个节点调用 visit 三次的话，可以省去 s
void lindstrom_dwyer(Node *p)
{
  Node *q = (Node *)-1;
  while (p != (Node *)-1) {
    p->visit();
    Node *r = p->l;
    p->l = p->r;
    p->r = q;
    q = p;
    p = r;
    if (! p) p = q, q = NULL;
  }
}
int main()
{
  Node *a[7];
  for (int i = 7; i--; )
    a[i] = new Node(i, i*2+1 < 7 ? a[i*2+1] : NULL, i*2+2 < 7 ? a[i*2+2] : NULL);
  preorder(a[0]);
  inorder(a[0]);
  postorder(a[0]);
  level_order(a[0]);
  morris_traversal(a[0], PREORDER);
  morris_traversal(a[0], INORDER);
  preorder_stack(a[0]);
  inorder_stack(a[0]);
  postorder_stack(a[0]);
  postorder2_stack(a[0]);
  schorr_waite(a[0], PREORDER);
  schorr_waite(a[0], INORDER);
  schorr_waite(a[0], POSTORDER);
  schorr_waite_alternative(a[0], PREORDER);
  schorr_waite_alternative(a[0], INORDER);
  schorr_waite_alternative(a[0], POSTORDER);
  lindstrom_dwyer(a[0]);
}