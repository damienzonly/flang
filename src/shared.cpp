#include "shared.h"
#include <iostream>

void die(size_t code) {
    exit(code);
}
void die(std::string message, size_t code) {
    std::cerr << message << std::endl;
    die(code);
}