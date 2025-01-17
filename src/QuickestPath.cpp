#include "Graph.h"
#include "RestApi.h"
#include"PathFinder.h"
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

        if (!std::getline(iss, landmarkA, ',') ||
            !std::getline(iss, landmarkB, ',') ||
            !std::getline(iss, timeStr, ',')) {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }

        try {
            time = std::stoi(timeStr);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid time value: " << timeStr << " in line: " << line << std::endl;
            continue;
        }

        graph.addEdge(landmarkA, landmarkB, time);
        
    }

    RestApi api(graph);
    api.run();

    std::cout << "Breakpoint" << std::endl;

    

    return 0;
}
