#pragma once
#include <iostream>
#include <optional>
#include <vector>

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

class Tokenizer{
public:
    Tokenizer(const std::string& content): src(content){}
    std::vector<Token> tokenize();
    char consume();
    std::optional<char> peek(size_t offset = 0);
private:
    std::string src;
    size_t charIndex = 0;
};