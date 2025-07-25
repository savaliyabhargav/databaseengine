#include "table_manager.h"
#include <iostream>

void TableManager::create_table(const std::string& name, const TableSchema& schema) {
    if (schemas.count(name)) {
        std::cout << "❌ Table already exists.\n";
        return;
    }
    schemas[name] = schema;
    tables[name] = {};
    std::cout << "✅ Table '" << name << "' created.\n";
}

void TableManager::insert_row(const std::string& table, const Row& row) {
    if (!tables.count(table)) {
        std::cout << "❌ Table not found.\n";
        return;
    }
    if (row.size() != schemas[table].column_names.size()) {
        std::cout << "❌ Column count mismatch.\n";
        return;
    }
    tables[table].push_back(row);
    std::cout << "✅ Row inserted.\n";
}

void TableManager::select_all(const std::string& table) {
    if (!tables.count(table)) {
        std::cout << "❌ Table not found.\n";
        return;
    }
    const auto& schema = schemas[table];
    for (const auto& col : schema.column_names)
        std::cout << col << "\t";
    std::cout << "\n---------------------------------\n";
    for (const auto& row : tables[table]) {
        for (const auto& val : row)
            std::cout << val << "\t";
        std::cout << "\n";
    }
}
