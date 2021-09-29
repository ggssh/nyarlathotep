#include <iostream>
#include <any>
// #include <llvm-12/llvm/IR/IRBuilder.h>

#include "antlr4-runtime.h"
#include "SillyBaseVisitor.h"
#include "SillyLexer.h"
#include "SillyParser.h"
// #include <string>

// generate by ASDL
// #include "AST.h" 暂时放弃自动生成
#include "ast_visitor.h"


using namespace antlr4;
// using namespace llvm;

int eval(const std::string &line) {
    // build parse tree
    ANTLRInputStream input(line);
    SillyLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SillyParser parser(&tokens);
    tree::ParseTree *parseTree = parser.expr();

    ASTVisitor v;
    return v.visit(parseTree);
}

int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    SillyLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SillyParser parser(&tokens);
    // tree::ParseTree *tree = parser.baseblock();
    // SillyParser::BaseblockContext* tree = parser.baseblock();
    // 生成一个语法树
    tree::ParseTree *tree = parser.baseblock();
    ASTVisitor visitor;
    // int a = visitor.visitBaseblock(tree).as<int>();
    int a = visitor.visit(tree).as<int>();
    std::cout << a << std::endl;
    return 0;
}