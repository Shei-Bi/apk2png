#include "LogicData.h"
#include <stdlib.h>
LogicData::LogicData() {
    abort();
}
LogicData::LogicData(CSVRow* csvRow, LogicDataTable* parentTable) :csvRow(csvRow), parentTable(parentTable) {
    ;
}
void LogicData::setCSVRow(CSVRow* csvRow, int size) {
    this->csvRow = csvRow;
    rowSize = size;
}
String& LogicData::getName() {
    return csvRow->getName();
}

