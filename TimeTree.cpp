// TimeTree.cpp
#include "TimeTree.h"
#include <iostream>
#include <iomanip>

void TimeTree::addDataPoint(const DataPoint& dataPoint) {
    int year, month, day, quarter;

    std::stringstream dateStream(dataPoint.date_time);
    dateStream.imbue(std::locale("pl_PL.utf8"));  // Ustawienie lokalizacji dla polskiego formatu daty

    char dot; // Odczytuj kropkę oddzielającą dzień, miesiąc i rok
    dateStream >> day >> dot >> month >> dot >> year;

    if (dateStream.fail()) {
        std::cerr << "Error reading date: " << dataPoint.date_time << std::endl;
        return;
    }

    quarter = getQuarter(dataPoint.date_time[11] - '0', dataPoint.date_time[14] - '0');

    tree[year][month][day][quarter].push_back(dataPoint);
}

void TimeTree::printTree() const {
    for (const auto& yearPair : tree) {
        std::cout << "Rok: " << yearPair.first << std::endl;
        for (const auto& monthPair : yearPair.second) {
            std::cout << "  Miesiac: " << monthPair.first << std::endl;
            for (const auto& dayPair : monthPair.second) {
                std::cout << "    Dzien: " << dayPair.first << std::endl;
                for (const auto& quarterPair : dayPair.second) {
                    std::cout << "      Quarter: " << quarterPair.first << std::endl;
                    for (const auto& dataPoint : quarterPair.second) {
                        std::cout << "        Data: " << dataPoint.date_time
                                  << ", Autokonsumpcja: " << dataPoint.autokonsumpcja
                                  << ", Eksport: " << dataPoint.eksport
                                  << ", Import: " << dataPoint.import
                                  << ", Pobor: " << dataPoint.pobor
                                  << ", Produkcja: " << dataPoint.produkcja << std::endl;
                    }
                }
            }
        }
    }
}

int TimeTree::getQuarter(int hour, int minute) const {
    if (0 <= hour && hour < 6) {
        return 1;
    } else if (6 <= hour && hour < 12) {
        return 2;
    } else if (12 <= hour && hour < 18) {
        return 3;
    } else {
        return 4;
    }
}