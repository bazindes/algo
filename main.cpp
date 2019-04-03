/*
    main.cpp
    Created by: baz
    Date: 2019-03-28 21:10
*/

#include <iostream>
#include "ds/list/LinkedList.h"
// #include "prac/InvertLinkedList.cpp"
// #include "lc/easy/TwoSum3DatastructureDesign_170.cpp"
#include "lc/easy/RemoveLinkedListElements_203.cpp"

using namespace std;

int main(int argc, char *argv[]) {

  int nums[] = {1,2,2,1};
  LinkedList list(4, nums);
  list.printLinkedList();
  list.head = removeElements(list.head, 2);
  list.printLinkedList();
  int nums2[] = {1,2,6,3,4,5,6};
  LinkedList list2(7, nums2);
  list2.printLinkedList();
  list2.head = removeElements(list2.head, 6);
  list2.printLinkedList();
  int nums3[] = {1,1,1};
  LinkedList list3(3, nums3);
  list3.printLinkedList();
  list3.head = removeElements(list3.head, 1);
  list3.printLinkedList();


  // int nums[] = {1, 2, 3, 5};
  // LinkedList list(4, nums);
  // list.printLinkedList();
  // invert(&list);
  // list.printLinkedList();
  
  // TwoSum_ *ts = new TwoSum_();
  // ts->add(1);
  // ts->add(1);
  // cout << ts->find(0) << endl;
  // cout << ts->find(1) << endl;
  // cout << ts->find(2) << endl;
  // ts->add(-1);
  // cout << ts->find(0) << endl;
  // cout << ts->find(1) << endl;
  // cout << ts->find(-2) << endl;
  // ts->add(-1);
  // cout << ts->find(-2) << endl;
  return 0;
}
//
