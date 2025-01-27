#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

class Graph {
public:
    void addEdge(const std::string& landmarkA, const std::string& landmarkB, int time);
    std::pair<int, std::vector<std::string>> quickestPath(const std::string& start, const std::string& end) const;
    const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& getAdjList() const;

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjList;
};

#endif // GRAPH_H
