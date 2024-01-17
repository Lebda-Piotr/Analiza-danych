// DataPoint.h
#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <string>

class DataPoint {
public:
    std::string date_time;
    double autokonsumpcja;
    double eksport;
    double import;
    double pobor;
    double produkcja;

    DataPoint(const std::string& date_time, double autokonsumpcja, double eksport, double import, double pobor, double produkcja);
};

#endif // DATAPOINT_H
