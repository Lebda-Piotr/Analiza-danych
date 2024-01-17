// TimeTree.h
#ifndef TIMETREE_H
#define TIMETREE_H

#include <map>
#include <vector>
#include "DataPoint.h"

class TimeTree {
public:
    void addDataPoint(const DataPoint& dataPoint);
    void printTree() const;

private:
    std::map<int, std::map<int, std::map<int, std::map<int, std::vector<DataPoint>>>>> tree;

    int getQuarter(int hour, int minute) const;
};

#endif // TIMETREE_H