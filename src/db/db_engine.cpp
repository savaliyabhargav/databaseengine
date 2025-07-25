#include "db_engine.h"
#include <iostream>
#include <sstream>

void DatabaseEngine::execute(const std::string& command) {
    std::string cmd = command;
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    if (cmd.rfind("create database", 0) == 0)
        handle_create_db(command.substr(16));
    else if (cmd.rfind("use", 0) == 0)
        handle_use_db(command.substr(4));
    else if (cmd.rfind("create table", 0) == 0)
        handle_create_table(command);
    else if (cmd.rfind("insert into", 0) == 0)
        handle_insert_into(command);
    else if (cmd.rfind("select *", 0) == 0)
        handle_select(command);
    else
        std::cout << "❓ Unknown command\n";
}

void DatabaseEngine::handle_create_db(const std::string& dbname) {
    std::cout << "✅ Created database: " << dbname << "\n";
}

void DatabaseEngine::handle_use_db(const std::string& dbname) {
    catalog.set_current_db(dbname);
    std::cout << "✅ Switched to DB: " << dbname << "\n";
}

void DatabaseEngine::handle_create_table(const std::string& input) {
    size_t pos1 = input.find("(");
    size_t pos2 = input.find(")");
    std::string name = input.substr(13, pos1 - 13);
    std::string cols = input.substr(pos1 + 1, pos2 - pos1 - 1);

    std::stringstream ss(cols);
    std::string item;
    TableSchema schema;
    while (getline(ss, item, ',')) {
        std::stringstream ss2(item);
        std::string colname, coltype;
        ss2 >> colname >> coltype;
        schema.column_names.push_back(colname);
        schema.column_types.push_back(coltype);
    }

    tables.create_table(name, schema);
}

void DatabaseEngine::handle_insert_into(const std::string& input) {
    size_t pos1 = input.find("into") + 5;
    size_t pos2 = input.find("values");
    std::string table = input.substr(pos1, pos2 - pos1 - 1);
    size_t open = input.find("(", pos2);
    size_t close = input.find(")", pos2);
    std::string values = input.substr(open + 1, close - open - 1);

    std::stringstream ss(values);
    std::string val;
    Row row;
    while (getline(ss, val, ',')) {
        val.erase(remove(val.begin(), val.end(), '"'), val.end());
        row.push_back(val);
    }
    tables.insert_row(table, row);
}

void DatabaseEngine::handle_select(const std::string& input) {
    size_t pos = input.find("from");
    std::string table = input.substr(pos + 5);
    tables.select_all(table);
}
