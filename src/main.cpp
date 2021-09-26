#include <iostream>
#include <any>

#include "antlr4-runtime.h"
#include "MyGrammarBaseVisitor.h"
#include "MyGrammarLexer.h"
#include "MyGrammarParser.h"


// generate by ASDL
#include "AST.h"

using namespace antlr4;

class TreeVisitor : public MyGrammarBaseVisitor {
private:
public:
    antlrcpp::Any visitAtomExpr(MyGrammarParser::AtomExprContext *ctx) override {
//        cout << ctx->getText() << endl;
//        return MyGrammarBaseVisitor::visitAtomExpr(ctx);
        return AST::IntLit(std::stoi(ctx->getText()));
    }

    antlrcpp::Any visitParenExpr(MyGrammarParser::ParenExprContext *ctx) override {
//        return MyGrammarBaseVisitor::visitParenExpr(ctx);
        return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr());
    }

    antlrcpp::Any visitOpExpr(MyGrammarParser::OpExprContext *ctx) override {
        AST::expr_t left = visit(ctx->left);
        AST::expr_t right = visit(ctx->right);

        AST::operator_t op;
        char op_char = ctx->op->getText()[0];
        switch (op_char) {
            case '+':
                op = AST::operator_t::kAdd;
                break;
            case '-':
                op = AST::operator_t::kSub;
                break;
            case '*':
                op = AST::operator_t::kMult;
                break;
            case '/':
                op = AST::operator_t::kDiv;
                break;
        }

//        return MyGrammarBaseVisitor::visitOpExpr(ctx);
        return AST::BinOp(left, op, right);
    }
};

class EvalVisitor : public AST::BaseVisitor {
public:
    std::any visitBinOp(AST::BinOp_t node) override {
//        int left_value = visit(node->left);
        int left_value = std::any_cast<int>(visit(node->left));
        int right_value = std::any_cast<int>(visit(node->right));

        int result;
        switch (node->op) {
            case AST::operator_t::kAdd:
                result = left_value + right_value;
                break;
            case AST::operator_t::kSub:
                result = left_value - right_value;
                break;
            case AST::operator_t::kMult:
                result = left_value * right_value;
                break;
            case AST::operator_t::kDiv:
                result = left_value / right_value;
                break;
        }
        return result;
    }

    std::any visitIntLit(AST::IntLit_t node) override {
//        return nullptr;
        return node->n;
    }

    std::any visitOperator(AST::operator_t value) override {
//        return nullptr;
        return 0;
    }
};

int eval(const std::string &line) {
    //build parse tree
    ANTLRInputStream input(line);
    MyGrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MyGrammarParser parser(&tokens);
    tree::ParseTree *parseTree = parser.expr();

    // print parse tree
//    std::cout << parseTree->toStringTree(&parser) << std::endl;

    // build abstract syntax tree
    TreeVisitor treeVisitor;
    AST::expr_t ast = treeVisitor.visit(parseTree);

    // print ast
//    std::cout << AST::to_string(ast) << std::endl;

    // return integer evaluation of AST
    EvalVisitor evalVisitor;
    return std::any_cast<int>(evalVisitor.visit(ast));
}

int main(int argc, const char *argv[]) {
//    std::ifstream stream;
//    stream.open(argv[1]);
//    ANTLRInputStream input(stream);
//    MyGrammarLexer lexer(&input);
//    CommonTokenStream tokens(&lexer);
//    MyGrammarParser parser(&tokens);
//    tree::ParseTree *tree = parser.expr();
//    TreeShapeListener listener;
//    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
//    TreeVisitor visitor;
//    visitor.visit(tree);
    std::ifstream ifstream;
    ifstream.open(argv[1]);
    std::string line;
    while (std::getline(ifstream,line)){
        std::cout<<line<<"=";
        std::cout << eval(line)<<std::endl;
    }
    return 0;
}