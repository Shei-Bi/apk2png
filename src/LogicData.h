#pragma once
#include "Supercell.hpp"
#include "CSVRow.h"
class LogicDataTable;
class LogicData {
public:
    CSVRow* csvRow;
    int rowSize;
    LogicDataTable* parentTable;
    LogicData();
    LogicData(CSVRow*, LogicDataTable*);
    void setCSVRow(CSVRow*, int);
    String& getName();
};