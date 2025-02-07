#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP

#include "Graph.hpp"
#include <vector>
#include <string>


class PathFinder {
public:
    explicit PathFinder(const Graph& graph);
    std::pair<int, std::vector<std::string>> findQuickestPath(const std::string& source, const std::string& destination);

private:
    const Graph& graph;
    size_t graphSize;
};
#endif
