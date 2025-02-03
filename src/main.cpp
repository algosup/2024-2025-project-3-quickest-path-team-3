#include "Graph.hpp"
#include "RestApi.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <boost/functional/hash.hpp>

void saveGraph(const Graph& graph, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    const auto& adjList = graph.getAdjList();
    for (size_t u = 0; u < adjList.size(); ++u) {
        for (const auto& [v, weight] : adjList[u]) {
            outFile << u << "," << v << "," << weight << "\n";
        }
    }

    outFile.close();
}

void loadGraph(Graph& graph, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::in | std::ios::binary);
    if (!inFile) {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        int u, v, weight;

        ss >> u;
        ss.ignore(1, ','); // Ignore the comma
        ss >> v;
        ss.ignore(1, ','); // Ignore the comma
        ss >> weight;

        graph.addShortcut(u, v, weight);
    }

    inFile.close();
}

int main() {
    Graph graph;
    const std::string preprocessedFile = "data/preprocessed-graph.txt";

    std::ifstream preprocessedFileCheck(preprocessedFile, std::ios::in | std::ios::binary);
    if (preprocessedFileCheck) {
        // Preprocessed file exists, load the graph from the file
        loadGraph(graph, preprocessedFile);
    } else {
        // Preprocessed file does not exist, read the original graph data and preprocess it
        std::ifstream file("data/USA-roads.csv", std::ios::in | std::ios::binary);

        if (!file) {
            std::cerr << "Failed to open file.\n";
            return 1;
        }

        graph.reserveNodes(24000000);

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string landmarkA, landmarkB;
            int time;

            std::getline(ss, landmarkA, ',');
            std::getline(ss, landmarkB, ',');
            ss >> time;

            graph.addEdge(landmarkA, landmarkB, time);
        }

        file.close();

        graph.contractNodes();

        // Add shortcuts directly to the graph
        const auto& adjList = graph.getAdjList();
        std::unordered_set<std::pair<int, int>, boost::hash<std::pair<int, int>>> existingEdges;

        for (size_t u = 0; u < adjList.size(); ++u) {
            for (const auto& [v, weightUV] : adjList[u]) {
                existingEdges.emplace(u, v);
            }
        }

        for (size_t u = 0; u < adjList.size(); ++u) {
            for (const auto& [v, weightUV] : adjList[u]) {
                for (const auto& [w, weightVW] : adjList[v]) {
                    if (u != w && existingEdges.find({u, w}) == existingEdges.end()) {
                        int shortcutWeight = weightUV + weightVW;
                        graph.addShortcut(u, w, shortcutWeight);
                        existingEdges.emplace(u, w);
                    }
                }
            }
        }

        // Save the preprocessed graph to a file
        saveGraph(graph, preprocessedFile);
    }

    RestApi api(graph);
    api.run();
    return 0;
}
