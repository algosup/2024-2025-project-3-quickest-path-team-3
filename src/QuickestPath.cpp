#include "Graph.hpp"
#include "RestApi.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

int main() {
    Graph graph;
    std::ifstream file("data/USA-roads.csv");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string landmarkA, landmarkB, timeStr;
        int time;

        if (!(std::getline(iss, landmarkA, ',') && std::getline(iss, landmarkB, ',') && std::getline(iss, timeStr, ','))) {
            continue;
        }

        try {
            time = std::stoi(timeStr);
        } catch (...) {
            continue;
        }

        graph.addEdge(landmarkA, landmarkB, time);
    }

    RestApi api(graph);
    api.run();

    return 0;
}
