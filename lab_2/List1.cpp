//Derek Wu 
//djw4yv
//List1.cpp 

#include "List.h" 
#include <iostream> 
using namespace std;

List :: void makeEmpty() {
  ListNode *temp1 = new ListNode;
  temp1 = head;
  while (temp1 -> next != NULL) {
    ListNode *temp2 = new ListNode;
    temp2 = temp1;
    temp1 = temp1 -> next;
    delete temp 2;
  }
  delete temp1;
}


List :: ListItr first () {
  ListItr itr = new ListItr;
  if (itr -> next != NULL) {
    current = itr -> next;
  }
  return itr;
}

List :: ListItr last() {
  ListItr itr = new ListItr
    if (itr -> next != NULL) {
      current = itr -> next;
    }
  return itr;
}

List :: void insertAfter(int x, ListItr position) {
  ListNode a = new ListNode;
  a -> next = position -> next;
  a -> previous = *position;
  position -> next = a;
  a -> value = x;
}

List:: void insertBefore(int x, Listitr position) {
  Listnode a = new ListNode;
  a -> next = *position;
  a -> previous = postion -> previous;
  position -> previous = a;
  a -> value = x;
}
