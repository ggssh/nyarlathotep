#include <iostream>
#include <any>

#include "antlr4-runtime.h"
#include "SillyBaseVisitor.h"
#include "SillyLexer.h"
#include "SillyParser.h"
// #include <string>

// generate by ASDL
// #include "AST.h" 暂时放弃自动生成
//#include "ast_visitor.h"
#include "ast_builder.h"
#include "error_reporter.h"

using namespace antlr4;
using namespace antlrcpp;
using namespace silly;
using namespace tree;

int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    SillyLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SillyParser parser(&tokens);
    auto *tree = parser.compUnit();
    ast::ASTBuilder astBuilder;
    auto ast = astBuilder(tree);
    return 0;
}