//Derek Wu 
//djw4yv
//2/2/2018
//postfixCalculator.cpp

#include "postfixCalculator.h"
#include <iostream> 
//#include <stack>
#include <cstdlib> 
using namespace std; 

PostfixCalculator :: PostfixCalculator() { 
  d = stack<int>();
}

void PostfixCalculator :: push(int e) { 
  d.push(e); 
}

int PostfixCalculator :: top() { 
  if (d.empty()) {
    exit(-1); 
  } 
  else {
    return d.top();
  }
}

void PostfixCalculator :: pop() {
  if (d.empty()) { 
    exit(-1);
  }
  else { 
    d.pop();
  }
}

bool PostfixCalculator :: empty() { 
  return d.empty();
}
void PostfixCalculator :: add() { 
  int x = d.top();
  d.pop(); 
  int y = d.top();
  d.pop();
  int sum = y + x; 
  d.push(sum); 
}

void PostfixCalculator :: subtraction() { 
  int x = d.top();
  d.pop();
  int y = d.top();
  d.pop();
  int difference = y-x;
  d.push(difference);  
} 

void PostfixCalculator :: multiplication() { 
  int x = d.top();
  d.pop(); 
  int y = d.top();
  d.pop(); 
  int product = y * x; 
  d.push(product); 
} 

void PostfixCalculator :: division() { 
  int x = d.top();
  d.pop();
  int y = d.top();
  d.pop();
  int quotient = y/x; 
  d.push(quotient); 
} 

void PostfixCalculator :: unarynegate() { 
  int x = d.top();
  d.pop(); 
  int neg = x * (-1); 
  d.push(neg);
} 
