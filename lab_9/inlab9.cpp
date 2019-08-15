//Derek Wu 
//djw4yv

#include "timer.h"
#include <iostream> 

using namespace std;

int main() { 
  timer t;
  t.start();
  int n = 5; 
  for (int i = 0; i < n; i++) {
    cout << i;
    cout << endl; 
  }
  t.stop(); 
  double tot = t.getTime();
  double fin = tot*1000; 
  cout << fin; 
  cout << endl; 
  return 0;
} 
