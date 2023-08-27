#pragma once
#include "Tokenizer.h"
#include <variant>
#define OPEN_BRACK "("
#define CLOSE_BRACK ")"
#define SEMI ";"

typedef struct {
    Token literal;
} NodeExprIntLiteral;

typedef struct {
    std::variant<NodeExprIntLiteral> exprVariant;
} NodeExpr;

typedef struct {
    std::string symbol;
    std::string oper;
    NodeExpr expr;
} NodeStatementAssign;

typedef struct {
    NodeExpr expr;
} NodeStatementExit;

typedef struct {
    std::variant<NodeStatementAssign, NodeStatementExit> stmVariant;
} NodeStatement;

typedef struct {
    std::vector<NodeStatement> statements;
} NodeRoot;

class Parser {
public:
    Parser(const std::vector<Token>& tokens): tokens(tokens){}
    NodeRoot parse();
    Token consume();
    std::optional<Token> peek(size_t offset = 0);
    std::optional<NodeStatement> parseStatement();
    std::optional<NodeExpr> parseExpression();
private:
    std::vector<Token> tokens;
    size_t tokenIndex = 0;
};

