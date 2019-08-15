//Derek Wu 
//djw4yv
//hashTable.h
//3/12/2018
//8AM LAB
#ifndef HASHTABLE_H
#define HASHTABLE_H 

#include <vector> 
#include <list>
#include <iostream> 
#include <string>

using namespace std; 

class hashTable { 
 public: 
  hashTable(string dictionary);
  bool find(string c);
  vector < list<string> > hash;  

 private: 
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n); 

};

#endif
