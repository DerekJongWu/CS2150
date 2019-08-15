//Derek Wu 

#include "HuffmanNode.h" 
#include <iostream> 

using namespace std; 

HuffmanNode :: HuffmanNode(const char &charac, const int &num) { 
  value = charac; 
  freq = num;
  left = NULL; 
  right = NULL; 
}

HuffmanNode :: HuffmanNode() { 
  value = '-';
  freq = 0; 
  left = NULL; 
  right = NULL; 
}
