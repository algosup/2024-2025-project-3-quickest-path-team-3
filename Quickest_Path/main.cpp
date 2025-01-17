#include <iostream>
#include <sstream>
#include "Data_Verification/DataIntergrity.h"
#include <fstream>
#include <filesystem>

int main() {

    DataIntergrity data;

    data.LoadGraphFromCSV("../roads.csv");

    //data.display();

    return 0;
}
