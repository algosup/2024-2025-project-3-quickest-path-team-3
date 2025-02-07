#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>
#include <thread>
#include <mutex>
#include "PathFinder.hpp"

using MinHeap = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>>;

std::mutex mtx; // Mutex for thread synchronization

PathFinder::PathFinder(const Graph& graph) : graph(graph) {
    graphSize = graph.getAdjList().size(); // Get the size of the graph
}

// Function to find the quickest path between two landmarks
std::pair<int, std::vector<std::string>> PathFinder::findQuickestPath(
    const std::string& source, const std::string& destination) {

    const auto& adjList = graph.getAdjList(); // Get the adjacency list of the graph
    const auto& nodeIndex = graph.getNodeIndex(); // Get the node index of the graph
    const auto& indexToNode = graph.getIndexToNode(); // Get the index to node mapping of the graph

    if (nodeIndex.count(source) == 0 || nodeIndex.count(destination) == 0) {
        return {-1, {}}; // Return -1 if the source or destination landmark is not in the graph
    }

    int src = nodeIndex.at(source); // Get the index of the source landmark
    int dest = nodeIndex.at(destination); // Get the index of the destination landmark

    std::vector<int> distF(graphSize, std::numeric_limits<int>::max()); // Initialize the forward distances vector
    std::vector<int> distB(graphSize, std::numeric_limits<int>::max()); // Initialize the backward distances vector
    std::vector<int> prevF(graphSize, -1); // Initialize the forward previous node vector
    std::vector<int> prevB(graphSize, -1); // Initialize the backward previous node vector
    std::vector<bool> visitedF(graphSize, false); // Initialize the forward visited vector
    std::vector<bool> visitedB(graphSize, false); // Initialize the backward visited vector

    MinHeap pqF, pqB; // Initialize the forward and backward priority queues
    distF[src] = 0; // Set the distance of the source node to 0
    distB[dest] = 0; // Set the distance of the destination node to 0
    pqF.emplace(0, src); // Push the source node to the forward priority queue
    pqB.emplace(0, dest); // Push the destination node to the backward priority queue

    int bestDist = std::numeric_limits<int>::max(); // Initialize the best distance to infinity
    int meetingNode = -1; // Initialize the meeting node to -1

    auto search = [&](MinHeap& pq, std::vector<int>& dist, std::vector<int>& prev,
                      std::vector<bool>& visited, std::vector<int>& otherDist, bool& stopFlag) {
        while (!pq.empty() && !stopFlag) {  // While the priority queue is not empty and the stop flag is false
            auto [distCurr, current] = pq.top();  // Get the top node from the priority queue
            pq.pop(); // Pop the top node from the priority queue

            if (visited[current]) continue;
            visited[current] = true; // Mark the current node as visited

            {
                std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
                if (visitedF[current] && visitedB[current]) { // If the current node has been visited by both searches
                    int totalDist = distF[current] + distB[current]; // Calculate the total distance
                    if (totalDist < bestDist) { // If the total distance is less than the best distance
                        bestDist = totalDist; // Update the best distance
                        meetingNode = current; // Update the meeting node
                        stopFlag = true; // Set the stop flag to true
                    }
                }
            }

            for (const auto& [neighbor, weight] : adjList[current]) { // For each neighbor of the current node
                int newDist = dist[current] + weight; // Calculate the new distance
                if (newDist < dist[neighbor]) { // If the new distance is less than the current distance
                    dist[neighbor] = newDist; // Update the distance
                    prev[neighbor] = current; // Update the previous node
                    pq.emplace(newDist, neighbor); // Push the neighbor and its distance to the priority queue
                }
            }
        }
    };

    bool stopFlag = false; // Initialize the stop flag to false
    std::thread forwardThread(search, std::ref(pqF), std::ref(distF), std::ref(prevF),
                              std::ref(visitedF), std::ref(distB), std::ref(stopFlag)); // Start the forward search thread
    std::thread backwardThread(search, std::ref(pqB), std::ref(distB), std::ref(prevB),
                               std::ref(visitedB), std::ref(distF), std::ref(stopFlag)); // Start the backward search thread

    forwardThread.join(); // Join the forward search thread
    backwardThread.join(); // Join the backward search thread

    if (meetingNode == -1) {
        return {-1, {}}; // Return -1 if the meeting node is not found
    }

    std::vector<std::string> path; // Initialize the path vector
    for (int at = meetingNode; at != -1; at = prevF[at]) { // For each node from the meeting node to the source node
        path.push_back(indexToNode[at]);  // Add the node to the path
    }
    std::reverse(path.begin(), path.end()); // Reverse the path
    for (int at = prevB[meetingNode]; at != -1; at = prevB[at]) { // For each node from the meeting node to the destination node
        path.push_back(indexToNode[at]); // Add the node to the path
    }

    return {bestDist, path}; // Return the best distance and the path
}
