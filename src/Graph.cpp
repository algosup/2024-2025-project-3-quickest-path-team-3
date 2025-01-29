#include "Graph.hpp"

void Graph::addEdge(const std::string& landmarkA, const std::string& landmarkB, int time) {
    if (nodeIndex.find(landmarkA) == nodeIndex.end()) {
        nodeIndex[landmarkA] = indexToNode.size();
        indexToNode.push_back(landmarkA);
        adjList.emplace_back();
    }
    if (nodeIndex.find(landmarkB) == nodeIndex.end()) {
        nodeIndex[landmarkB] = indexToNode.size();
        indexToNode.push_back(landmarkB);
        adjList.emplace_back();
    }
    int u = nodeIndex[landmarkA];
    int v = nodeIndex[landmarkB];
    adjList[u].emplace_back(v, time);
    adjList[v].emplace_back(u, time); // Assuming undirected graph
}

const std::unordered_map<std::string, int>& Graph::getNodeIndex() const {
    return nodeIndex;
}

const std::vector<std::string>& Graph::getIndexToNode() const {
    return indexToNode;
}

const std::vector<std::vector<std::pair<int, int>>>& Graph::getAdjList() const {
    return adjList;
}
