#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);
/**
 *@brief find the best smallest path length for the supplied cities. Create an earth with a number of cities that are provided. 
 *@return The return value of 0 just to show that the function was completed.                                         
 *@param argc is the number if command line inputs passed through the main function.                                  
 */

int main (int argc, char **argv) {
  // check the number of parameters                                                                                   
  if ( argc != 6 ) {
    cout << "Usage: " << argv[0] << " <world_height> <world_width> "
         << "<num_cities> <random_seed> <cities_to_visit>" << endl;
    exit(0);
  }
  // we'll assume the parameters are all well-formed                                                                  
  int width, height, num_cities, rand_seed, cities_to_visit;
  sscanf (argv[1], "%d", &width);
  sscanf (argv[2], "%d", &height);
  sscanf (argv[3], "%d", &num_cities);
  sscanf (argv[4], "%d", &rand_seed);
  sscanf (argv[5], "%d", &cities_to_visit);
  // Create the world, and select your itinerary                                                                      
  MiddleEarth me(width, height, num_cities, rand_seed);
  vector<string> dests = me.getItinerary(cities_to_visit);
  vector<string> final = dests;
  string starting = dests[0];
  //for (int i = 0; i < dests.size(); i++) {                                                                          
  //cout << dests[i] << endl;                                                                                         
  //}                                                                                                                 
  sort(dests.begin()+1, dests.end());
  float out = computeDistance(me, starting, dests);
  while (next_permutation(dests.begin()+1, dests.end())) {
    float test = computeDistance(me, dests[0], dests);
    if (test < out) {
      out = test;
      final = dests;
    }
    else {
      continue;
    }
  }
  cout << "Your journey will take you along the path ";
  printRoute(final[0], final);
  cout << endl;
  cout << "It will have a length of " <<  out;
  cout << endl;
  return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests               
// vector IN ORDER, and ends back at the 'start' parameter.                                                           
/**                                                                            
 *@brief compute the total cycle length for all of the cities in the path. 
 *@return the total distance of the whole cycle.                                                                      
 *@param me is the earth that was created.                                                                            
 *@param start is the home location of the cycle                                                                      
 *@param dests is a vector that inlcudes all of the cities that have to be visited in the cycle.                      
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float distance = 0.0;
  string prev = start;
  for (int i = 0; i < dests.size(); i++) {
    distance = distance + me.getDistance(prev, dests[i]);
    prev = dests[i];
  }
  distance = distance + me.getDistance(start, dests.back());
  return distance;
}

// This method will print the entire route, starting and ending at the                                                
// 'start' parameter.  The output should be of the form:                                                              
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor                                           
/**                                                                        
 *@brief prints all of the nodes in the cycle beginning with the home city and ending with the home city.                                            
 *@return nothing, the function will print out all of the nodes in the cycle but return nothing.                      
 *@param start is the starting location in the cycle   
 *@param dests is all of the cities that are in the cycle.
 */
void printRoute (string start, vector<string> dests) {
  for(int i = 0; i < dests.size(); i++) {
    cout << dests[i] << " -> ";
  }
  cout << start;
}

