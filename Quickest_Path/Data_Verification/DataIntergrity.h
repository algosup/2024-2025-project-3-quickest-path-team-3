//
// Created by Vivien Bistrel TSANGUE CHOUNGOU on 15/01/2025.
//

#ifndef DATAINTERGRITY_H
#define DATAINTERGRITY_H

#include <unordered_set>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;



class DataIntergrity {
public:
    bool ValidateGraphIntergrity();
    bool detectCycleLoop(int node, unordered_set<int> visited, unordered_set<int> stack);
    bool detectSelfLoop();
    void LoadGraphFromCSV(const string& filename);
    void AddEdge(int u, int v, int w);
    void display() const;
};



#endif //DATAINTERGRITY_H
