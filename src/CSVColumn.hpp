#pragma once
#include "Supercell.hpp"

class CSVColumn {
public:
    LogicArrayList<String> strings;
    LogicArrayList<bool> booleans;
    LogicArrayList<int> integers;
    int type;
    CSVColumn(int type, int rowSize) {
        this->type = type;
        switch (type)
        {
        case 0:
            strings.reserve(rowSize);
            break;
        case 1:
            integers.reserve(rowSize);
            break;
        case 2:
            booleans.reserve(rowSize);
            break;
        }
    }
    int getSize() {
        switch (type)
        {
        case 0:
            return strings.size();
        case 1:
            return integers.size();
        case 2:
            return booleans.size();
        }
    }
    String& getStringValue(int row) {
        return strings[row];
    }
};