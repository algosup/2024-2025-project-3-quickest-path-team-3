#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

class Graph {
public:
    void addEdge(const std::string& landmarkA, const std::string& landmarkB, int time);
    const std::unordered_map<std::string, int>& getNodeIndex() const;
    const std::vector<std::string>& getIndexToNode() const;
    const std::vector<std::vector<std::pair<int, int>>>& getAdjList() const;

private:
    std::unordered_map<std::string, int> nodeIndex; // Maps node names to indices
    std::vector<std::string> indexToNode;           // Maps indices back to node names
    std::vector<std::vector<std::pair<int, int>>> adjList; // Adjacency list
};

#endif // GRAPH_H
