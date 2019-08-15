//Derek Wu
//djw4yv

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <unordered_map>
#include "HuffmanNode.h"

using namespace std;

/*
void ReadBits(HuffmanNode* root, string bits) {  
  for (int i = 0; i < bits.length(); i++) { 
    if (root -> left == NULL && root -> right == NULL) { 
      cout << root -> value; 
    }
    else { 
      if (bits[i] == '1') {
	ReadBits(root -> right, bits.substr(1));
      }
      else { 
	ReadBits(root -> left, bits.substr(1));
      } 
    }
  }
}
*/

void makeHuffmanTree (HuffmanNode* root, string prefix, char c) { 
  if (prefix.size() == 1) { 
    HuffmanNode* ins = new HuffmanNode();
    if (prefix == "1") { 
      ins -> value = c; 
      root -> right = ins; 
    }
    if (prefix == "0") {
      ins -> value = c;  
      root -> left = ins;
    }
  }
  else { 
    if (prefix[0] == '1') {
      if (root -> right != NULL) {  
	makeHuffmanTree(root -> right, prefix.substr(1), c);
      }
      else { 
	HuffmanNode* ins1 = new HuffmanNode();
	root -> right = ins1; 
	makeHuffmanTree(root -> right, prefix.substr(1),c);
      }
    }
    if (prefix[0] == '0') { 
      if (root -> left != NULL) { 
	makeHuffmanTree(root -> left, prefix.substr(1), c); 
      }
      else { 
	HuffmanNode* ins2 = new HuffmanNode(); 
	root -> left = ins2; 
	makeHuffmanTree(root-> left, prefix.substr(1), c);
      }
    }
  }
}
// main(): we want to use parameters
int main (int argc, char **argv) {
  // verify the correct number of parameters
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the only parameter" << endl;
    exit(1);
  }
  // attempt to open the supplied file; must be opened in binary
  // mode, as otherwise whitespace is discarded
  ifstream file(argv[1], ifstream::binary);
  // report any problems opening the file and then exit
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
  // read in the first section of the file: the prefix codes
  string character; 
  string prefix;
  unordered_map<string, string> codes; 
  while ( true ) {
    //string character, prefix;
    // read in the first token on the line
    file >> character;
    // did we hit the separator?
    if ( (character[0] == '-') && (character.length() > 1) )
      break;
    // check for space
    if ( character == "space" )
      character = " ";
    // read in the prefix code
    file >> prefix;
    // do something with the prefix code 
    codes.insert(make_pair(character,prefix));
    cout << "character '" << character << "' has prefix code '"
	 << prefix << "'" << endl;
  }
  // read in the second section of the file: the encoded message
  stringstream sstm;
  while ( true ) {
    string bits;
    // read in the next set of 1's and 0's
    file >> bits;
    // check for the separator
    if ( bits[0] == '-' )
      break;
    // add it to the stringstream
    sstm << bits;
  }
  string allbits = sstm.str();
  // at this point, all the bits are in the 'allbits' string
  cout << "All the bits: " << allbits << endl;
  // close the file before exiting
  file.close();

  //Create the Huffman Tree from the prefix codes
  unordered_map <string, string> :: iterator itr; 
  HuffmanNode* input_node = new HuffmanNode();
  for (itr = codes.begin(); itr != codes.end(); itr++) { 
    string param = itr -> first; 
    makeHuffmanTree(input_node, itr -> second, param[0]);
  } 
  //cout << input_node -> right -> left -> left -> value << endl; 
  //Read bits 
  HuffmanNode* currNode = input_node; 
  for (int i = 0; i < allbits.length() + 1; i++) { 
    if (currNode -> left == NULL & currNode -> right == NULL) { 
      cout << currNode -> value; 
      currNode = input_node;
      i = i - 1; 
    }
    else { 
      if (allbits[i] == '1') { 
	currNode = currNode -> right; 
      }
      else { 
	currNode = currNode -> left; 
      }
    } 
  }
  cout << endl;
  return 0; 
}
