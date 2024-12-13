#include "LogicDataTable.hpp"
LogicDataTable* TABLES[61];
class LogicDataTables {
public:
    static void initDataTable(CSVNode* csvNode, int index) {
        if (TABLES[index]) {
            ;
        }
        else {
            TABLES[index] = new LogicDataTable(csvNode->table, index);
        }
    }
};