#include <iostream>
#include <any>

#include "antlr4-runtime.h"
#include "SillyBaseVisitor.h"
#include "SillyLexer.h"
#include "SillyParser.h"

// generate by ASDL
// #include "AST.h" 暂时放弃自动生成
#include "ast_visitor.h"

using namespace antlr4;

int eval(const std::string &line) {
    //build parse tree
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
    SillyParser::BaseblockContext* tree = parser.baseblock();
    ASTVisitor visitor;
    int a = visitor.visitBaseblock(tree).as<int>();
    std::cout<<a<<std::endl;
    // TreeShapeListener listener;
    // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    
    // std::ifstream ifstream;
    // ifstream.open(argv[1]);
    // std::string line;
    // while (std::getline(ifstream, line)) {
    //     std::cout << line << "=";
    //     std::cout << eval(line) << std::endl;
    // }
    // while (std::getline(ifstream, line)) {
    //     sltest(line);
    // }
    return 0;
}