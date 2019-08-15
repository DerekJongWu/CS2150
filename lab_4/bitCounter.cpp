//Derek Wu 
//djw4yv
//2/15/2018
//bitCounter.cpp

#include <cmath> 
#include <iostream> 
using namespace std; 

int bitCounter(int n) {
  int count = 0;  
  if (n == 0) { 
    return 0; 
  }
  if (n == 1) { 
    return 1; 
  } 
    if (n % 2 == 0) { 
      return (count + bitCounter(n/2));
    }
    else { 
      int x = floor(n/2); 
      return (count + bitCounter(x) + 1); 
    } 
}


int main(int argc, char ** argv) {
  if (argc < 2) { 
    cout << "Input a value" << endl; 
    return 0; 
  }   
  for (int i = 1; i < argc; i++) { 
    int value = atoi(argv[i]); 
    cout << bitCounter(value) << endl; 
  }
  return 0; 
}
