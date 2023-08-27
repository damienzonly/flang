#include <fstream>
#include <sstream>
#include "Tokenizer.h"
#include "Parser.h"
#include "Generator.h"

int main(int argc, char** argv) {
    std::fstream input(argv[1], std::ios::in);
    std::stringstream stream;
    stream << input.rdbuf();
    std::string content = stream.str();
    Tokenizer t(content);
    auto tokens = t.tokenize();
    Parser p(tokens);
    auto root = p.parse();
    Generator g(root);
    auto _asm = g.generate();
    std::cout << "generated:\n" << _asm << std::endl;
    std::fstream file("out.asm", std::ios::out);
    file << _asm;
    file.close();
    system("nasm -f elf64 out.asm");
    system("ld -o main out.o");
    return 0;
}
