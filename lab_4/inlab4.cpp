//Derek Wu 
//djw4yv
//2/13/2018 
//inlab4.cpp 

#include <iostream> 
#include <limits> 
using namespace std; 

int main() {
  int a = 1;
  unsigned int b = 1; 
  float c = 1.0;  
  double d = 1.0; 
  char e = '1';
  bool f = false;

  cout << "maximum value for bool " << numeric_limits<bool>::max()<< endl;
  cout << "maximum value for char: " << numeric_limits<char>::max()<< endl;  
  cout << a << endl; 
  cout << b << endl; 
  cout << c << endl; 
  cout << d << endl; 
  cout << e << endl; 
  cout << f << endl; 
 
//-Primitive Arrays in C++---------------------------------------------------- 
  int IntArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  char CharArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

  int IntArray2D[2][3] = { {1,2,3}, {4,5,6} } ;
  char CharArray2D[2][3] = { {'a','b','c'}, {'d','e','f'} }; 
  cout << IntArray << endl; 
  cout << CharArray << endl;
  cout << IntArray2D << endl; 
  cout << CharArray2D << endl; 
  return 0; 
} 
