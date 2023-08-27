#include "Parser.h"
#include "shared.h"
#include <iostream>

NodeRoot Parser::parse() {
    NodeRoot root = {};
    std::optional<NodeStatement> statement;
    while (peek()) {
        statement = parseStatement();
        if (statement.has_value()) root.statements.push_back(statement.value());
    }
    return root;
}

Token Parser::consume() {
    return tokens.at(tokenIndex++);
}

std::optional<Token> Parser::peek(size_t offset) {
    auto sum = offset + tokenIndex;
    if (sum >= tokens.size()) return {};
    return tokens.at(sum);
}

std::optional<NodeStatement> Parser::parseStatement() {
    NodeStatement statement = {};
    Token t = peek().value();
    if (t.type == TokenType::exit) {
        consume();
        auto next = peek();
        if (!next || next.value().type != TokenType::open_brack)
            die("expected token (");
        consume();
        auto expr = parseExpression();
        if (!expr) die("expected input in exit function");
        next = peek();
        if (!next || next.value().type != TokenType::close_brack)
            die("expected `)`");
        consume();
        next = peek();
        if (!next || next.value().type != TokenType::semicol)
            die("missing `;`");
        consume();
        statement.stmVariant = NodeStatementExit{.expr = expr.value()};
    }
    return statement;
}

std::optional<NodeExpr> Parser::parseExpression() {
    NodeExpr expression;
    auto t = peek();
    if (!t) return {};
    auto type = t.value().type;
    if (type == TokenType::int_literal) {
        expression.exprVariant = NodeExprIntLiteral {.literal = consume()};
    }
    return expression;
}
