#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <queue>
#include <limits>

//Constructor to initialize the graph object
Graph::Graph() {
    forwardEdges.clear(); // Clear the forward edges list
    backwardEdges.clear(); //Clear the backward edges list
    landmarkDistances.clear(); //Clear the landmark distances list
}


//Function to ensure that a node exists in the graph
int Graph::ensureNode(const std::string& landmark) {
    if (!nodeIndex.count(landmark)) { //If the landmark is not in the node index
        int newIndex = nodeIndex.size(); //Get the new index for the landmark
        nodeIndex[landmark] = newIndex; // Map the landmark to the node index
        indexToNode.push_back(landmark); // Add the landmark to the index to node list
        adjList.emplace_back(); // Add an adjacency list for the new node
        forwardEdges.emplace_back(); // Add a forward edge for the new node
        backwardEdges.emplace_back(); // Add a backward edge for the new node
        return newIndex;
    }
    return nodeIndex[landmark]; //Return the index of the landmark if the landmark already exists
}


//Function to add an edge between two landmarks with a given travel time
void Graph::addEdge(const std::string& landmarkA, const std::string& landmarkB, int time) {
    if (time < 0) {
        throw std::invalid_argument("Travel time cannot be negative");
    }
    int u = ensureNode(landmarkA); //Ensure that the first landmark exists in the graph and get its index
    int v = ensureNode(landmarkB); //Ensure that the second landmark exists in the graph and get its index
    adjList[u].emplace_back(v, time); //Add an edge between the two landmarks with the given travel time
    adjList[v].emplace_back(u, time);
    forwardEdges[u].push_back({v, time}); //Add a forward edge between the two landmarks with the given travel time
    backwardEdges[v].push_back({u, time}); //Add a backward edge between the two landmarks with the given travel time


    //Ensure that the forward and backward edges lists are large enough to accommodate the new edge
    while (forwardEdges.size() <= std::max(u, v)) {
        forwardEdges.emplace_back(); //Add a new forward edge list
        backwardEdges.emplace_back(); //Add a new backward edge list
    }
}

//Function to precompute landmark distances for a given list of landmarks
void Graph::precomputeLandmarks(const std::vector<std::string>& landmarks) {
    int INF = std::numeric_limits<int>::max(); //Set the maximum value for infinity
    for (const std::string& landmark : landmarks) { //For each landmark in the list of landmarks
        if (!nodeIndex.count(landmark)) continue;
        int start = nodeIndex[landmark]; //Get the index of the landmark
        std::vector<int> dist(nodeIndex.size(), INF); //Create a vector to store the distances from the landmark
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq; //Create a priority queue to store the nodes to visit
        dist[start] = 0; //Set the distance from the landmark to itself to 0
        pq.emplace(0, start); //Push the start node to the priority queue
        while (!pq.empty()) { //While the priority queue is not empty
            auto [d, u] = pq.top(); pq.pop(); //Get the top node from the priority queue
            if (d > dist[u]) continue;
            for (auto [v, weight] : adjList[u]) { //For each neighbor of the current node
                if (dist[u] + weight < dist[v]) { //If the distance to the neighbor through the current node is less than the current distance
                    dist[v] = dist[u] + weight; //Update the distance to the neighbor
                    pq.emplace(dist[v], v); //Push the neighbor to the priority queue
                }
            }
        }
        landmarkDistances[start] = dist; //Store the distances from the landmark to all other nodes
    }
}


