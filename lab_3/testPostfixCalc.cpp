//Derek Wu
//djw4yv
//2/2/2018
//testPostfixCalc.cpp

#include "postfixCalculator.h"
#include <iostream> 
//#include <stack>
#include <cstdlib> 
using namespace std;

int main() {  
  string s;
  PostfixCalculator stack;
  while (cin >> s) {
    int count = 0;  
    char c = s.at(0);
    if (s.size() > 1) {
      while (s.size() > count) { 
	char c = s.at(count); 
	if (isdigit(c) == true) {
	  count ++;
	  break; 
	}
	else {
	  count ++; 
	}
      int b = atoi(s.c_str());
      stack.push(b);
      continue; 
      }
    }
    if (isdigit(c) == true) { 
      int a = atoi(s.c_str());       
      stack.push(a);
    }
    else { 
      if (s == "*") { 
	stack.multiplication();
      }
      if (s == "/") { 
	stack.division();
      }
      if (s == "-") { 
	stack.subtraction();
      }
      if (s == "+") { 
	stack.add(); 
      }
      if (s == "~") { 
	stack.unarynegate();
      }
    }
  } 
  cout << "The answer is: " <<  stack.top() << endl; 
 return 0; 
}
