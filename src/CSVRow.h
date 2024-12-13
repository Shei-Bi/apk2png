#pragma once
#include "Supercell.hpp"
class CSVTable;

class CSVRow {
public:
    CSVTable* table;
    int rowIndex;
    CSVRow(CSVTable* table);
    String& getName();
};