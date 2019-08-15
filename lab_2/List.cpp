//Derek Wu 
//djw4yv
//1/29/2018
//List.cpp

#include "List.h" 
#include <iostream> 
using namespace std; 

//constructor
List :: List() {
  head = new ListNode;
  tail = new ListNode;
  head -> next = tail;
  tail -> previous = head;
  count = 0;  
} 

//Copy Constructor 
List::List(const List& source) {
  head = new ListNode;
  tail = new ListNode;
  head -> next = tail;
  tail -> previous = head;
  count = 0;
  ListItr iter(source.head -> next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}


//Deconstructor 
List :: ~List() {
  makeEmpty(); 
  delete head;
  delete tail;
  
} 

//Equals Operator 
List& List :: operator = (const List& source) { 
  if (this == &source) {
    return *this; 
  }
  else { 
    makeEmpty();
    ListItr iter(source.head -> next); 
    while (!iter.isPastEnd()) { 
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this; 
}

//Check if List is empty 
bool List:: isEmpty() const { 
  if (count == 0) { 
    return true; 
  }
  else {  
    return false;
  } 
} 

//Remove all items 
void List::makeEmpty() { 
  ListItr itr (head -> next);
  while (itr.current -> next != NULL) { 
    itr.moveForward(); 
    head -> next = itr. current;
    delete itr.current -> previous; 
    itr.current -> previous = head;  
    count = count - 1; 
  }

}

//Returns an Itr that points to index 0 
ListItr List:: first () { 
  ListItr itr(head -> next);
  return itr;    
}

//Returns an Itr that points to last position 
ListItr List::last() { 
  ListItr itr(tail -> previous);
  return itr; 
}

//Insert After
void List::insertAfter(int x, ListItr position) { 
  ListNode *n = new ListNode();
  n -> value = x; 
  ListNode *point1 = position.current; 
  ListNode *point2 = position.current -> next;
  n -> next = point2;
  n -> previous = point1;
  point1 -> next = n; 
  point2 -> previous = n; 
  count ++;
}

//Insert Before
void List::insertBefore(int x, ListItr position) { 
  ListNode *n = new ListNode();
  n -> value = x; 
  ListNode *point1 = position.current;
  ListNode *point2= position.current -> previous;  
  n -> next = point1; 
  n -> previous = point2; 
  point1 -> previous = n;
  point2 -> next = n;  
  count++; 
} 
 
//Insert x at Tail 
void List:: insertAtTail(int x) { 
  ListNode *n = new ListNode();
  n -> value = x; 
  ListNode *prev = tail -> previous; 
  n -> next = tail;
  n -> previous = prev; 
  tail -> previous = n; 
  prev -> next = n; 
  count ++; 
}
//Removes the first occurence of x 
void List :: remove(int x) {
  ListItr itr(head -> next);
  if (count == 0) { 
    return; 
  }
  else { 
  while (itr.current -> value != x) {
    itr.moveForward();
  }
  ListNode *n = itr.current -> next; 
  ListNode *p = itr.current -> previous;
  p -> next = n;
  n -> previous = p; 
  delete itr.current;    
}
}


//Return an iterator that points to first occurence of x 
ListItr List ::  find(int x) { 
  ListItr itr(head -> next);
  while (itr.current -> value != x) { 
    itr.moveForward();
  }
  return itr; 
}

//Returns number of elements in list 
int List :: size() const { 
  return count; 
}


void printList(List& source, bool direction) { 
  if (direction == true) { 
    ListItr itr (source.first()); 
    while (itr.isPastEnd() != true) { 
      cout << itr.retrieve() << " "; 
      itr.moveForward(); 
    }
    cout << " " << endl;
  }
  else { 
    ListItr itr(source.last());
    while (itr.isPastBeginning() != true) { 
      cout << itr.retrieve() << " ";  
      itr.moveBackward(); 
    } 
    cout << " " << endl;
  }
}
