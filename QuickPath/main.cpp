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
    data.LoadGraphFromCSV("../src/data/USA-roads.csv");

    // cout << endl;
    // cout << "======================= CONNECTIVITY CHECK ========================" << endl;
    // data.Connectivity();


    /////////////// Quickest Path /////////////////
    // Graph graph;
    // ifstream file("../USA-roads.csv");
    // string line;
    //
    // if (!file.is_open()) {
    //     cout << "Failed to open the file." << endl;
    //     return 1;
    // }
    //
    // while (getline(file, line)) {
    //     istringstream iss(line);
    //     string landmarkA, landmarkB, timeStr;
    //     int time;
    //
    //     if (!getline(iss, landmarkA, ',') ||
    //         !getline(iss, landmarkB, ',') ||
    //         !getline(iss, timeStr, ',')) {
    //         cout << "Error parsing line: " << line << endl;
    //         continue;
    //         }
    //
    //     try {
    //         time = stoi(timeStr);
    //     } catch (const invalid_argument& e) {
    //         cout << "Invalid time value: " << timeStr << " in line: " << line << endl;
    //         continue;
    //     }
    //
    //     graph.addEdge(landmarkA, landmarkB, time);
    // }
    //
    // RestApi api(graph);
    // api.run();

    return 0;
}
