#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>
#include <thread>
#include <mutex>
#include "PathFinder.hpp"

struct MinHeap {
    std::vector<std::pair<int, int>> heap;  // (distance, node)

    void push(int node, int dist) {
        heap.emplace_back(dist, node);
        std::push_heap(heap.begin(), heap.end(), std::greater<>{});
    }

    std::pair<int, int> pop() {
        std::pop_heap(heap.begin(), heap.end(), std::greater<>{});
        auto min = heap.back();
        heap.pop_back();
        return min;
    }

    bool empty() const {
        return heap.empty();
    }
};

std::mutex mtx; // Mutex for thread-safe operations

PathFinder::PathFinder(const Graph& graph) : graph(graph) {
    graphSize = graph.getAdjList().size();
}

std::pair<int, std::vector<std::string>> PathFinder::findQuickestPath(
    const std::string& source, const std::string& destination) {

    const auto& adjList = graph.getAdjList();
    const auto& nodeIndex = graph.getNodeIndex();
    const auto& indexToNode = graph.getIndexToNode();

    if (nodeIndex.count(source) == 0 || nodeIndex.count(destination) == 0) {
        return {-1, {}};
    }

    int src = nodeIndex.at(source);
    int dest = nodeIndex.at(destination);

    std::vector<int> distF(graphSize, std::numeric_limits<int>::max());
    std::vector<int> distB(graphSize, std::numeric_limits<int>::max());
    std::vector<int> prevF(graphSize, -1);
    std::vector<int> prevB(graphSize, -1);

    std::vector<bool> visitedF(graphSize, false);
    std::vector<bool> visitedB(graphSize, false);

    MinHeap pqF, pqB;
    distF[src] = 0;
    distB[dest] = 0;
    pqF.push(src, 0);
    pqB.push(dest, 0);

    int bestDist = std::numeric_limits<int>::max();
    int meetingNode = -1;

    auto search = [&](MinHeap& pq, std::vector<int>& dist, std::vector<int>& prev,
                       std::vector<bool>& visited, std::vector<int>& otherDist, bool& stopFlag) {
        while (!pq.empty() && !stopFlag) {
            auto [distCurr, current] = pq.pop();

            if (visited[current]) continue;
            visited[current] = true;

            mtx.lock();
            if (visitedF[current] && visitedB[current]) {
                int totalDist = distF[current] + distB[current];
                if (totalDist < bestDist) {
                    bestDist = totalDist;
                    meetingNode = current;
                    stopFlag = true;
                }
            }
            mtx.unlock();

            for (const auto& [neighbor, weight] : adjList[current]) {
                int newDist = dist[current] + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    prev[neighbor] = current;
                    pq.push(neighbor, newDist);
                }
            }
        }
    };

    bool stopFlag = false;
    std::thread forwardThread(search, std::ref(pqF), std::ref(distF), std::ref(prevF),
                              std::ref(visitedF), std::ref(distB), std::ref(stopFlag));
    std::thread backwardThread(search, std::ref(pqB), std::ref(distB), std::ref(prevB),
                               std::ref(visitedB), std::ref(distF), std::ref(stopFlag));

    forwardThread.join();
    backwardThread.join();

    if (meetingNode == -1) {
        return {-1, {}};
    }

    // Reconstruct the path
    std::vector<std::string> path;
    for (int at = meetingNode; at != -1; at = prevF[at]) {
        path.push_back(indexToNode[at]);
    }
    std::reverse(path.begin(), path.end());
    for (int at = prevB[meetingNode]; at != -1; at = prevB[at]) {
        path.push_back(indexToNode[at]);
    }

    return {bestDist, path};
}
