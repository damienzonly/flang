#pragma once
#include <iostream>

enum class TokenType {
    exit,
    open_brack,
    close_brack,
    semicol,
    int_literal
};

typedef struct {
    TokenType type;
    std::optional<std::string> value;
} Token;

class Tokenizer {
public:
    Tokenizer(const std::string& content): src(content){}
    std::vector<Token> parse();
    char consume();
    std::optional<char> peek(size_t offset = 0);
private:
    size_t charIndex;
    std::string src;
};