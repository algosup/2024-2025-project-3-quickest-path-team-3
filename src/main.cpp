#include "Graph.hpp"
#include "RestApi.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <boost/functional/hash.hpp>

//void saveGraph(const Graph& graph, const std::string& filename) {
//    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
//    if (!outFile) {
//        std::cerr << "Failed to open file for writing.\n";
//        return;
//    }
//
//    const auto& adjList = graph.getAdjList();
//    for (size_t u = 0; u < adjList.size(); ++u) {
//        for (const auto& [v, weight] : adjList[u]) {
//            outFile << u << "," << v << "," << weight << "\n";
//        }
//    }
//
//    outFile.close();
//}
//
//void loadGraph(Graph& graph, const std::string& filename) {
//    std::ifstream inFile(filename, std::ios::in | std::ios::binary);
//    if (!inFile) {
//        std::cerr << "Failed to open file for reading.\n";
//        return;
//    }
//    graph.reserveNodes(24000000);
//    // Load node index mapping
//    size_t nodeIndexSize;
//    inFile >> nodeIndexSize;
//    inFile.ignore(); // Ignore the newline character
//
//    for (size_t i = 0; i < nodeIndexSize; ++i) {
//        std::string line;
//        std::getline(inFile, line);
//        std::stringstream ss(line);
//        std::string node;
//        int index;
//        std::getline(ss, node, ',');
//        ss >> index;
//        graph.nodeIndex[node] = index;
//        graph.indexToNode.push_back(node);
//    }
//
//    // Load adjacency list
//    size_t adjListSize;
//    inFile >> adjListSize;
//    inFile.ignore(); // Ignore the newline character
//
//    graph.adjList.resize(adjListSize);
//    for (size_t u = 0; u < adjListSize; ++u) {
//        std::string line;
//        while (std::getline(inFile, line)) {
//            std::stringstream ss(line);
//            int v, weight;
//            char comma;
//            ss >> u >> comma >> v >> comma >> weight;
//            graph.adjList[u].emplace_back(v, weight);
//        }
//    }
//
//    inFile.close();
//}

int main() {
    Graph graph;
    const std::string preprocessedFile = "data/preprocessed-graph.csv";

    std::ifstream preprocessedFileCheck(preprocessedFile, std::ios::in | std::ios::binary);
    if (preprocessedFileCheck) {
        // Preprocessed file exists, load the graph from the file
        //loadGraph(graph, preprocessedFile);
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

        // Preprocess the graph
        graph.contractNodes();

        // Save the preprocessed graph to a file
       // saveGraph(graph, preprocessedFile);
    }

    RestApi api(graph);
    api.run();
    return 0;
}
