//
// Created by ggssh on 2021/9/30.
//

#include "ast_builder.h"

using namespace nyar::ast;

antlrcpp::Any ASTBuilder::visitCompUnit(NyarParser::CompUnitContext *ctx) {
    auto result = new CompUnit;
    result->line = 1;
    result->pos = 0;
    auto decls = ctx->decl();
    auto funcdefs = ctx->funcDef();
    int decls_i = 0, funcdefs_i = 0;
    for (auto child: ctx->children) {
        if (antlrcpp::is<NyarParser::DeclContext *>(child)) {
            auto decl_list =
                    antlr4::tree::AbstractParseTreeVisitor::visit(decls[decls_i++]).as<ptr_list<VarDefStmt >>();
            for (int i = 0; i < decl_list.size(); ++i) {
                result->body.push_back(decl_list[i]);
            }
        } else if (antlrcpp::is<NyarParser::FuncDefContext *>(child)) {
            ptr<FuncDef> funcdef;
            funcdef.reset(antlr4::tree::AbstractParseTreeVisitor::visit(funcdefs[funcdefs_i++]).as<FuncDef *>());
//            result->global_defs.push_back(tmp);
            result->body.push_back(funcdef);
        }
    }
//    printf("AST has been successfully established!\n");
    return static_cast<CompUnit *>(result);
}

antlrcpp::Any ASTBuilder::visitDecl(NyarParser::DeclContext *ctx) {
    // decl:constDecl
    if (ctx->constDecl())
        return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->constDecl());
    // decl:varDecl
    if (ctx->varDecl())
        return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->varDecl());
    //    return SillyBaseVisitor::visitDecl(ctx);
}

antlrcpp::Any ASTBuilder::visitConstDecl(NyarParser::ConstDeclContext *ctx) {
    //    printf("enter visitConstDecl");
    ptr_list<VarDefStmt> result;
    auto vardefs = ctx->constDef();
    for (int i = 0; i < vardefs.size(); ++i) {
        ptr<VarDefStmt> temp;
        temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(vardefs[i]).as<VarDefStmt *>());
        result.push_back(temp);
    }
//    printf("ConstDecl\n");
    return static_cast<ptr_list<VarDefStmt>>(result);
    //    return SillyBaseVisitor::visitConstDecl(ctx);
}

antlrcpp::Any ASTBuilder::visitConstDef(NyarParser::ConstDefContext *ctx) {
    auto result = new VarDefStmt;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_const = true;
    result->name = std::string(ctx->IDENTIFIER()->getSymbol()->getText());
    result->init_value.clear();
    auto exprs = ctx->expr();
    int comma_count = ctx->COMMA().size();
    // constDef : IDENTIFIER ASSIGN expr
    if (!ctx->LBRACK()) {
        result->arr_length.reset();
        result->init_value.resize(1);
        result->init_value[0].reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
    } else if (comma_count == exprs.size() - 2) {
        result->arr_length.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
        for (int i = 1; i < exprs.size(); ++i) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->init_value.push_back(temp);
        }
    } else {
        // such as a[] = {}, just handle it as single variable
        if (comma_count == 0) {
            result->arr_length.reset();
        } else {
            Number *temp = new Number;
            temp->line = ctx->getStart()->getLine();
            temp->pos = ctx->LBRACK()->getSymbol()->getCharPositionInLine() + 1;
            temp->number = comma_count + 1;
            result->arr_length.reset(temp);
        }

        for (int i = 0; i < exprs.size(); ++i) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->init_value.push_back(temp);
        }
    }
//    printf("ConstDef\n");
    return static_cast<VarDefStmt *>(result);
}

antlrcpp::Any ASTBuilder::visitVarDecl(NyarParser::VarDeclContext *ctx) {
    ptr_list<VarDefStmt> result;
    auto vardefs = ctx->varDef();
    for (int i = 0; i < vardefs.size(); ++i) {
        ptr<VarDefStmt> temp;
        temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(vardefs[i]).as<VarDefStmt *>());
        result.push_back(temp);
    }
//    printf("VarDecl\n");
    return static_cast<ptr_list<VarDefStmt>>(result);
    //    auto result = new Stmt;
    //    return SillyBaseVisitor::visitVarDecl(ctx);
}

antlrcpp::Any ASTBuilder::visitVarDef(NyarParser::VarDefContext *ctx) {
    //    int v1, v2 = 3;
    //    int a1[3];
    //    int a2[3] = {1, 2};
    //    int a3[] = {1, 2, 3, 4};
    //    const int c1 = 3, a4[2] = {1, 2};
    auto result = new VarDefStmt;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_const = false;
    result->name = std::string(ctx->IDENTIFIER()->getSymbol()->getText());
    result->init_value.clear();
    // get the num of comma to handle the last state
    int comma_count = ctx->COMMA().size();
    auto exprs = ctx->expr();
    // varDef : IDENTIFIER
    if (exprs.size() == 0) {
        result->arr_length.reset();
        result->init_value.clear();
    }
        // varDef : IDENTIFIER ASSIGN expr
    else if (!ctx->LBRACK()) {
        result->arr_length.reset();
        result->init_value.resize(1);
        result->init_value[0].reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
    }
        // varDef : IDENTIFIER LBRACK expr RBRACE
    else if (!ctx->LBRACE()) {
        result->arr_length.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
        result->init_value.clear();
    }
        // varDef : IDENTIFIER LBRACK (expr)? RBRACK ASSIGN LBRACE expr (COMMA expr)* RBRACE
        // varDef : IDENTIFIER LBRACK expr RBRACK ASSIGN LBRACE expr (COMMA expr)* RBRACE
    else if (comma_count == exprs.size() - 2) {
        result->arr_length.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
        result->init_value.clear();
        for (int i = 1; i < exprs.size(); i++) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->init_value.push_back(temp);
        }
    }
        // [nothing] need compiler to infer
    else {
        // such as a[] = {}, just handle it as single variable
        if (comma_count == 0) {
            result->arr_length.reset();
        } else {
            Number *temp = new Number;
            temp->line = ctx->getStart()->getLine();
            temp->pos = ctx->LBRACK()->getSymbol()->getCharPositionInLine() + 1;
            temp->number = comma_count + 1;
            result->arr_length.reset(temp);
        }

        for (int i = 0; i < exprs.size(); ++i) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->init_value.push_back(temp);
        }
    }
//    printf("VarDef\n");
    return static_cast<VarDefStmt *>(result);
}

antlrcpp::Any ASTBuilder::visitFuncDef(NyarParser::FuncDefContext *ctx) {
    auto result = new FuncDef;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    if (ctx->INT()){
        result->type = functype::INT;
    }else{
        result->type = functype::VOID;
    }
    // Function name
    result->name = ctx->IDENTIFIER()->getSymbol()->getText();
    auto block = ctx->block();
    // handle function block
    result->body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(block).as<Block *>());

//    printf("FuncDef\n");
    return static_cast<FuncDef *>(result);
    //    return SillyBaseVisitor::visitFuncDef(ctx);
}

antlrcpp::Any ASTBuilder::visitBlock(NyarParser::BlockContext *ctx) {
    auto ds = ctx->decl();
    auto ss = ctx->stmt();
    auto result = new Block;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    // clear the body
    result->body.clear();
    //    result->body = blocks.
    //    for(auto i : blocks){
    //
    //    }
    //    for (auto i : ds) {
    //        result->body.push_back(static_cast<std::shared_ptr<Stmt>>(antlr4::tree::AbstractParseTreeVisitor::visit(i).as<Stmt *>()));
    //    }
    //    for (auto i : ss) {
    //        result->body.push_back(static_cast<std::shared_ptr<Stmt>>(antlr4::tree::AbstractParseTreeVisitor::visit(i).as<Stmt *>()));
    //    }
    int decls_count = 0, stmts_count = 0;
    for (auto child: ctx->children) {
        std::shared_ptr<Stmt> tmp;
        if (antlrcpp::is<NyarParser::DeclContext *>(child)) {
            auto decllist =
                    antlr4::tree::AbstractParseTreeVisitor::visit(ds[decls_count++]).as<ptr_list<VarDefStmt >>();
            for (int i = 0; i < decllist.size(); i++) {
                result->body.push_back(decllist[i]);
            }
        } else if (antlrcpp::is<NyarParser::StmtContext *>(child)) {
            tmp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ss[stmts_count++]).as<Stmt *>());
            result->body.push_back(tmp);
        }
    }
//    printf("Block\n");
    return static_cast<Block *>(result);
}

antlrcpp::Any ASTBuilder::visitStmt(NyarParser::StmtContext *ctx) {
    // stmt : lval ASSIGN expr SEMICOLON
    // 赋值语句
    if (ctx->lVal()) {
        auto result = new AssignStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->lhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->lVal()).as<LValExpr *>());
        result->rhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr()).as<Expr *>());
        return static_cast<Stmt *>(result);
    }
        // stmt : block
        // 块
    else if (ctx->block()) {
        auto result = new Block;
        result = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
        return static_cast<Stmt *>(result);
    }
        // stmt : IDENTIFIER LPAREN RPAREN SEMICOLON
        // 函数调用
    else if (ctx->IDENTIFIER()) {
        auto result = new FuncCallStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->name = std::string(ctx->IDENTIFIER()->getSymbol()->getText());
        return static_cast<Stmt *>(result);
    }
        // stmt : IF LPAREN cond RPAREN stmt (ELSE stmt)?
        // if语句
    else if (ctx->IF()) {
        auto result = new IfStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->cond.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond()).as<Cond *>());
        result->then_body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->stmt(0)).as<Stmt *>());
        if (ctx->ELSE()) {
            result->else_body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->stmt(1)).as<Stmt *>());
        } else {
            result->else_body.reset();
        }
        return static_cast<Stmt *>(result);
    }
        // stmt : WHILE LPAREN cond RPAREN stmt
        // while语句
    else if (ctx->WHILE()) {
        auto result = new WhileStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->cond.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond()).as<Cond *>());
        result->do_body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->stmt(0)).as<Stmt *>());
        return static_cast<Stmt *>(result);
    }
        //返回值语句
    else if (ctx->RETURN()) {
        auto result = new ReturnStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->expr.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr()).as<Expr *>());
        return static_cast<Stmt *>(result);
    }
        // stmt : SEMICOLON
        // 空语句
    else {
        auto result = new EmptyStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        return static_cast<Stmt *>(result);
    }
}

antlrcpp::Any ASTBuilder::visitLVal(NyarParser::LValContext *ctx) {
    auto result = new LValExpr;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->IDENTIFIER()->getSymbol()->getText();
    //    result->name = ctx->IDENTIFIER()->getText();
    if (ctx->expr()) {
        auto expressions = ctx->expr();
        result->arr_index.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions).as<Expr *>());
    } else {
        result->arr_index = nullptr;
    }
//    printf("LVal\n");
    return static_cast<LValExpr *>(result);
    //    return SillyBaseVisitor::visitLVal(ctx);
}

antlrcpp::Any ASTBuilder::visitCond(NyarParser::CondContext *ctx) {
    auto expressions = ctx->expr();
    auto result = new Cond;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->lhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]).as<Expr *>());
    auto ro = ctx->relOp();
    if (ro->EQ())
        result->op = relop::EQ;
    else if (ro->NE())
        result->op = relop::NE;
    else if (ro->LT())
        result->op = relop::LT;
    else if (ro->LE())
        result->op = relop::LE;
    else if (ro->GT())
        result->op = relop::GT;
    else if (ro->GE())
        result->op = relop::GE;
    result->rhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[1]).as<Expr *>());
//    printf("Cond\n");
    return static_cast<Cond *>(result);
    //    return SillyBaseVisitor::visitCond(ctx);
}

antlrcpp::Any ASTBuilder::visitExpr(NyarParser::ExprContext *ctx) {
    //    return SillyBaseVisitor::visitExpr(ctx);
    // Get all sub-contexts of type "expr"
    auto expressions = ctx->expr();
    // The size of expression is two indicates that it's an expression of binary operator
    if (expressions.size() == 2) {
        auto result = new BinopExpr;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->lhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]).as<Expr *>());
        auto bo = ctx->binOp();
        //        if (ctx->binOp())
        if (bo->ADD())
            result->op = binop::ADD;
        else if (bo->SUB())
            result->op = binop::SUB;
        else if (bo->MUL())
            result->op = binop::MUL;
        else if (bo->DIV())
            result->op = binop::DIV;
        else if (bo->MOD())
            result->op = binop::MOD;
        result->rhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[1]).as<Expr *>());
        return static_cast<Expr *>(result);
    } else if (expressions.size() == 1) {
        // If is has unaryOp , it must be a unaryExpr else it must have two parens
        if (ctx->unaryOp()) {
            auto result = new UnaryopExpr;
            result->line = ctx->getStart()->getLine();
            result->pos = ctx->getStart()->getCharPositionInLine();
            auto uo = ctx->unaryOp();
            if (uo->ADD())
                result->op = unaryop::ADD;
            if (uo->SUB())
                result->op = unaryop::SUB;
            result->rhs.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]).as<Expr *>());
            return static_cast<Expr *>(result);
        } else {
            if (ctx->LPAREN())
                return antlr4::tree::AbstractParseTreeVisitor::visit(expressions[0]);
        }
    } else {
        if (ctx->lVal()) {
            return static_cast<Expr *>(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->lVal()).as<LValExpr *>());
        }
        auto result = new Number;
        auto num = ctx->NUMBER();
        // If `Number` exists as a child, we can say it's a literal integer expression.
        result->line = num->getSymbol()->getLine();
        result->pos = num->getSymbol()->getCharPositionInLine();
        auto text = num->getSymbol()->getText();
        // consider to enable 0x
        result->number = std::stoi(text, nullptr, 10);
        return static_cast<Expr *>(result);
    }
}

nyar::ast::ptr<nyar::ast::Node> ASTBuilder::operator()(antlr4::tree::ParseTree *ctx) {
    auto result = antlr4::tree::AbstractParseTreeVisitor::visit(ctx);
    if (result.is<Node *>())
        return ptr<Node>(result.as<Node *>());
    //    return ast::ptr<ast::Node>();
    if (result.is<CompUnit *>())
        return ptr<Node>(result.as<CompUnit *>());
    if (result.is<FuncDef *>())
        return ptr<Node>(result.as<FuncDef *>());
    if (result.is<Cond *>())
        return ptr<Node>(result.as<Cond *>());
    if (result.is<Expr *>())
        return ptr<Node>(result.as<Expr *>());
    if (result.is<BinopExpr *>())
        return ptr<Node>(result.as<BinopExpr *>());
    if (result.is<UnaryopExpr *>())
        return ptr<Node>(result.as<UnaryopExpr *>());
    if (result.is<LValExpr *>())
        return ptr<Node>(result.as<LValExpr *>());
    if (result.is<Number *>())
        return ptr<Node>(result.as<Number *>());
    if (result.is<Stmt *>())
        return ptr<Node>(result.as<Stmt *>());
    if (result.is<VarDefStmt *>())
        return ptr<Node>(result.as<VarDefStmt *>());
    if (result.is<AssignStmt *>())
        return ptr<Node>(result.as<AssignStmt *>());
    if (result.is<FuncCallStmt *>())
        return ptr<Node>(result.as<FuncCallStmt *>());
    if (result.is<Block *>())
        return ptr<Node>(result.as<Block *>());
    if (result.is<IfStmt *>())
        return ptr<Node>(result.as<IfStmt *>());
    if (result.is<WhileStmt *>())
        return ptr<Node>(result.as<WhileStmt *>());
    return nullptr;
}
