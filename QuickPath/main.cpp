#include <iostream>
#include <sstream>
#include "DataIntegrityVerification/DataIntegrity.h"
#include "src/Graph.hpp"
#include "src/RestApi.hpp"
#include <fstream>


int main() {

    /////////// Check the integrity of the graph by checking if there is any self-loop and cycle loop //////////
     DataIntegrity data;

     cout <<endl;
     cout << "======================= LOOPS DETECTION ===========================" << endl;
     data.LoadGraphFromCSV("../USA-roads.csv");

    data.Connectivity();

    /////////////// Quickest Path /////////////////
    Graph graph;

    // First, let's add a counter for coordinates
    size_t coordCount = 0;
    std::ifstream file("../USA-roads.csv", std::ios::in | std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

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

