//
// Created by ggssh on 2021/9/30.
//

#include "ast_builder.h"
using namespace silly::ast;

antlrcpp::Any ASTBuilder::visitCompUnit(SillyParser::CompUnitContext *ctx) {
    auto result = new CompUnit;
    result->line = 1;
    result->pos = 0;
    auto decls = ctx->decl();
    auto funcdefs = ctx->funcDef();
    int decls_i = 0, funcdefs_i = 0;
    for (auto child : ctx->children) {
        if (antlrcpp::is<SillyParser::DeclContext *>(child)) {
            auto decllist = antlr4::tree::AbstractParseTreeVisitor::visit(decls[decls_i++]).as<ptr_list<VarDefStmt>>();
            for (int i = 0; i < decllist.size(); ++i) {
                result->global_defs.push_back(decllist[i]);
            }
        }
    }
    //    return SillyBaseVisitor::visitCompUnit(ctx);
    printf("Success!");
    return static_cast<CompUnit *>(result);
}
antlrcpp::Any ASTBuilder::visitDecl(SillyParser::DeclContext *ctx) {
    // decl:constDecl
    if (ctx->constDecl())
        return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->constDecl());
    // decl:varDecl
    if (ctx->varDecl())
        return antlr4::tree::AbstractParseTreeVisitor::visit(ctx->varDecl());
    //    return SillyBaseVisitor::visitDecl(ctx);
}
antlrcpp::Any ASTBuilder::visitConstDecl(SillyParser::ConstDeclContext *ctx) {
    //    printf("enter visitConstDecl");
    ptr_list<VarDefStmt> result;
    auto vardefs = ctx->constDef();
    for (int i = 0; i < vardefs.size(); ++i) {
        ptr<VarDefStmt> temp;
        temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(vardefs[i]).as<VarDefStmt *>());
        result.push_back(temp);
    }
    return static_cast<ptr_list<VarDefStmt>>(result);
    //    return SillyBaseVisitor::visitConstDecl(ctx);
}
antlrcpp::Any ASTBuilder::visitConstDef(SillyParser::ConstDefContext *ctx) {
    auto result = new VarDefStmt;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_constant = true;
    result->name = std::string(ctx->IDENTIFIER()->getSymbol()->getText());
    result->initializers.clear();
    auto exprs = ctx->expr();
    int comma_count = ctx->COMMA().size();
    // constDef : IDENTIFIER ASSIGN expr
    if (!ctx->LBRACK()) {
        result->arr_len.reset();
        result->initializers.resize(1);
        result->initializers[0].reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
    } else if (comma_count == exprs.size() - 2) {
        result->arr_len.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
        for (int i = 1; i < exprs.size(); ++i) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->initializers.push_back(temp);
        }
    } else {
        // such as a[] = {}, just handle it as single variable
        if (comma_count == 0) {
            result->arr_len.reset();
        } else {
            Interger *temp = new Interger;
            temp->line = ctx->getStart()->getLine();
            temp->pos = ctx->LBRACK()->getSymbol()->getCharPositionInLine() + 1;
            temp->number = comma_count + 1;
            result->arr_len.reset(temp);
        }

        for (int i = 0; i < exprs.size(); ++i) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->initializers.push_back(temp);
        }
    }
    //    return SillyBaseVisitor::visitConstDef(ctx);
    return static_cast<VarDefStmt *>(result);
}
antlrcpp::Any ASTBuilder::visitVarDecl(SillyParser::VarDeclContext *ctx) {
    ptr_list<VarDefStmt> result;
    auto vardefs = ctx->varDef();
    for (int i = 0; i < vardefs.size(); ++i) {
        ptr<VarDefStmt> temp;
        temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(vardefs[i]).as<VarDefStmt *>());
        result.push_back(temp);
    }
    return static_cast<ptr_list<VarDefStmt>>(result);
    //    auto result = new Stmt;
    //    return SillyBaseVisitor::visitVarDecl(ctx);
}
antlrcpp::Any ASTBuilder::visitVarDef(SillyParser::VarDefContext *ctx) {
    //    int v1, v2 = 3;
    //    int a1[3];
    //    int a2[3] = {1, 2};
    //    int a3[] = {1, 2, 3, 4};
    //    const int c1 = 3, a4[2] = {1, 2};
    auto result = new VarDefStmt;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_constant = false;
    result->name = std::string(ctx->IDENTIFIER()->getSymbol()->getText());
    result->initializers.clear();
    // get the num of comma to handle the last state
    int comma_count = ctx->COMMA().size();
    auto exprs = ctx->expr();
    // varDef : IDENTIFIER
    if (exprs.size() == 0) {
        result->arr_len.reset();
        result->initializers.clear();
    }
    // varDef : IDENTIFIER ASSIGN expr
    else if (!ctx->LBRACK()) {
        result->arr_len.reset();
        result->initializers.resize(1);
        result->initializers[0].reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
    }
    // varDef : IDENTIFIER LBRACK expr RBRACE
    else if (!ctx->LBRACE()) {
        result->arr_len.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
        result->initializers.clear();
    }
    // varDef : IDENTIFIER LBRACK (expr)? RBRACK ASSIGN LBRACE expr (COMMA expr)* RBRACE
    // varDef : IDENTIFIER LBRACK expr RBRACK ASSIGN LBRACE expr (COMMA expr)* RBRACE
    else if (comma_count == exprs.size() - 2) {
        result->arr_len.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[0]).as<Expr *>());
        result->initializers.clear();
        for (int i = 1; i < exprs.size(); i++) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->initializers.push_back(temp);
        }
    }
    // [nothing] need compiler to infer
    else {
        // such as a[] = {}, just handle it as single variable
        if (comma_count == 0) {
            result->arr_len.reset();
        } else {
            Interger *temp = new Interger;
            temp->line = ctx->getStart()->getLine();
            temp->pos = ctx->LBRACK()->getSymbol()->getCharPositionInLine() + 1;
            temp->number = comma_count + 1;
            result->arr_len.reset(temp);
        }

        for (int i = 0; i < exprs.size(); ++i) {
            std::shared_ptr<Expr> temp;
            temp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(exprs[i]).as<Expr *>());
            result->initializers.push_back(temp);
        }
    }
    return static_cast<VarDefStmt *>(result);
    // return SillyBaseVisitor::visitVarDef(ctx);
}
antlrcpp::Any ASTBuilder::visitFuncDef(SillyParser::FuncDefContext *ctx) {
    auto result = new FuncDef;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    // Function name
    result->name = ctx->IDENTIFIER()->getSymbol()->getText();
    auto block = ctx->block();
    // handle function block
    result->body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(block).as<Block *>());

    return static_cast<GlobalDef *>(result);
    //    return SillyBaseVisitor::visitFuncDef(ctx);
}
antlrcpp::Any ASTBuilder::visitBlock(SillyParser::BlockContext *ctx) {
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
    for (auto child : ctx->children) {
        std::shared_ptr<Stmt> tmp;
        if (antlrcpp::is<SillyParser::DeclContext *>(child)) {
            auto decllist = antlr4::tree::AbstractParseTreeVisitor::visit(ds[decls_count++]).as<ptr_list<VarDefStmt>>();
            for (int i = 0; i < decllist.size(); i++) {
                result->body.push_back(decllist[i]);
            }
        } else if (antlrcpp::is<SillyParser::StmtContext *>(child)) {
            tmp.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ss[stmts_count++]).as<Stmt *>());
            result->body.push_back(tmp);
        }
    }
    return static_cast<Stmt *>(result);
}
antlrcpp::Any ASTBuilder::visitStmt(SillyParser::StmtContext *ctx) {
    // stmt : lval ASSIGN expr SEMICOLON
    if (ctx->lVal()) {
        auto result = new AssignStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->target.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->lVal()).as<LValExpr *>());
        result->value.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->expr()).as<Expr *>());
        return static_cast<Stmt *>(result);
    }
    // stmt : block
    else if (ctx->block()) {
        auto result = new Block;
        result = antlr4::tree::AbstractParseTreeVisitor::visit(ctx->block());
        return static_cast<Stmt *>(result);
    }
    // stmt : IDENTIFIER LPAREN RPAREN SEMICOLON
    else if (ctx->IDENTIFIER()) {
        auto result = new FuncCallStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->name = std::string(ctx->IDENTIFIER()->getSymbol()->getText());
        return static_cast<Stmt *>(result);
    }
    // stmt : IF LPAREN cond RPAREN stmt (ELSE stmt)?
    else if (ctx->IF()) {
        auto result = new IfStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond()).as<Cond *>());
        result->then_body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->stmt(0)).as<Stmt *>());
        if (ctx->ELSE()) {
            result->else_body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->stmt(1)).as<Stmt *>());
        } else {
            result->else_body.reset();
        }
        return static_cast<Stmt *>(result);
    }
    // stmt : WHILE LPAREN cond RPAREN stmt
    else if (ctx->WHILE()) {
        auto result = new WhileStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->cond()).as<Cond *>());
        result->body.reset(antlr4::tree::AbstractParseTreeVisitor::visit(ctx->stmt(0)).as<Stmt *>());
        return static_cast<Stmt *>(result);
    }
    // stmt : SEMICOLON
    else {
        auto result = new EmptyStmt;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        return static_cast<Stmt *>(result);
    }
}
antlrcpp::Any ASTBuilder::visitLVal(SillyParser::LValContext *ctx) {
    auto result = new LValExpr;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->IDENTIFIER()->getSymbol()->getText();
    //    result->name = ctx->IDENTIFIER()->getText();
    if (ctx->expr()) {
        auto expressions = ctx->expr();
        result->array_index.reset(antlr4::tree::AbstractParseTreeVisitor::visit(expressions).as<Expr *>());
    } else {
        result->array_index = nullptr;
    }
    return static_cast<LValExpr *>(result);
    //    return SillyBaseVisitor::visitLVal(ctx);
}
antlrcpp::Any ASTBuilder::visitCond(SillyParser::CondContext *ctx) {
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
    return static_cast<Cond *>(result);
    //    return SillyBaseVisitor::visitCond(ctx);
}
antlrcpp::Any ASTBuilder::visitExpr(SillyParser::ExprContext *ctx) {
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
        auto result = new Interger;
        auto number = ctx->NUMBER();
        // If `Number` exists as a child, we can say it's a literal integer expression.
        result->line = number->getSymbol()->getLine();
        result->pos = number->getSymbol()->getCharPositionInLine();
        auto text = number->getSymbol()->getText();
        // consider to enable 0x
        result->number = std::stoi(text, nullptr, 10);
        return static_cast<Expr *>(result);
    }
}
silly::ast::ptr<silly::ast::Node> ASTBuilder::operator()(antlr4::tree::ParseTree *ctx) {
    auto result = antlr4::tree::AbstractParseTreeVisitor::visit(ctx);
    if (result.is<Node *>())
        return ptr<Node>(result.as<Node *>());
    //    return ast::ptr<ast::Node>();
    if (result.is<CompUnit *>())
        return ptr<Node>(result.as<CompUnit *>());
    if (result.is<GlobalDef *>())
        return ptr<Node>(result.as<GlobalDef *>());
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
    if (result.is<Interger *>())
        return ptr<Node>(result.as<Interger *>());
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
