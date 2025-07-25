#pragma once
#include <string>

class Catalog {
public:
    void set_current_db(const std::string& name);
    std::string current_db() const;

private:
    std::string db_name = "default";
};
