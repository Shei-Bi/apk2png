#pragma once
class CSVTable;

class CSVRow {
public:
    CSVTable* table;
    int rowIndex;
    CSVRow(CSVTable* table);
};