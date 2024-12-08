#pragma once
#include <string_view>
#include <vector>

class CSVColumn {
public:
    std::vector<std::string> strings;
    std::vector<bool> booleans;
    std::vector<int> integers;
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
};