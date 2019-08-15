//Derek Wu 
//djw4yv
//2/7/2018
//Stack.h 

#ifndef STACK_H 
#define STACK_H 
#include <iostream>
#include "StackNode.h" 
using namespace std; 

class Stack { 
 public: 
  Stack();
  ~Stack();
  bool isEmpty() const;
  void push(int value);
  void pop();
  int top() const; 

 private: 
  StackNode *head; 
  int count; 

};

#endif
