#include "Graph.hpp"
#include "RestApi.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main() {
    Graph graph;
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

    RestApi api(graph);
    api.run();
    return 0;
}
