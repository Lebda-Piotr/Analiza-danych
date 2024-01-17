// main.cpp
#include "CSVReader.h"
#include "TimeTree.h"

int main() {
    std::string filePath = "nazwa_pliku.csv";
    CSVReader csvReader(filePath);
    std::vector<DataPoint> dataPoints = csvReader.readData();

    TimeTree timeTree;
    for (const auto& dataPoint : dataPoints) {
        timeTree.addDataPoint(dataPoint);
    }

    // Dodatkowo możesz wyświetlić drzewo
    timeTree.printTree();

    return 0;
}
