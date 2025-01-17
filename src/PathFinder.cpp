#include "PathFinder.h"
#include <queue>
#include <unordered_map>
#include <limits>

PathFinder::PathFinder(const Graph& graph) : graph(graph) {}

std::pair<int, std::vector<std::string>> PathFinder::findQuickestPath(const std::string& source, const std::string& destination) {
    std::unordered_map<std::string, int> time;
    std::unordered_map<std::string, std::string> previous;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> pq;

    for (const auto& pair : graph.getAdjList()) {
        time[pair.first] = std::numeric_limits<int>::max();
        previous[pair.first] = "";
    }

    time[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto current = pq.top().second;
        pq.pop();

        for (const auto& neighbor : graph.getAdjList().at(current)) {
            auto newTime = time[current] + neighbor.second;
            if (newTime < time[neighbor.first]) {
                time[neighbor.first] = newTime;
                previous[neighbor.first] = current;
                pq.push({newTime, neighbor.first});
            }
        }
    }

    if (previous[destination].empty()) {
        return { -1, {} };
    }

    std::vector<std::string> path;
    auto current = destination;
    while (!current.empty()) {
        path.push_back(current);
        current = previous[current];
    }

    std::reverse(path.begin(), path.end());
    return { time[destination], path };
}
