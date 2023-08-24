#include <fstream>
#include <iostream>
#include <sstream>
#include "Tokenizer.h"

int main(int argc, char** argv) {
    std::fstream input(argv[1], std::ios::in);
    std::stringstream stream;
    stream << input.rdbuf();
    std::string content = stream.str();
    Tokenizer p(content);
    auto tokens = p.tokenize();
    return 0;
}
