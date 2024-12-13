#include "Supercell.hpp"
#include <stdio.h>
#include <algorithm>
#include "CSVColumn.hpp"
#include "CSVRow.h"

class CSVTable {
public:
    LogicArrayList<String> columnNames;
    LogicArrayList<CSVColumn*> columns;
    LogicArrayList<CSVRow*> rows;
    int rowSize;
    CSVTable(int columnSize, int rowSize) :rowSize(rowSize) {
        if (columnSize <= 0) columnSize = 4;
        columnNames.reserve(columnSize);
        columns.reserve(columnSize);
        rows.reserve(rowSize);
    }
    void addColumn(std::string& column) {
        columnNames.emplace_back(column);
    }
    void addColumnType(int type) {
        columns.push_back(new CSVColumn(type, rowSize));
    }
    void columnNamesLoaded() {
        columns.reserve(columnNames.size());
    }
    CSVRow* createRow() {
        return new CSVRow(this);
    }
    void addRow(CSVRow* row) {
        rows.push_back(row);
    }
    int getColumnRowCount() {
        return columns[0]->getSize();
    }
    void addAndConvertValue(std::string_view& element, int index) {
        if (element.length() == 0) {
            switch (columns[index]->type) {
            case 0:
                columns[index]->strings.emplace_back("");
                break;
            case 1:
                columns[index]->integers.push_back(0x7FFFFFFF);
                break;
            case 2:
                columns[index]->booleans.push_back(false);
                break;
            }
        }
        else {
            std::string stack_stuff(element);
            switch (columns[index]->type) {
            case 0:
                columns[index]->strings.emplace_back(element);
                break;
            case 1:
                columns[index]->integers.push_back(std::stoi(stack_stuff));
                break;
            case 2:
                std::transform(stack_stuff.begin(), stack_stuff.end(), stack_stuff.begin(), [](unsigned char c) {
                    return std::tolower(c);
                    });
                columns[index]->booleans.push_back(stack_stuff == "true" ? 1 : (stack_stuff == "false" ? 0 : (abort(), 0)));
                break;
            }
        }
    }
    int getRowCount() {
        return rows.size();
    }
    String& getValueAt(int column, int row) {
        if (column < -1) return String("");
        return columns[column]->getStringValue(row);
    }
};