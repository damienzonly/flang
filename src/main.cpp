#include <fstream>
#include <iostream>
#include <sstream>
#include "Parser.h"

int main(int argc, char** argv) {
    std::fstream input(argv[1], std::ios::in);
    std::stringstream stream;
    stream << input.rdbuf();
    std::string content = stream.str();
    Parser p(content);
    auto tokens = p.parse();
    return 0;
}
