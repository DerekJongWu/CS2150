//Derek Wu
//djw4yv
//3/1/2018

#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <cstring> 

using namespace std; 

BinaryNode :: BinaryNode() { 
  left = NULL;
  right = NULL;
  value = " ";  
}

BinarySearchTree :: BinarySearchTree() { 
  root = NULL;  
}

BinarySearchTree :: ~BinarySearchTree() { 

}

void BinarySearchTree :: insert(const string& x) { 
  insert(x, root); 
}

void BinarySearchTree :: remove(const string& x) { 
  root = remove(x,root);
}

string BinarySearchTree :: pathTo(const string &x) const {
  return pathTo(x, root); 
}

bool BinarySearchTree :: find(const string &x) const { 
  return find(x, root); 
}

int BinarySearchTree :: numNodes() const { 
  return numNodes(root); 
} 
void BinarySearchTree :: insert(const string &x, BinaryNode *&b) {  
  if (b == NULL) { 
    BinaryNode *n = new BinaryNode(); 
    n -> value = x; 
    b = n; 
  }

  if ((b -> value) < x) {
    insert(x, b -> right);  
  }

  if ((b -> value) > x) { 
    insert(x, b -> left); 
  } 
  else { 
  } 
}

BinaryNode* BinarySearchTree :: remove(const string &x, BinaryNode *&b) {
  if (b == NULL) { 
    return NULL; 
  }
  if (x == b -> value) {
    if (b -> left == NULL && b -> right == NULL) { 
      delete b;
      return NULL; 
    } 
    if (b -> left == NULL) { 
      return b-> right; 
    }
    if (b->right == NULL) { 
      return b -> left; 
    }
  }
  else if (x < b -> value) { 
    b -> left = remove(x, b -> left);
  }
  else { 
    b -> right = remove(x, b -> right); 
  }
  return b; 
} 

string BinarySearchTree :: pathTo(const string &x, BinaryNode *b) const { 
  string final = "";
  if (b == NULL) { 
    return " "; 
  }
  if (x == b -> value) { 
    final = " " + final + (b->value); 
  }
  else if (x > b -> value) { 
    final = " " + final + b-> value +  pathTo(x,b -> right); 
  }
  else if (x < b -> value) { 
    final =" " + final + b-> value + pathTo(x,b -> left); 
  }
  return final; 
}

bool BinarySearchTree :: find(const string &x, BinaryNode *b) const { 
  if (b == NULL) { 
    return false; 
  } 
  if (b -> value > x) { 
    return find(x, b-> left); 
  } 
  if (x > b -> value) { 
    return find(x, b-> right); 
  }
  else { 
    return false;  
 } 
}

int BinarySearchTree :: numNodes(BinaryNode *b) const {  
  int c = 1; 
  if (b -> right != NULL) { 
    c += numNodes(b->right); 
  }
  if (b->left != NULL) { 
    c += numNodes(b->left);
  }
  return c; 
}
