//Derek Wu
//djw4yv 
//hashTable.cpp
//8 AM LAB 
//3/12/2018
#include <iostream>
#include "hashTable.h" 
#include <vector>
#include <list>  
#include <fstream>
#include <string> 
#include <cmath> 
using namespace std; 

bool hashTable :: checkprime(unsigned int p) { 
  if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases                      
    return false;
  if ( p == 2 ) // 2 is prime                                                              
    return true;
  if ( p % 2 == 0 ) // even numbers other than 2 are not prime                             
    return false;
  for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p                       
    if ( p % i == 0 )
      return false;
  return true;
}

int hashTable :: getNextPrime (unsigned int n) {
  while ( !checkprime(++n) );
  return n; // all your primes are belong to us                                            
}


hashTable :: hashTable(string dictionary) {
  int counter = 0; 
  string line; 
  ifstream myfile(dictionary.c_str()); 
  if(myfile.is_open()) { 
    while (getline(myfile,line)) { 
      counter++; 
    }
  }
  int size = 0;  
  if (checkprime(counter)) { 
    size = counter; 
  }
  else {
    size = getNextPrime(counter);
  } 
  hash.resize(counter); 
  myfile.close();
  string words; 
  ifstream data(dictionary.c_str());
  if(data.is_open()) {
    while (getline(data, words)) { 
      unsigned int bin = 0; 
      /*for (int i = 0; i < words.length(); i++) {
	bin = bin + ((int) words[i] * pow(37, i));   
      }
      bin = bin % hash.size();
      */ 
      bin = (int)words[0];
      if (hash[bin].empty() == true) { 
	list<string> list; 
	list.push_back(words);
	hash[bin] = list;
      }
      else {
	hash[bin].push_back(words); 
      } 
    }
  }
}

bool hashTable :: find(string c) {  
  unsigned int bin = 0;
  /*for (int i = 0; i < c.length(); i++) {
    bin = bin + ((int)c[i] * pow(37, i));
  }
  */
  bin = (int)c[0];
  list<string> :: iterator it; 
  for (it = hash[bin].begin(); it != hash[bin].end(); ++it) {
    if (*it == c) { 
      return true; 
    }
    else { 
      continue; 
    }
  }  
  return false; 
} 


