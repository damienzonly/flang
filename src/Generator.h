#pragma once
#include "Parser.h"
#include <sstream>

class Generator {
public:
    Generator(NodeRoot root): root(std::move(root)), _asm(""){}
    std::string generate();
private:
    void generateStatement(const NodeStatement&);
    void generateExpression(const NodeExpr&);
    const NodeRoot root;
    std::stringstream _asm;
};
