#pragma once
#include "Tokenizer.h"

std::vector<Token> Tokenizer::tokenize() {
    char c;
    std::string buf;
    std::vector<Token> tokens;
    while (peek().has_value()) {
        c = peek().value();
        if (std::isalpha(c)) {
            while (peek().has_value() && std::isalnum(peek().value()))
                buf.push_back(consume());
            if (buf == "exit")
                tokens.push_back(Token{.type = TokenType::exit});
            buf.clear();
            continue;
        } else if (std::isdigit(c)) {
            while (peek().has_value() && std::isdigit(peek().value()))
                buf.push_back(consume());
            tokens.push_back(Token {.type = TokenType::int_literal, .value = buf});
            buf.clear();
            continue;
        } else if (c == '(') {
            consume();
            tokens.push_back(Token{.type = TokenType::open_brack});
            continue;
        } else if (c == ')') {
            consume();
            tokens.push_back(Token{.type = TokenType::close_brack});
            continue;
        } else if (c == ';') {
            consume();
            tokens.push_back(Token{.type = TokenType::semicol});
            continue;
        }
    }
    return tokens;
}

std::optional<char> Tokenizer::peek(size_t offset) {
    auto sum = offset + charIndex;
    if (sum >= src.length()) return {};
    return src[sum];
}

char Tokenizer::consume() {
    return src[charIndex++];
}
