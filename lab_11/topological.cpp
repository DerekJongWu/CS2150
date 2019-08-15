//Derek Wu 
//8 AM Lab 

#include <vector> 
#include <unordered_map>
#include <queue> 
#include <list> 
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;


/** @brief Produce a topological sort of a given graph

 *
 * This main method is supposed to topolgoically sort a graph that is inputted through a text file. 

 *@return a topological sort
 *@param txt The text file that includes the graph
 *@param argc Checks to see how many parameters were passed in at the command line.
 *@todo Need to create the graph and then topologically sort the graph. 
 */

// we want to use parameters                                                    
int main (int argc, char **argv) {
  // verify the correct number of parameters                                  
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter"\
	 << endl;
    exit(1);
  }
  vector<string> edges; 
  unordered_map<string, int> map;
  int counter = 0; 
  // attempt to open the supplied file                                        
  ifstream file(argv[1], ifstream::binary);
  // report any problems opening the file and then exit                       
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
  else { 
    string s1,s2;
    while(true) {  
      file >> s1;
      file >> s2;
      edges.push_back(s1);
      edges.push_back(s2);
      if (s1 == "0") { 
	break; 
      } 
      if (map.find(s1) == map.end()) { 
	map.insert(make_pair(s1,counter));
	counter++;
      }
      if (map.find(s2) == map.end()) { 
	map.insert(make_pair(s2,counter));
	counter++;
      } 
      else { 
	continue;
      } 
    }
  }
  // string comparison done with ==, but not shown here                       
  // close the file before exiting                                            
  file.close();
  //Creating adjacency matrix 
  
  int adj[counter][counter]; 
  adj[1][1] = 1; 
  cout << adj[1][1] << endl; 
  cout << counter << endl;   
  unordered_map<string, int> :: iterator itr; 
  for (itr = map.begin(); itr!= map.end(); itr++) { 
    cout << itr -> first << " " << itr -> second; 
    cout << endl; 
  }
 
  // string comparison done with ==, but not shown here                                                                                        
  // close the file before exiting                                                                                                             
  file.close();

  cout << endl; 

  for (int i = 0; i < counter; i++) {
    for (int n = 0; n < counter; n++) {
      adj[i][n] = 0;
    }
  }
  //Create the adjacency matrix
  int index = 0; 
  while (edges[index] != "0") { 
    string class1 = edges[index];
    index++; 
    string class2 = edges[index]; 
    int index1 = map[class1]; 
    int index2 = map[class2]; 
    adj[index1][index2] = 1; 
    index++; 
  }

  for (int i = 0; i < counter; i++) { 
    for (int n = 0; n < counter; n++) { 
      cout << adj[i][n];
    }
    cout << endl;
  }

  cout << endl;
  vector<int>out; //stores the final output 
  queue<int> q; //queue for topsort 
  int sum = 0; //check for indegree 
  for (int i = 0; i < counter; i++) { 
    for(int n = 0; n < counter; n++) { 
      for (int a = 0; a < counter; a++) { 
	sum = sum + adj[a][n];  // sum all of the values in each column
      }
      bool there = false; //check to see if the node was already visited
      for (int b = 0; b < out.size(); b++) { 
	if (n == out[b]) { 
	  there = true; 
	}
	else { 
	  there = false; 
	}
      }
      //push to the queue if the sum is zero and it hasnt already been visited
      if (sum == 0 && there == false) {
	cout << n; 
	q.push(n); 
      }
      else { 
	sum = 0; 
	continue;
      }
    }
    while (!q.empty()) { 
      int output = q.front();
      //cout<< output;  
      out.push_back(output);  
      q.pop(); 
      for (int b = 0; b < counter; b++) { 
	adj[output][b] = 0; 
      }
    }
  }
  return 0; 
}










