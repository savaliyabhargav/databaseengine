#pragma once
#include "table_manager.h"
#include "catalog.h"

class DatabaseEngine {
public:
    void execute(const std::string& command);

private:
    Catalog catalog;
    TableManager tables;

    void handle_create_db(const std::string& dbname);
    void handle_use_db(const std::string& dbname);
    void handle_create_table(const std::string& input);
    void handle_insert_into(const std::string& input);
    void handle_select(const std::string& input);
};
