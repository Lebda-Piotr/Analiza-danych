// DataPoint.cpp
#include "DataPoint.h"

DataPoint::DataPoint(const std::string& date_time, double autokonsumpcja, double eksport, double import, double pobor, double produkcja)
    : date_time(date_time), autokonsumpcja(autokonsumpcja), eksport(eksport), import(import),
      pobor(pobor), produkcja(produkcja) {}
