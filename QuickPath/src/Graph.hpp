#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Graph {
public:
    Graph();

    int ensureNode(const std::string& landmark);

    void addEdge(const std::string& landmarkA, const std::string& landmarkB, int time);

    void precomputeLandmarks(const std::vector<std::string> &landmarks);

    const std::vector<std::vector<std::pair<int, int>>>& getAdjList() const { return adjList; }
    const std::unordered_map<std::string, int>& getNodeIndex() const { return nodeIndex; }
    const std::vector<std::string>& getIndexToNode() const { return indexToNode; }

private:
    std::unordered_map<std::string, int> nodeIndex;
    std::vector<std::string> indexToNode;
    std::vector<std::vector<std::pair<int, int>>> adjList;
    std::vector<std::vector<std::pair<int, int>>> forwardEdges, backwardEdges;
    std::unordered_map<int, std::vector<int>> landmarkDistances;
};

#endif // GRAPH_HPP