#include "DataIntergrity.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;


unordered_map<int, vector<pair<int, int>>> graph;


// Add an edge to the graph u landmark_A, v landmark_B, w weight
void DataIntergrity::AddEdge(int u, int v, int w){
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

void DataIntergrity::LoadGraphFromCSV(const string& filename){
  ifstream file(filename);
  if(!file.is_open()){
    cout << "Error opening file " << filename << endl;
    return;
  }

  string line;

  while(getline(file, line)){
    stringstream ss(line);
    int node, neighbour, time;
    char comma;
    ss >> node >> comma >> neighbour >> comma >> time;

    AddEdge(node, neighbour, time);
  }

    file.close();
    cout << "CSV file " << filename << " read successfully!" << endl;
}

void DataIntergrity::display() const {
        for (const auto& [node, neighbors] : graph) {
            cout << "Landmark " << node << " connects to:" << endl;
            for (const auto& [neighbor, weight] : neighbors) {
                cout << "  -> Landmark " << neighbor << " with time " << weight << endl;
            }
        }
    }

bool DataIntergrity::detectSelfLoop(){
	for(auto& [node, neighbour] : graph){
        for(auto& [neighbor, _] : neighbour){
            if(node == neighbor){
                cout << "Self loop detected at node " << node << endl;
                return false;
            }
        }
	}
    return true;
};


//Check if there is a cycle loop in the graph by iterating through all neighbors of the node
bool DataIntergrity::detectCycleLoop(int node, unordered_set<int> visited, unordered_set<int> stack){
	visited.insert(node);
    stack.insert(node);

    // Iterate through all neighbors of the node
    for (const auto& [neighbor, _] : graph[node]) {

      	// If the neighbor is in the stack, then there is a cycle
        if (stack.count(neighbor)) {
            return true; // Cycle detected
        }

        // If the neighbor has not been visited, then recursively check if there is a cycle
        if (!visited.count(neighbor) && detectCycleLoop(neighbor, visited, stack)) {
            return true; // Cycle detected in recursive call
        }
    }

    // Remove the node from the stack
    stack.erase(node);
    return false; // No cycle detected
};

bool DataIntergrity::ValidateGraphIntergrity(){
	unordered_set<int> visited, stack;

    if(!detectSelfLoop()){
        cout << "The graph is not perfect" << endl;
      return false;
    }

    for(auto& [node, _] : graph){
      if(!visited.count(node)){
      	if(detectCycleLoop(node, visited, stack)){;
          return false;
        }
      }
    }
    cout << "The graph is perfect" << endl;
    return true;
};