#include "CSVRow.h"
#include "CSVTable.hpp"

CSVRow::CSVRow(CSVTable* table) {
    this->table = table;
    rowIndex = table->getColumnRowCount();
    table->addRow(this);
}