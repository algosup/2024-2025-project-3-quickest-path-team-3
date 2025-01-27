#include <iostream>
#include <sstream>
#include "DataIntegrityVerification/DataIntegrity.h"
#include "src/Graph.h"
#include "src/RestApi.h"
#include <fstream>


int main() {

    ///////////// Check the integrity of the graph by checking if there is any self-loop and cycle loop //////////
    DataIntegrity data;

    cout <<endl;
    cout << "======================= LOOPS DETECTION ===========================" << endl;
    data.LoadGraphFromCSV("../DataIntegrityVerification/roads.csv");

    cout << endl;
    cout << "======================= CONNECTIVITY CHECK ========================" << endl;
    data.Connectivity();


    ///////////// Quickest Path //////////////
    Graph graph;
    std::ifstream file("../src/data/USA-roads.csv");
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

    return 0;
}
