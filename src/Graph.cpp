#include "Graph.hpp"



void Graph::reserveNodes(size_t numNodes) {
    nodeIndex.reserve(numNodes);
    indexToNode.reserve(numNodes);
    adjList.reserve(numNodes);
}

void Graph::addEdge(const std::string& landmarkA, const std::string& landmarkB, int time) {
    if (!nodeIndex.count(landmarkA)) {
        nodeIndex[landmarkA] = indexToNode.size();
        indexToNode.push_back(landmarkA);
        adjList.emplace_back();
    }
    if (!nodeIndex.count(landmarkB)) {
        nodeIndex[landmarkB] = indexToNode.size();
        indexToNode.push_back(landmarkB);
        adjList.emplace_back();
    }
    
    int u = nodeIndex[landmarkA];
    int v = nodeIndex[landmarkB];
    
    adjList[u].emplace_back(v, time);
    adjList[v].emplace_back(u, time);
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

void Graph::contractNodes(){
    // Example node ordering based on node degree
    std::vector<int> order(indexToNode.size());
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [this](int a, int b) {
        return adjList[a].size() < adjList[b].size();
        });

    contractedAdjList = adjList;

    for (int node : order) {
        // Contract the node
        for (const auto& [neighbor1, weight1] : adjList[node]) {
            for (const auto& [neighbor2, weight2] : adjList[node]) {
                if (neighbor1 != neighbor2) {
                    int shortcutWeight = weight1 + weight2;
                    addShortcut(neighbor1, neighbor2, shortcutWeight);
                }
            }
        }
        // Remove the node from the graph
        contractedAdjList[node].clear();
    }
}

void Graph::addShortcut(int u, int v, int weight) {
    contractedAdjList[u].emplace_back(v, weight);
    contractedAdjList[v].emplace_back(u, weight);
}

const std::vector<std::vector<std::pair<int, int>>>& Graph::getContractedAdjList() const {
    return contractedAdjList;
}
