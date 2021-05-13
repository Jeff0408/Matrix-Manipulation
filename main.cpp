
#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <cstring>


int main(int argc, const char* argv[]) {
    Manipulation m;
    // check argument count and usage
    if (argc != 2) {
        std::cout << "There should be two command line arguments." << std::endl;
        return 0;
    }
    // check if user choose multiply or transpose or not
    if (strcmp(argv[1], "multiply") == 0) {
        m.matrixMultiply();
    } else if (strcmp(argv[1], "transpose") == 0) {
        m.matrixTranspose();
    } else {
        std::cout << "Try 'multiply' or 'transpose'." << std::endl;
    }

    return 0;
}