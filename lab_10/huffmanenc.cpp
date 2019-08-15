//Derek Wu
//huffmanenc.cpp 

#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include "heap.h"
#include "HuffmanNode.h" 

using namespace std; 

int main(int argc, char **argv) { 
  unordered_map<char, int> hash; 
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter"\
	 << endl;
    exit(1);
  }
  FILE *fp = fopen(argv[1], "r");
  // if the file wasn't found, output and error message and exit              
  if ( fp == NULL ) {
    cout << "File '" << argv[1] << "' does not exist!" << endl;
    exit(2);
  }
  unordered_map<char,int>:: iterator itr; 
  char g;
  while ( (g = fgetc(fp)) != EOF ) {
    if (g == '\n') { 
      continue; 
    }  
    if (hash.find(g) == hash.end()) { 
      hash.insert(make_pair(g,1));
    }
    else {
      hash.find(g) -> second = hash.find(g) -> second + 1; 
    }
  }
  /*
 for (itr = hash.begin(); itr != hash.end(); itr++) {  
    cout << itr->first << " " << itr -> second;  
    cout << endl; 
 }
  */
 rewind(fp); 
 //cout << "---------------------------------------";
 //cout << endl; 
 Heap h = Heap(); 
 for (itr = hash.begin(); itr != hash.end(); itr++) {
   HuffmanNode* ins = new HuffmanNode(itr -> first, itr -> second);
   h.insert(ins);
 }
 /* while (h.isEmpty() != true) {
   cout << h.deleteMin() -> value;
   cout << endl; 
   }*/
 while (h.size() > 1) { 
   HuffmanNode* one = h.deleteMin(); 
   HuffmanNode* two = h.deleteMin();
   HuffmanNode* rent = new HuffmanNode(); 
   rent -> freq = (one -> freq) + (two -> freq);
   rent -> left = one; 
   rent -> right = two; 
   h.insert(rent); 
 }
 h.printEncode(h.findMin(), " ");
 cout << "-------------------------------------";
 cout << endl; 
 int counter = 0;
 string out = ""; 
 while ( (g = fgetc(fp)) != EOF ) {
   if (int(g) > 31 && int(g) < 127) { 
     out.append(h.getBits(g));
     counter = counter + 1;  
   }
 }
 cout << out; 
 cout << endl; 
 cout << "-------------------------------------";
 cout << endl; 
 cout <<"There are a totoal of " <<  counter << " symobls." << endl; 
 cout << "There are " << h.getSize() << " distinct symbols used." << endl; 
 cout << "There were " << counter * 8 << " bits in the original file" << endl;
 int counter1 = 0;
 for (int i = 0; i < out.length(); i++) { 
   if (out[i] == ' ') { 
     continue; 
   }
   else { 
     counter1++; 
   }
 }
 cout << "There were " << counter1 << " bits in the compressed file." <<  endl;
 double ratio = double (counter*8)/counter1;
 cout << "This gives a compression ratio of " << ratio << "."<< endl;
 double cost = double (counter1)/counter; 
 cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl; 
 return 0; 
} 
