#include "Generator.h"
#include <variant>
std::string Generator::generate() {
    _asm << "global _start\n";
    _asm << "_start:\n";
    for (auto stm: root.statements) {
        generateStatement(stm);
    }
    _asm << "_quit:\n";
    _asm << "\tmov rax, 60\n";
    _asm << "\tmov rdi, 0\n";
    _asm << "\tsyscall\n";
    return _asm.str();
}

void Generator::generateStatement(const NodeStatement& statement) {
    struct Vis {
        Generator* gen;
        void operator()(const NodeStatementExit& s) const {
            gen->generateExpression(s.expr);
            gen->_asm << "\tmov rax, 60\n";
            gen->_asm << "\tpop rdi\n";
            gen->_asm << "\tsyscall\n";
        }
        void operator()(const NodeStatementAssign& s) const {

        }
    };
    Vis v = Vis{.gen = this};
    std::visit(v, statement.stmVariant);
}

void Generator::generateExpression(const NodeExpr& expr) {
    struct Vis {
        Generator* gen;
        void operator()(const NodeExprIntLiteral expr) {
            gen->_asm << "\tmov rax, " << expr.literal.value.value() << "\n";
            gen->_asm << "\tpush rax\n";
        }
    };
    auto vis = Vis{.gen = this};
    std::visit(vis, expr.exprVariant);
}
