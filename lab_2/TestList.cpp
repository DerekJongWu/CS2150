//Derek Wu
//djw4yv
//TestList.cpp 

#include 'List.h'
#include <iostream> 
using namespace std;

int main() { 
  List *a = new List; 
  if (a -> head == NULL) {
    cout << "Head was created sucessfully" << endl; 
  } 
  return 0; 
}
