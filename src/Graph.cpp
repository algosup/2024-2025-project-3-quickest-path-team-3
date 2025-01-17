#include "Graph.h"
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>

void Graph::addEdge(const std::string& landmarkA, const std::string& landmarkB, int time) {
    adjList[landmarkA].emplace_back(landmarkB, time);
    adjList[landmarkB].emplace_back(landmarkA, time); // Assuming undirected graph
}

std::pair<int, std::vector<std::string>> Graph::quickestPath(const std::string& start, const std::string& end) const {
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> predecessors;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;

    for (const auto& pair : adjList) {
        distances[pair.first] = std::numeric_limits<int>::max();
    }
    distances[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        if (currentNode == end) break;

        for (const auto& [neighbor, weight] : adjList.at(currentNode)) {
            int newDistance = currentDistance + weight;
            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                predecessors[neighbor] = currentNode;
                pq.emplace(newDistance, neighbor);
            }
        }
    }

    std::vector<std::string> path;
    if (distances[end] == std::numeric_limits<int>::max()) {
        return { -1, path }; // No path found
    }

    for (std::string at = end; at != start; at = predecessors[at]) {
        path.push_back(at);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return { distances[end], path };
}

const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& Graph::getAdjList() const {
    return adjList;
}
