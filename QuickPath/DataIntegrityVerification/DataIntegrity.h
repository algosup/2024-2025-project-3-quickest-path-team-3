#ifndef DATAINTEGRITY_H
#define DATAINTEGRITY_H

#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;



class DataIntegrity {
public:
    bool ValidateGraphIntegrity();
    bool detectCycleLoop(int startNode, unordered_set<int>& visited);
    bool detectSelfLoop();
    void LoadGraphFromCSV(const std::string& filename);
    void AddEdge(int u, int v, int w);
    void display() const;
    bool Connectivity();
    void DFSConnectivity(int node, unordered_set<int>& visited);
};



#endif //DATAINTEGRITY_H
