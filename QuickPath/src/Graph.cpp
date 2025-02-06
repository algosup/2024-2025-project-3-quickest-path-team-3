// Graph.cpp
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

int Graph::ensureNode(const std::string& landmark) {
    if (!nodeIndex.count(landmark)) {
        int newIndex = nodeIndex.size();
        nodeIndex[landmark] = newIndex;
        indexToNode.push_back(landmark);
        adjList.push_back(std::vector<std::pair<int, int>>());
        return newIndex;
    }
    return nodeIndex[landmark];
}

void Graph::setCoordinates(const std::string& landmark, int x, int y) {
    int idx = ensureNode(landmark);
    nodeCoordinates[idx] = {x, y};
}

void Graph::debugNode(const std::string& landmark) const {
    std::cout << "Node " << landmark << ": ";
    if (nodeIndex.count(landmark)) {
        int idx = nodeIndex.at(landmark);
        std::cout << "index=" << idx
                 << ", connections=" << adjList[idx].size()
                 << ", has_coords=" << (nodeCoordinates.count(idx) > 0)
                 << std::endl;
    } else {
        std::cout << "not found in index" << std::endl;
    }
}

void Graph::addEdge(const std::string& landmarkA, const std::string& landmarkB, int time) {
    if (time < 0) {
        throw std::invalid_argument("Travel time cannot be negative");
    }

    // Get or create indices for both nodes
    int u = ensureNode(landmarkA);
    int v = ensureNode(landmarkB);

    // Ensure we have space in our adjacency list
    while (adjList.size() <= std::max(u, v)) {
        adjList.push_back(std::vector<std::pair<int, int>>());
    }

    // Add the edges in both directions
    adjList[u].emplace_back(v, time);
    adjList[v].emplace_back(u, time);

    // Verify the connection was added successfully
    if (adjList[u].empty() || adjList[v].empty()) {
        std::cerr << "WARNING: Edge addition may have failed!" << std::endl;
        debugNode(landmarkA);
        debugNode(landmarkB);
    }
}

// Add a method to verify a specific connection
bool Graph::verifyConnection(const std::string& landmarkA, const std::string& landmarkB) const {
    if (!nodeIndex.count(landmarkA) || !nodeIndex.count(landmarkB)) {
        return false;
    }

    int u = nodeIndex.at(landmarkA);
    int v = nodeIndex.at(landmarkB);

    // Check if v exists in u's adjacency list
    bool forward = false;
    for (const auto& [neighbor, _] : adjList[u]) {
        if (neighbor == v) {
            forward = true;
            break;
        }
    }

    // Check if u exists in v's adjacency list
    bool backward = false;
    for (const auto& [neighbor, _] : adjList[v]) {
        if (neighbor == u) {
            backward = true;
            break;
        }
    }

    return forward && backward;
}

// Add a method to print node statistics
void Graph::printNodeStats(const std::string& landmark) const {
    if (!nodeIndex.count(landmark)) {
        std::cout << "Node " << landmark << " not found in graph" << std::endl;
        return;
    }

    int idx = nodeIndex.at(landmark);
    std::cout << "Node " << landmark << " statistics:\n"
             << "  Index: " << idx << "\n"
             << "  Number of connections: " << adjList[idx].size() << "\n"
             << "  Has coordinates: " << (nodeCoordinates.count(idx) > 0) << "\n";

    if (!adjList[idx].empty()) {
        std::cout << "  Connected to nodes: ";
        for (const auto& [neighbor, time] : adjList[idx]) {
            std::cout << indexToNode[neighbor] << "(" << time << "ms) ";
        }
        std::cout << std::endl;
    }
}