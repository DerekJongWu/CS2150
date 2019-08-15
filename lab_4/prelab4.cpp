//Derek Wu
//djw4yv
//prelab4.cpp

#include <iostream>
#include <climits> 
using namespace std;

void sizeOfTest() { 
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl; 
  cout << "Size of float: " << sizeof(float) << endl; 
  cout << "Size of double: " << sizeof(double) << endl; 
  cout << "Size of char: " << sizeof(char) << endl; 
  cout << "Size of bool: " << sizeof(bool) << endl; 
  cout << "Size of pointer to int: " << sizeof(int*) << endl; 
  cout << "Size of pointer to char: " << sizeof(char*) << endl;
  cout << "Size of pointer to double: " << sizeof(double*) << endl; 
}

void outputBinary(unsigned int x) { 
  int i = 31;
  int counter = 0; 
  unsigned int value = x; 
  while (value != 0)  {
    if (value >= (1 << i)) {        
      cout << 1;  
      value = value - (1 << i);
      i = i -1; 
      counter ++;     
    } 
    else {
      cout << 0; 
      i = i - 1; 
      counter ++; 
    }
    if (counter % 4 == 0) {
      cout << " "; 
    }
  } 
  cout << " " << endl; 
}

void overflow() { 
  unsigned int z = UINT_MAX; 
  z = z + 1; 
  cout << z << endl; 
  cout << "The reported value is 0, this happens because by adding one you go past the max and loop back to 0" << endl; 
}
int main () { 
  sizeOfTest();
  cout << "Enter an integer: ";
  unsigned int y; 
  cin >> y;  
  outputBinary(y);
  overflow(); 
  return 0;  
}

