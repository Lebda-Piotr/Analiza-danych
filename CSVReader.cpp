// CSVReader.cpp
#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

CSVReader::CSVReader(const std::string& filePath) : filePath(filePath) {}

std::vector<DataPoint> CSVReader::readData() {
    std::vector<DataPoint> dataPoints;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return dataPoints;
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateTime;
        double autokonsumpcja, eksport, import_, pobor, produkcja;

        if (!(iss >> dateTime >> autokonsumpcja >> eksport >> import_ >> pobor >> produkcja)) {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }

        dataPoints.emplace_back(dateTime, autokonsumpcja, eksport, import_, pobor, produkcja);
    }

    file.close();
    return dataPoints;
}