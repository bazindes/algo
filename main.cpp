/*
    main.cpp
    Created by: baz
    Date: 2019-03-28 21:10
*/

#include "ds/list/LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int nums[] = {1, 2, 3, 5};
  LinkedList list(4, nums);

  list.printLinkedList();
  return 0;
}
//
