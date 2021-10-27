#include <iostream>
#include <fstream>
//#include <any>

#include "antlr4-runtime.h"
#include "NyarLexer.h"
#include "NyarParser.h"
// #include <string>

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
    // 生成抽象语法树
    ASTBuilder astBuilder;
    auto ast = astBuilder(tree);
    LLVMContext context;
    nyar::ErrorReporter err(std::cerr);
    CodeGenerator codegen(context, err);
    codegen.build("nyar", ast);
    auto module = codegen.get_module();
    module->print(outs(), nullptr);
//    std::ofstream out("hhh.txt");
//    out<<"nihao"<<std::endl;
    return 0;
}