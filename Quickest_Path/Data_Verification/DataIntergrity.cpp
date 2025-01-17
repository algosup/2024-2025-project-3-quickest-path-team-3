#include "DataIntergrity.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;


unordered_map<int, vector<pair<int, int>>> graph;


/////////// Add an edge to the graph u landmark_A, v landmark_B, w weight ///////////
void DataIntergrity::AddEdge(int u, int v, int w){
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
}

////////////// Load the graph from the CSV file //////////////
void DataIntergrity::LoadGraphFromCSV(const string& filename){

  ifstream file(filename); // Open the file

  if(!file.is_open()){ // Check if the file is open
    cout << "Error opening file " << filename << endl;
    return;
  }



/* Read the file line by line and add the edges to the graph */
  string line;

  while(getline(file, line)){
    stringstream ss(line); // Convert the line to a stringstream
    int node, neighbour, time; // Variables to store the landmark A, landmark B and time/unit, respectively.
    char comma;
    ss >> node >> comma >> neighbour >> comma >> time; // Read the line

    AddEdge(node, neighbour, time); //call the AddEdge function to add the line to the graph
  }
	ValidateGraphIntergrity(); // call the ValidateGraphIntergrity function to check the integrity of the graph
    file.close(); // Close the file
    cout << "CSV file " << filename << " read successfully!" << endl;
}


/////////////// Display the graph /////////////////
void DataIntergrity::display() const {
        for (const auto& [node, neighbors] : graph) { // Iterate through all nodes in the graph
            cout << "Landmark " << node << " connects to:" << endl;
            for (const auto& [neighbor, weight] : neighbors) { // Iterate through all neighbors of the node
                cout << "  -> Landmark " << neighbor << " with time " << weight << endl;
            }
        }
    }


////////////////////// Check the integrity of the graph by checking if there is any self-loop //////////////////////
bool DataIntergrity::detectSelfLoop(){
	for(auto& [node, neighbour] : graph){ // Iterate through all nodes in the graph
        for(auto& [neighbor, _] : neighbour){ // Iterate through all neighbors of the node
            if(node == neighbor){ // If the node is the same as the neighbor, then there is a self loop
                cout << "Self loop detected at node " << node << endl;
                return false;
            }
        }
	}
    return true;
};


///////// Check if there is a cycle loop in the graph by iterating through all neighbors of the node ///////////
bool DataIntergrity::detectCycleLoop(int node, unordered_set<int>& visited, unordered_set<int>& stack, vector<int>& path){
	visited.insert(node);
    stack.insert(node);
    path.emplace_back(node);

    for (const auto& [neighbor, _] : graph[node]) { // Iterate through all neighbors of the node
      	/* If the neighbor is in the stack, then there is a cycle */
        if (stack.contains(neighbor)) {

            cout << "path leader : ";
            for (const int n : path) {
                cout << n << " -> ";
            }
            cout << neighbor << endl;
            cout << "Cycle detected, path: " << endl;
            for(auto it = find(path.begin(), path.end(), neighbor);it != path.end(); ++it){

              cout << *it << " -> ";
            }
            cout << neighbor << endl;
            //return true; // Cycle detected
        }

        /* If the neighbor has not been visited, then recursively check if there is a cycle */
        if (!visited.contains(neighbor) && detectCycleLoop(neighbor, visited, stack, path)) {

            cout << "path leader : ";
            for (const int n : path) {
                cout << n << " -> ";
            }
            cout << neighbor << endl;
          	cout << "Cycle detected " << endl;

            for(auto it = find(path.begin(), path.end(), neighbor);it != path.end(); ++it){
              cout << *it << " -> ";
            }
            cout << neighbor << endl;
            //return true; // Cycle detected in recursive call
        }

    }


    stack.erase(node); // Remove the node from the stack
    path.pop_back(); // Remove the node from the path
    return false; // No cycle detected
};


///////////// Check the integrity of the graph by checking if there is any self-loop and cycle loop //////////
bool DataIntergrity::ValidateGraphIntergrity(){
	unordered_set<int> visited, stack;
    vector<int> path;

    /* If there is a self loop, then the graph is not perfect */
    if(!detectSelfLoop()){
        cout << "The graph is not perfect" << endl;
      return false;
    }

    for(auto& [node, _] : graph){ // Iterate through all nodes in the graph
      /* If the node has not been visited, then recursively check if there is a cycle */
      if(!visited.count(node)){
      	if(detectCycleLoop(node, visited, stack, path)){
          return false;
        }
      }
    }
    cout << "The graph is perfect" << endl;
    return true;
};