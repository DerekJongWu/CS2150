//Derek Wu
//djw4yv
//1/29/2018    
//ListItr.cpp 

#include "ListItr.h" 
#include <iostream> 
using namespace std; 

ListItr :: ListItr() { 
  current = NULL; 
} 

ListItr :: ListItr(ListNode* theNode) { 
  current = theNode; 
} 

bool ListItr :: isPastEnd() const {
  if (current -> next == NULL) { 
    return true;
  }
  else {
    return false;
  } 
}

bool ListItr:: isPastBeginning() const { 
  if (current -> previous == NULL) {
    return true;
  }
  else {
    return false;
  }
}

void ListItr ::  moveForward() {
  current = current -> next; 
}

void ListItr :: moveBackward() { 
  current = current -> previous; 
}

int ListItr ::  retrieve() const { 
  return current -> value;
}

