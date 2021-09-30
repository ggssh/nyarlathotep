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
    return RES;
}