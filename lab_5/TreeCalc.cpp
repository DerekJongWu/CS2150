// Derek Wu 
// djw4yv
// 2/25/2018
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib> 
#include <stack> 
using namespace std;

//Constructor
TreeCalc::TreeCalc() {
  mystack  = stack<TreeNode*>(); 
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  while (!mystack.empty()) {
    cleanTree(mystack.top());
    mystack.pop();
  }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr != NULL) {
  if (ptr -> left == NULL && ptr -> right == NULL) { 
    delete ptr; 
  }
  cleanTree(ptr -> left); 
  cleanTree(ptr -> right);
  } 
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  if (isdigit(val[0]) || isdigit(val[1])) { 
    TreeNode *n = new TreeNode();
    n -> value = val; 
    mystack.push(n);
  }
  else {
    TreeNode * root = new TreeNode();
    TreeNode * a = new TreeNode();
    a =  mystack.top();
    mystack.pop(); 
    TreeNode * b = new TreeNode();
    b = mystack.top();
    mystack.pop();
    root -> value = val; 
    root -> right = a; 
    root -> left = b;
    mystack.push(root);  
  }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if (ptr != NULL) { 
    cout << (ptr -> value);
    cout << " ";  
    printPrefix(ptr -> left); 
    printPrefix(ptr -> right);
  }

}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
  if (ptr != NULL) { 
    if (isdigit((ptr -> value).front()) == false) { 
      cout << "(";  
    }
    printInfix(ptr -> left);
    if (isdigit((ptr -> value).front()) == false && (ptr->value).size() < 2) {
	cout << " ";
	cout << (ptr -> value); 
	cout << " "; 
      } 
    else { 
    cout << (ptr -> value);
    }    
    printInfix(ptr -> right);
    if (isdigit((ptr->value).front()) ==  false && (ptr -> value).size() < 2) { 
      cout << ")";
    }
  } 
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
  if (ptr != NULL) { 
    printPostfix(ptr -> left); 
    printPostfix(ptr -> right); 
    cout << (ptr -> value);
    cout << " ";  
  }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(mystack.top()); 
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(mystack.top());
        cout << endl;
    }
    else {
        cout<< "Size is 0." << endl;
    }
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
  if (ptr == NULL) { 
    return 0; 
  }
  if (ptr -> left == NULL && ptr -> right == NULL) { 
    return atoi(&(ptr -> value).front()); 
  }
  int left = calculate(ptr -> left); 
  int right = calculate(ptr -> right); 
  if (ptr -> value == "+") { 
    return (left) + (right); 
  }
  if (ptr -> value == "-") { 
    return (left) - (right); 
  }
  if (ptr -> value == "*") { 
    return (left) * (right); 
  }
  else  {   
    return (left)/(right);
  } 
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
  int i = calculate(mystack.top());
  while (!mystack.empty()) {
    cleanTree(mystack.top());
    mystack.pop();
  }
  return i; 
}
