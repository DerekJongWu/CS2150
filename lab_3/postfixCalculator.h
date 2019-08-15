//Derek Wu 
//djw4yv
//2/2/2018
//postfixCalculator.h 

#ifndef POSTFIXCALCULATOR_H 
#define POSTFIXCALCULATOR_H 
#include <iostream> 
#include <stack>
using namespace std; 

class PostfixCalculator{ 
 public: 
  PostfixCalculator();
  void push(int e);
  int top();
  void pop();
  bool empty();
  void add(); 
  void subtraction();
  void multiplication(); 
  void division();
  void unarynegate();

 private: 
  stack<int> d ;
};

#endif  
