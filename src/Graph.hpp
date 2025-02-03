#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <numeric>
#include <algorithm>


class Graph {
public:
    void reserveNodes(size_t numNodes);
    void addEdge(const std::string& landmarkA, const std::string& landmarkB, int time);
	void contractNodes(); 
    void addShortcut(int u, int v, int weight);
    const std::unordered_map<std::string, int>& getNodeIndex() const;
    const std::vector<std::string>& getIndexToNode() const;
    const std::vector<std::vector<std::pair<int, int>>>& getAdjList() const;
    const std::vector<std::vector<std::pair<int, int>>>& getContractedAdjList() const;
   

private:
    std::unordered_map<std::string, int> nodeIndex;
    std::vector<std::string> indexToNode;
    std::vector<std::vector<std::pair<int, int>>> adjList;
    std::vector<std::vector<std::pair<int, int>>> contractedAdjList;
};

#endif
