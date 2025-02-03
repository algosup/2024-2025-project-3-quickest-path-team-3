#include "PathFinder.hpp"
#include <queue>
#include <limits>
#include <vector>

PathFinder::PathFinder(const Graph& graph) : graph(graph) {}

std::pair<int, std::vector<std::string>> PathFinder::findQuickestPath(const std::string& source, const std::string& destination) {
    const auto& adjList = graph.getAdjList();
    const auto& nodeIndex = graph.getNodeIndex();
    const auto& indexToNode = graph.getIndexToNode();

    if (nodeIndex.count(source) == 0 || nodeIndex.count(destination) == 0) {
        return { -1, {} };  // Invalid nodes
    }

    int n = adjList.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<int> prev(n, -1);

    using PQ = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>>;
    PQ pq;

    int src = nodeIndex.at(source);
    int dest = nodeIndex.at(destination);
    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [currentDist, currentNode] = pq.top();
        pq.pop();

        if (currentNode == dest) break;
        if (currentDist > dist[currentNode]) continue;

        for (const auto& [neighbor, weight] : adjList[currentNode]) {
            int newDist = currentDist + weight;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                prev[neighbor] = currentNode;
                pq.emplace(newDist, neighbor);
            }
        }
    }

    if (dist[dest] == std::numeric_limits<int>::max()) return { -1, {} };

    std::vector<std::string> path;
    for (int at = dest; at != -1; at = prev[at]) {
        path.push_back(indexToNode[at]);
    }
    std::reverse(path.begin(), path.end());

    return { dist[dest], path };
}
