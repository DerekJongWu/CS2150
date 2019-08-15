//Derek Wu
//djw4yv
//2/7/2018
//Stack.cpp

#include "Stack.h" 
#include <iostream> 
using namespace std; 

Stack :: Stack() { 
  head = new StackNode; 
  count = 0; 
  head -> next = NULL; 
}

Stack :: ~Stack() { 
  while (count != 0) { 
    StackNode *n = head; 
    n -> next = head; 
    delete n; 
    count = count -1; 
  }
}

bool Stack :: isEmpty() const { 
  if (count == 0) { 
    return true; 
  }
  else { 
    return false; 
  }
}

void Stack :: push(int e) { 
  StackNode *n = new StackNode(); 
  n -> value = e; 
  n -> next = head;
  head = n;
  count ++;    
} 

void Stack :: pop() { 
  StackNode *n = head; 
  n -> next = head; 
  delete n; 
}

int Stack :: top() const { 
  StackNode *n = head; 
  return head -> value; 
}

