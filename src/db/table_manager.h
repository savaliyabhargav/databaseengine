#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct TableSchema {
    std::vector<std::string> column_names;
    std::vector<std::string> column_types;
};

using Row = std::vector<std::string>;
using TableData = std::vector<Row>;

class TableManager {
public:
    void create_table(const std::string& name, const TableSchema& schema);
    void insert_row(const std::string& table, const Row& row);
    void select_all(const std::string& table);

private:
    std::unordered_map<std::string, TableSchema> schemas;
    std::unordered_map<std::string, TableData> tables;
};
