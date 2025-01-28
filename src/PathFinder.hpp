#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Graph.hpp"
#include <vector>
#include <string>

class PathFinder {
public:
    PathFinder(const Graph& graph);
    std::pair<int, std::vector<std::string>> findQuickestPath(const std::string& source, const std::string& destination);

private:
    const Graph& graph;
};

#endif // PATHFINDER_H
