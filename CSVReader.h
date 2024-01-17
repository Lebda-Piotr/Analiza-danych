// CSVReader.h
#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include "DataPoint.h"

class CSVReader {
public:
    CSVReader(const std::string& filePath);
    std::vector<DataPoint> readData();

private:
    std::string filePath;
};

#endif // CSVREADER_H
