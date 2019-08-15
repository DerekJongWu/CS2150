//Derek Wu 

#include <iostream> 
#include <cstdlib> 
#include "timer.h" 

using namespace std; 

extern "C" int threexplusone(int); 

int main() { 
  timer t; 
  int x;
  int n; 
  cout << "Enter a value: "; 
  cin >> x;
  cout << "Enter number of times: "; 
  cin >> n; 
  t.start();
  for (int i = 0; i < n; i++) { 
    cout << threexplusone(x);
    cout << endl; 
  }
  t.stop();
  cout << "Average time: ";
  double tot = (t.getTime()*1000)/n;
  cout << tot;
  cout << " ms";
  cout << endl;    
  return 0;

}
