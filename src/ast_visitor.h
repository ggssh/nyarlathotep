#include "SillyBaseVisitor.h"

class ASTVisitor : public SillyBaseVisitor {
private:
    antlrcpp::Any RES = antlrcpp::Any(true);

public:
    antlrcpp::Any visitBaseblock(SillyParser::BaseblockContext *ctx) override;

    antlrcpp::Any visitAtomExpr(SillyParser::AtomExprContext *ctx) override;

    antlrcpp::Any visitParenExpr(SillyParser::ParenExprContext *ctx) override;

    antlrcpp::Any visitOpExpr(SillyParser::OpExprContext *ctx) override;

    // antlrcpp::Any visitFuncCall(SillyParser::FuncCallContext *ctx) override;

    // antlrcpp::Any visitFuncCall(MyGrammarParser::FuncCallContext *ctx) override {
    //     std::string func_name = ctx->funcname->getText();
    //     std::cout << func_name << "'s result is : " << std::endl;
    //     std::string param = ctx->params->getText();
    //     std::cout << param << std::endl;
    // }
};