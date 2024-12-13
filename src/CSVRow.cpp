#include "CSVRow.h"
#include "CSVTable.hpp"

CSVRow::CSVRow(CSVTable* table) :table(table) {
    rowIndex = table->getColumnRowCount();
    table->addRow(this);
}
String& CSVRow::getName() {
    return table->getValueAt(0, rowIndex);
}
