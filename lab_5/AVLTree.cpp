//Derek Wu 
//djw4yv
//3/1/2018
 
#include "AVLTree.h"
#include <string>
#include <iostream> 
#include <cstring> 
using namespace std;

// Implement the following
AVLNode::AVLNode() {
  left = NULL; 
  right = NULL;
  value = "" ;
  height = 0; 
}
AVLTree::AVLTree() {
  root = NULL;
}
AVLTree::~AVLTree() {
  cleanTree(root);
}

void AVLTree :: cleanTree(AVLNode *& n){ 
  if (n -> left == NULL && n -> right == NULL) { 
    delete n; 
  }
  else { 
    delete n -> left; 
    delete n -> right; 
  }
}

void AVLTree::insert(const string& x) {
  insert(x,root); 
}

int AVLTree :: bfac(AVLNode *b) {
  if (b == NULL) {
    return 0;
  }
  else {
    return height(b -> right) - height(b->left);
  }
}

void AVLTree :: insert(const string &x, AVLNode *&b) { 
  if (b == NULL) { 
    AVLNode *n = new AVLNode();
    n -> value = x; 
    b = n; 
  }

  else if ((b -> value) < x) { 
    insert(x,b->right);
  }

  else if ((b -> value ) > x) { 
    insert(x, b->left);
  }
  else { 
  } 
  b -> height = max(height(b -> left), height(b -> right)) + 1; 
  balance(b); 
}

string AVLTree ::  pathTo(const string& x) const {
  return pathTo(x, root); 
}
bool AVLTree :: find(const string& x) const {
  return true; 
}
int AVLTree :: numNodes() const {
  return numNodes(root); 
}

// The following are implemented for you
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

AVLNode* AVLTree :: rotateRight(AVLNode*&n) { 
  AVLNode * c = n -> left; 
  n -> left = c ->right; 
  c -> right = n; 
  n -> height = max(height(n -> left), height(n -> right)) + 1; 
  c -> height = max(height(c -> left), height(c->right)) + 1; 
  return c; 
}

AVLNode* AVLTree :: rotateLeft(AVLNode *&n) { 
  AVLNode * c = n -> right;
  n -> right = c -> left; 
  c -> left = n; 
  n -> height = max(height(n -> left), height(n->right)) + 1;
  c -> height = max(height(c->left), height(c->right)) + 1;
  return c; 
}
void AVLTree ::  balance(AVLNode *& n) { 
  int fac = bfac(n);
  if (fac > 1) { 
    if (bfac(n -> right) < 0) { 
      n -> right = rotateRight(n -> right); 
      n = rotateLeft(n); 
    }
    else { 
      n = rotateLeft(n); 
    }
  }
  else if (fac < -1) { 
    if (bfac(n->left) > 0) { 
      n -> left = rotateLeft(n->left); 
      n = rotateRight(n); 
    }
    else { 
      n = rotateRight(n); 
    }
  }
}

string AVLTree :: pathTo(const string&x, AVLNode *b) const { 
  string final = "";
  if (b == NULL) { 
    return ""; 
  }
  if (x == b -> value) { 
    final = " " + final + (b->value); 
  }
  else if (x > b -> value) { 
    final = " " + final + b->value + pathTo(x,b->right); 
  }
  else if (x < b -> value) { 
    final = " " + final + b -> value + pathTo(x,b->left); 
  }
  return final; 
}

int AVLTree :: numNodes(AVLNode *b) const { 
  int c = 1; 
  if (b -> right != NULL) { 
    c += numNodes(b -> right);
  }
  if (b -> left != NULL) { 
    c += numNodes(b -> left); 
  }
  return c; 
}
// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      return n->right;
    }
    if (n->right == NULL) {
      return n->left;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

