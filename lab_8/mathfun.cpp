//Derek Wu
//djw4yv
//3/26/2018
//8AM Lab

#include <iostream> 
#include <cstdlib> 

using namespace std;

extern "C" int product(int, int); 
extern "C" int power(int, int); 

int main() { 

  int x,y; 

  cout << "Enter a value: "; 
  cin >> x;
  
  cout << "Enter another value: ";
  cin >> y; 
  
  cout << "The product of the two numbers: " << product(x,y) << endl; 
  cout << x << " to the " << y << " equals " << power(x,y) << endl; 

  return 0; 
} 
