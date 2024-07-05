#include "utils.h"
#include <fstream>
#include <sstream>

std::vector<std::string> readFile(std::string filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}