#include "ast_visitor.h"

// antlrcpp::Any ASTVisitor::visitAtomExpr(SillyParser::AtomExprContext *ctx) {
//     //        cout << ctx->getText() << endl;
//     //        return MyGrammarBaseVisitor::visitAtomExpr(ctx);
//     int value = std::stoi(ctx->atom->getText());
//     return value;
// }

// antlrcpp::Any ASTVisitor::visitParenExpr(SillyParser::ParenExprContext *ctx) {
//     //        return MyGrammarBaseVisitor::visitParenExpr(ctx);
//     //    for(auto i : ctx->children){
//     //        std::cout<<i->toString()<<std::endl;
//     //    }

//     return visit(ctx->expr());
// }

// antlrcpp::Any ASTVisitor::visitOpExpr(SillyParser::OpExprContext *ctx) {
//     //    for(auto i : ctx->children){
//     //        std::cout<<i->toString()<<std::endl;
//     //    }
//     int left = visit(ctx->left).as<int>();
//     int right = visit(ctx->right).as<int>();

//     // antlrcpp::Any op;
//     char op_char = ctx->op->getText()[0];
//     int res = 0;
//     switch (op_char) {
//     case '+':
//         // op = AST::operator_t::kAdd;
//         // return left + right;
//         res = left + right;
//         break;
//     case '-':
//         // op = AST::operator_t::kSub;
//         res = left - right;
//         break;
//         // return left - right;
//     case '*':
//         // op = AST::operator_t::kMult;
//         res = left * right;
//         break;
//         // return left * right;
//     case '/':
//         // op = AST::operator_t::kDiv;
//         res = left / right;
//         break;
//         // return left / right;
//     }
//     // std::cout << "=" << res << std::endl;
//     //        return MyGrammarBaseVisitor::visitOpExpr(ctx);
//     // return AST::BinOp(left, op, right);
//     return res;
// }

// // antlrcpp::Any ASTVisitor::visitFuncCall(SillyParser::FuncCallContext *ctx){
// //     std::string func_name = visit(ctx->funcname);
// // }
// antlrcpp::Any ASTVisitor::visitBaseblock(SillyParser::BaseblockContext *ctx) {
//     // 访问baseblock子节点
//     //    for(auto i: ctx->children){
//     //        std::cout<<i->toString()<<std::endl;
//     //    }
//     return visitChildren(ctx);
// }

antlrcpp::Any ASTVisitor::visitCompUnit(SillyParser::CompUnitContext *ctx) {

    visitChildren(ctx);
    return nullptr;
}
antlrcpp::Any ASTVisitor::visitFuncType(SillyParser::FuncTypeContext *ctx) {
    return visitChildren(ctx);
}
/**
 * if match the terminal return the name of this node
 * @param node
 * @return
 */
antlrcpp::Any ASTVisitor::visitTerminal(antlr4::tree::TerminalNode *node) {
//    return AbstractParseTreeVisitor::visitTerminal(node);
//    return node->getText();
//    std::cout<<node->getText()<<std::endl;
//    return nullptr;
    std::string str = node->getText();
    if (str=="EOF"){
        return nullptr;
    }
    return node->getText();
}
/**
 * override visitChildren in APTV
 * @param node
 * @return
 */
antlrcpp::Any ASTVisitor::visitChildren(antlr4::tree::ParseTree *node) {
//    return AbstractParseTreeVisitor::visitChildren(node);
    size_t n = node->children.size();
    if (n==1){
        // only has one terminalsymbol
        return node->children[0]->accept(this);
    }else{
        for(size_t i = 0; i < n;i ++){
            node->children[i]->accept(this);
        }
        return nullptr;
    }

}
/**
 * 
 * @param ctx
 * @return
 */
antlrcpp::Any ASTVisitor::visitBType(SillyParser::BTypeContext *ctx) {
    // it only has one terminal
    return ctx->INT()->getText();
}
antlrcpp::Any ASTVisitor::visitNumber(SillyParser::NumberContext *ctx) {
    return std::stoi(ctx->INTEGER()->getText());
//    return SillyBaseVisitor::visitNumber(ctx);
}
antlrcpp::Any ASTVisitor::visitFuncDef(SillyParser::FuncDefContext *ctx) {
//    return SillyBaseVisitor::visitFuncDef(ctx);
//    FunctionType *FT = FunctionType::get()
    // todo
}
antlrcpp::Any ASTVisitor::visitFuncFParams(SillyParser::FuncFParamsContext *ctx) {
    return SillyBaseVisitor::visitFuncFParams(ctx);
}
antlrcpp::Any ASTVisitor::visitFuncFParam(SillyParser::FuncFParamContext *ctx) {
    return SillyBaseVisitor::visitFuncFParam(ctx);
}
