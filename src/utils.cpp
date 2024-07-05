#include "utils.h"
#include <fstream>
#include <sstream>

std::vector<std::string> readFile(std::string filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        // Remove potential carriage return characters
        if (!line.empty() && line[line.size() - 1] == '\r') {
            line.erase(line.size() - 1);
        }
        lines.push_back(line);
    }

    return lines;
}