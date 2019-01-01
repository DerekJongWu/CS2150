o//Derek Wu
//djw4yv
//xToN.cpp
#include <iostream>
using namespace std; 

int xToN(int a, int b) {
  if (b == 0)
    return 1;
  return a* xToN(a,(b-1));
}

int main( ) { 
    int x,y,z;
    cout<< "Enter the a number: " << endl;
    cin >> x; 
    cout << "Enter the exponent: " << endl;
    cin >> y;
    z = xToN(x,y);
    cout << x << " ^ " << y << " = " << z << endl; 
    return 0; 
}

	     
