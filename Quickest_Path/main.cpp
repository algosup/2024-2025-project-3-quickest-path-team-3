#include <iostream>
#include <sstream>
#include "Data_Verification/DataIntergrity.h"
#include <fstream>
#include <filesystem>

int main() {

    DataIntergrity data;



    data.LoadGraphFromCSV("../roads.csv");

    data.display();

    if (data.ValidateGraphIntergrity()) {
        cout << "\n\nGraph integrity validated successfully." << endl;
    } else {
        cout << "Graph integrity validation failed." << endl;
    }





    return 0;
}
