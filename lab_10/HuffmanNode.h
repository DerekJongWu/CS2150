//Derek Wu 

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <iostream> 

using namespace std; 

class HuffmanNode { 
 public: 
  HuffmanNode(); 
  HuffmanNode(const char &charac, const int &num);
  char value; 
  int freq; 
  HuffmanNode *left, *right;   
};

#endif
