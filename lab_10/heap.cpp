//Derek Wu

#include <unordered_map>
#include <iostream>
#include "heap.h"
#include "HuffmanNode.h"
using namespace std;

// default constructor
Heap::Heap() : heap_size(0) {
  heap.push_back(0); 
}

// builds a heap from an unsorted vector
Heap::Heap(vector<HuffmanNode*> vec) : heap_size(vec.size()) {
  heap = vec;
  heap.push_back(heap[0]);
  heap[0] = 0;
  for ( int i = heap_size/2; i > 0; i-- )
    percolateDown(i);
}

// the destructor doesn't need to do much
Heap::~Heap() {
}

void Heap::insert(HuffmanNode* x) {
  // a vector push_back will resize as necessary
  heap.push_back(x);
  // move it up into the right position
  percolateUp(++heap_size);
}

void Heap::percolateUp(int hole) {
  // get the value just inserted
  HuffmanNode* x = heap[hole];
  // while we haven't run off the top and while the
  // value is less than the parent...
  for ( ; (hole > 1) && (x -> freq < heap[hole/2] -> freq); hole /= 2 )
    heap[hole] = heap[hole/2]; // move the parent down
  // correct position found!  insert at that spot
  heap[hole] = x;
}

HuffmanNode* Heap::deleteMin() {
  // make sure the heap is not empty
  if ( heap_size == 0 )
    throw "deleteMin() called on empty heap";
  // save the value to be returned
  HuffmanNode* ret = heap[1];
  // move the last inserted position into the root
  heap[1] = heap[heap_size--];
  // make sure the vector knows that there is one less element
  heap.pop_back();
  // percolate the root down to the proper position
  if (heap_size > 1) {  
  percolateDown(1);
  }
  // return the old root node
  return ret;
}

void Heap::percolateDown(int hole) {
  // get the value to percolate down
  HuffmanNode* x = heap[hole];
  // while there is a left child...
  while ( hole*2 <= heap_size ) {
    int child = hole*2; // the left child
    // is there a right child?  if so, is it lesser?
    if ( (child+1 <= heap_size) && (heap[child+1] -> freq < heap[child] -> freq) )
      child++;
    // if the child is greater than the node...
    if ( x -> freq  > heap[child] -> freq ) {
      heap[hole] = heap[child]; // move child up
      hole = child;             // move hole down
    } else
      break;
  }
  // correct position found!  insert at that spot
  heap[hole] = x;
}

HuffmanNode* Heap::findMin() {
  if ( heap_size == 0 )
    throw "findMin() called on empty heap";
  return heap[1];
}

unsigned int Heap::size() {
  return heap_size;
}

void Heap::makeEmpty() {
  heap_size = 0;
  heap.resize(1);
}

bool Heap::isEmpty() {
  return heap_size == 0;
}

void Heap::print() {
  cout << "(" << heap[1] -> freq << ") "; 
  for ( int i = 1; i <= heap_size; i++ ) {
    cout << heap[i] -> value; 
    cout << heap[i] -> value << " ";
    // next line from from http://tinyurl.com/mf9tbgm
    bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    if ( isPow2 )
      cout << endl << "\t";
  }
  cout << endl;
}

void Heap :: printEncode(HuffmanNode* n, string currstr) {
  if(n -> left == NULL && n -> right == NULL) {
    if(n -> value == ' ') {
      cout << "space" << currstr << endl;  
    }
    else {
      cout << n -> value << currstr << endl;
    } 
    lib.insert(make_pair(n->value,currstr)); 
  }

  if (n-> left != NULL) { 
    printEncode(n->left, currstr + "0");
  }
  if (n-> right != NULL) { 
    printEncode(n->right, currstr + "1"); 
  }
}

string Heap :: getBits(char letter) { 
  return lib[letter];
}

int Heap :: getSize() { 
  return lib.size(); 
} 
