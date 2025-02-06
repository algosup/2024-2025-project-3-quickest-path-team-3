// Graph.hpp
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Graph {
public:
    int ensureNode(const std::string& landmark);
    void setCoordinates(const std::string& landmark, int x, int y);

    void debugNode(const std::string &landmark) const;

    void addEdge(const std::string& landmarkA, const std::string& landmarkB, int time);

    bool verifyConnection(const std::string &landmarkA, const std::string &landmarkB) const;

    void printNodeStats(const std::string &landmark) const;

    const std::vector<std::vector<std::pair<int, int>>>& getAdjList() const { return adjList; }
    const std::unordered_map<std::string, int>& getNodeIndex() const { return nodeIndex; }
    const std::vector<std::string>& getIndexToNode() const { return indexToNode; }
    const std::unordered_map<int, std::pair<int, int>>& getNodeCoordinates() const { return nodeCoordinates; }

private:
    std::unordered_map<std::string, int> nodeIndex;
    std::vector<std::string> indexToNode;
    std::vector<std::vector<std::pair<int, int>>> adjList;
    std::unordered_map<int, std::pair<int, int>> nodeCoordinates;
};

#endif // GRAPH_HPP