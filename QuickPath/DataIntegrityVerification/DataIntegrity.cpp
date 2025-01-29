#include "DataIntegrity.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

using namespace std;


unordered_map<int, vector<pair<int, int> > > graph;


////////////// Add an edge to the graph u landmark_A, v landmark_B, w weight /////////////
void DataIntegrity::AddEdge(int u, int v, int w){
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
}


////////////////// Load the graph from the CSV file //////////////////
void DataIntegrity::LoadGraphFromCSV(const std::string& filename){
  ifstream file(filename); // Open the file
  if(!file.is_open()){ // Check if the file is open
    cout << "Error opening file " << filename << endl;
    return;
  }

  string line;

  while(getline(file, line)){
    stringstream ss(line); // Convert the line to a stringstream
    int node, neighbour, time; // Variables to store the landmark A, landmark B and time/unit, respectively.
    char comma;
    ss >> node >> comma >> neighbour >> comma >> time; // Read the line

    AddEdge(node, neighbour, time); //call the AddEdge function to add the line to the graph
  }
    cout << endl;
    cout << "CSV file " << filename << " read successfully!" << endl;
    ValidateGraphIntegrity(); // call the ValidateGraphIntergrity function to check the integrity of the graph;
    file.close(); // Close the file

}


/////////////////// Display the graph ////////////////////
void DataIntegrity::display() const {
        for (const auto& [node, neighbors] : graph) { // Iterate through all nodes in the graph
            cout << "Landmark " << node << " connects to:" << endl;
            for (const auto& [neighbor, weight] : neighbors) { // Iterate through all neighbors of the node
                cout << "  -> Landmark " << neighbor << " with time " << weight << endl;
            }
        }
    }


////////////////////// Check the integrity of the graph by checking if there is any self-loop //////////////////////
bool DataIntegrity::detectSelfLoop(){
    unordered_set<int>  selfLoop;

	for(auto& [node, neighbour] : graph){ // Iterate through all nodes in the graph
        for(auto& [neighbor, _] : neighbour){ // Iterate through all neighbors of the node
            if(node == neighbor){ // If the node is the same as the neighbor, then there is a self loop
                selfLoop.insert(node); // add all the nodes with self loops to selfLoop set
            }
        }
	}

    /* Display the nodes found within the selfLoop set */
    cout << endl;
    if (!selfLoop.empty()) {
        cout << "Self loop detected at node(s): ";
        for (const int node : selfLoop) {
            cout << node << " ";
        }
        cout << "\n" << endl;
        return false;
    }

    /* If no self loop is found */
    cout << "No self loop detected\n" << endl;
    return true;
};


//////////// Check if there is a cycle loop in the graph by iterating through all neighbors of the node //////////////
bool DataIntegrity::detectCycleLoop(int startNode, unordered_set<int>& visited) {
    stack<pair<int, size_t>> nodeStack;  // Pair of (node, neighbor_index)
    vector<int> currentPath;
    unordered_map<int, bool> inPath;

    // Initialize with start node
    nodeStack.push({startNode, 0});
    currentPath.push_back(startNode);
    inPath[startNode] = true;
    visited.insert(startNode);

    while (!nodeStack.empty()) {
        int currentNode = nodeStack.top().first;
        size_t& index = nodeStack.top().second; //

        // If we've processed all neighbors of current node
        if (index >= graph[currentNode].size()) {
            nodeStack.pop();
            if (!currentPath.empty()) {
                currentPath.pop_back();
                inPath[currentNode] = false;
            }
            continue;
        }

        // Get next neighbor to process
        int neighbor = graph[currentNode][index].first;  // Using .first since your graph stores pairs of (neighbor, weight)
        index++;  // Move to next neighbor for future iterations

        // If neighbor is in current path, we found a cycle
        if (inPath[neighbor]) {
            // Only report cycles of length >= 3
            auto it = find(currentPath.begin(), currentPath.end(), neighbor);
            if (distance(it, currentPath.end()) >= 3) {
                cout << "\nPath Leader: ";
                for (const int n : currentPath) {
                    cout << n << " -> ";
                }
                cout << neighbor << endl;

                cout << "CycleLoop Detected: {";
                for (; it != currentPath.end(); ++it) {
                    cout << *it << " -> ";
                }
                cout << neighbor << "}" << endl;
                return true;
            }
            continue;
        }

        // Skip if already visited (but allow revisiting if it would create a cycle)
        if (visited.count(neighbor) && !inPath[neighbor]) {
            continue;
        }

        // Add neighbor to path and stack
        nodeStack.push({neighbor, 0});
        currentPath.push_back(neighbor);
        inPath[neighbor] = true;
        visited.insert(neighbor);
    }

    return false;
}


/////////////// Check the integrity of the graph by checking if there is any self-loop and cycle loop ///////////////
bool DataIntegrity::ValidateGraphIntegrity() {
    unordered_set<int> visited, stack;
    vector<int> path;

    bool cycleDetected = true;

    /* Check for self-loops */
    if (!detectSelfLoop()) {
        cycleDetected = false; // Invalid graph due to self-loops
    }

    /* Check for cyclesLoops */
    for (auto& [node, _] : graph) { // Iterate through all nodes in the graph
        if (!visited.count(node) && detectCycleLoop(node, visited)) {
            cout << "\nThe graph is not free of loops" << endl;
            return false;
        }
    }

    /* If no self-loops or cyclesLoops are found */
    cout << "\nThe graph is free of loops" << endl;
    return cycleDetected;
}


////////////// Check the connectivity of the graph //////////////
bool DataIntegrity::Connectivity() {
    unordered_set<int> visited; // Create a set to store visited nodes
    DFSConnectivity(graph.begin()->first, visited);
    cout << endl;

    if (visited.size() != graph.size()) {
        cout << "The graph is not fully connected" << endl;
        return false;
    }

    cout << "The graph is fully connected" << endl;
    return true;
}


////////////// Depth First Search to check the connectivity of the graph //////////////
void DataIntegrity::DFSConnectivity(int node, unordered_set<int>& visited) {
    visited.insert(node); // mark the node as visited
    stack<int> nodeStack;
    nodeStack.push(node);

    while (!nodeStack.empty()) {
        int currentNode = nodeStack.top();
        nodeStack.pop();

        for (const auto& [neighbor, _] : graph[currentNode]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                nodeStack.push(neighbor);
            }
        }
    }
}