#include <iostream>
#include "db/db_engine.h"

int main() {
    std::cout << "Starting CustomDB..." << std::endl;

    DBEngine engine;
    engine.test();

    return 0;
}
