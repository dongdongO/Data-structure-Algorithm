// loadmapdata.cpp
#include <include/loadmapdata.h>
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<std::vector<int>> load_map_data(const std::string& file_path) {
    std::vector<std::vector<int>> map_data;
    std::ifstream file(file_path);

    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + file_path);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        int num;
        while (iss >> num) {
            row.push_back(num);
        }
        map_data.push_back(row);
    }

    return map_data;
}
