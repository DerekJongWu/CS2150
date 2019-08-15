//Derek Wu 
//djw4yv
//TestListNode.cpp 

#include "ListNode.h"
#include <iostream>
using namespace std; 
 
int main() {
  ListNode *d = new ListNode();
  cout << "You made a node!" << endl; 

  if (d -> value == 0) { 
    cout << "Value is set correctly" << endl;
  }

  if (d -> next == NULL) {
    cout << "Pointer next is set correctly" << endl;
  }

  if (d -> previous == NULL) {
    cout << "Pointer previous is  set correctly" << endl;
  }

  return 0;
 
}
