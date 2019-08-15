//Derek Wu 
//djw4yv
//3/1/2018

#ifndef BST_H
#define BST_H
#include <iostream> 
#include <string> 

using namespace std; 

class BinaryNode {
  BinaryNode();  
  string value;
  BinaryNode* left;
  BinaryNode* right;

  friend class BinarySearchTree;
};

class BinarySearchTree {
 public:
  BinarySearchTree();
  ~BinarySearchTree();

  // insert finds a position for x in the tree and places it there.
  void insert(const string& x);
  // remove finds x's position in the tree and removes it.
  void remove(const string& x);

  // pathTo finds x in the tree and returns a string representing the path it
  // took to get there.
  string pathTo(const string& x) const;
  // find determines whether or not x exists in the tree.
  bool find(const string& x) const;
  // numNodes returns the total number of nodes in the tree.
  int numNodes() const;

 private:
  // Declare a root node
  BinaryNode* root;
  void insert(const string &x, BinaryNode *&b);
  BinaryNode* remove(const string &x, BinaryNode *&b);
  string pathTo(const string &x, BinaryNode *b) const; 
  bool find(const string& x, BinaryNode *b) const; 
  int numNodes(BinaryNode *b) const; 
  // Any other methods you need...
};

#endif
