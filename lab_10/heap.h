//Derek Wu

#ifndef HEAP_H
#define HEAP_H
#include "HuffmanNode.h" 
#include <iostream> 
#include <vector> 
#include <unordered_map> 

using namespace std; 

class Heap {
 public:
  Heap();
  Heap(vector<HuffmanNode*> vec);
  ~Heap();
  void insert(HuffmanNode* x);
  HuffmanNode* findMin();
  HuffmanNode* deleteMin();
  unsigned int size();
  void makeEmpty();
  bool isEmpty();
  void print();
  void printEncode(HuffmanNode* n,string currstr);
  unordered_map<char, string> lib;
  string getBits(char letter);
  int getSize(); 
 private:
  vector<HuffmanNode*> heap;
  unsigned int heap_size; 
  void percolateUp(int hole);
  void percolateDown(int hole);
};

#endif
