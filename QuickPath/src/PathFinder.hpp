#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP

#include "Graph.hpp"
#include <vector>
#include <string>


class PathFinder {
public:
    explicit PathFinder(const Graph& graph);

    double calculateHeuristic(int nodeIdx1, int nodeIdx2) const;

    inline int heuristic(const std::pair<int, int>& a, const std::pair<int, int>& b);
    std::pair<int, std::vector<std::string>> findQuickestPath(const std::string& source, const std::string& destination);
private:
    const Graph& graph;
    size_t graphSize;

    int heuristic(int currentNode, int targetNode) const;

};
#endif
