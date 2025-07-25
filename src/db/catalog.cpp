#include "catalog.h"

void Catalog::set_current_db(const std::string& name) {
    db_name = name;
}

std::string Catalog::current_db() const {
    return db_name;
}
