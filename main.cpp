#include <iostream>
#include <any>

#include "antlr4-runtime.h"
#include "NyarBaseVisitor.h"
#include "NyarLexer.h"
#include "NyarParser.h"
// #include <string>

//#include "ast_visitor.h"
#include "ast_builder.h"
#include "code_gen.h"
#include "error_reporter.h"

using namespace antlr4;
using namespace antlrcpp;
using namespace nyar::ast;
using namespace tree;

int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    NyarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    NyarParser parser(&tokens);
    auto *tree = parser.compUnit();
    ASTBuilder astBuilder;
    auto ast = astBuilder(tree);
    return 0;
}