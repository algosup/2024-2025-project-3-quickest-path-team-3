#include <iostream>
#include <sstream>
#include "Data_Verification/DataIntegrity.h"
#include <fstream>
#include <filesystem>

int main() {

    DataIntegrity data;

    cout <<endl;
    cout << "======================= LOOPS DETECTION ===========================" << endl;
    data.LoadGraphFromCSV("../roads.csv");

    cout << endl;
    cout << "======================= CONNECTIVITY CHECK ========================" << endl;
    data.Connectivity();

    return 0;
}
