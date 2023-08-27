#include <fstream>
#include <iostream>
#include <sstream>
#include "Tokenizer.h"
#include "Parser.h"

int main(int argc, char** argv) {
    std::fstream input(argv[1], std::ios::in);
    std::stringstream stream;
    stream << input.rdbuf();
    std::string content = stream.str();
    Tokenizer t(content);
    auto tokens = t.tokenize();
    Parser p(tokens);
    auto x = p.parse();
    return 0;
}
