//Derek Wu 
//djw4yv
//2/7/2018
//StackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H 
#include <iostream>
using namespace std; 

class StackNode { 
 public: 
  StackNode();

 private: 
  int value; 
  StackNode *next;
  friend class Stack; 

};

#endif
