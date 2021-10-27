//
// Created by ggssh on 2021/10/9 0009.
//

#include "code_gen.h"
#include <vector>

using namespace llvm;


void CodeGenerator::visit(CompUnit *node) {
    in_global = true;
    //随机初始化避免段错误
    value_result = ConstantInt::get(Type::getInt32Ty(context), 0);
    bb_count = 1;
    for (const auto &ptr_def: node->global_defs) {
        ptr_def->accept(*this);
    }
    printf("codegen success!\n");
}

void CodeGenerator::visit(FuncDef *node) {
    in_global = false;
    if (functions.find(node->name) == functions.end()) {
        // todo 错误处理
    }
    FunctionType *FT = FunctionType::get(Type::getVoidTy(context), {}, false);
    current_funciton = Function::Create(FT, GlobalValue::ExternalLinkage, node->name, module.get());
    functions[node->name] = current_funciton;
    auto func_entry = BasicBlock::Create(context, "func_entry_" + node->name, current_funciton);
    builder.SetInsertPoint(func_entry);
    node->body->accept(*this);
    // return
    builder.CreateRetVoid();
    builder.ClearInsertionPoint();
    in_global = true;
}

void CodeGenerator::visit(FuncCallStmt *node) {
    if (functions.find(node->name) == functions.end()) {
//        std::string error_info = "function " + node->name + "() is not declared";
//        err.error(node->line, node->pos, error_info);
//        error_flag = true;
//        return;
    }
    auto func = functions[node->name];
    builder.CreateCall(func);
}

void CodeGenerator::visit(LValExpr *node) {
}

void CodeGenerator::visit(Block *node) {
    // 初始化一个block
    enter_scope();
    nyar::ast::ptr_list<Stmt> body = node->body;
    for (const auto &item: body) {
        item->accept(*this);
    }
    exit_scope();
}

void CodeGenerator::visit(BinopExpr *node) {
}

void CodeGenerator::visit(VarDefStmt *node) {
}

void CodeGenerator::visit(AssignStmt *node) {
}

void CodeGenerator::visit(IfStmt *node) {
    // if then else
    if (node->else_body) {
        auto pred_block = BasicBlock::Create(context, "if_pred_b" + std::to_string(bb_count++), current_funciton);
        auto then_block = BasicBlock::Create(context, "if_then_b" + std::to_string(bb_count++), current_funciton);
        auto else_block = BasicBlock::Create(context, "if_else_b" + std::to_string(bb_count++), current_funciton);
        auto next_block = BasicBlock::Create(context, "if_next_b" + std::to_string(bb_count++), current_funciton);
        builder.CreateBr(pred_block);

        // pred_block
        builder.SetInsertPoint(pred_block);
        node->pred->accept(*this);
        builder.CreateCondBr(value_result, then_block, else_block);

        // then_block
        builder.SetInsertPoint(then_block);
        node->then_body->accept(*this);
        builder.CreateBr(next_block);// 跳转到退出if语句后要执行的语句

        // else_block
        builder.SetInsertPoint(else_block);
        node->else_body->accept(*this);
        builder.CreateBr(next_block);

        // next_block
        builder.SetInsertPoint(next_block);
    }
        // if then
    else {
        auto pred_block = BasicBlock::Create(context, "if_pred_b" + std::to_string(bb_count++), current_funciton);
        auto then_block = BasicBlock::Create(context, "if_then_b" + std::to_string(bb_count++), current_funciton);
        auto next_block = BasicBlock::Create(context, "if_next_b" + std::to_string(bb_count++), current_funciton);

        // pred_block
        builder.CreateBr(pred_block);
        builder.SetInsertPoint(pred_block);
        node->pred->accept(*this);
        builder.CreateCondBr(value_result, then_block, next_block);// value_result为false直接跳转到if语句结束

        // then_block
        builder.SetInsertPoint(then_block);
        node->then_body->accept(*this);
        builder.CreateBr(next_block);

        // next_block
        builder.SetInsertPoint(next_block);
    }
}

void CodeGenerator::visit(Interger *node) {
}

void CodeGenerator::visit(WhileStmt *node) {
    auto pred_block = BasicBlock::Create(context, "while_pred_b" + std::to_string(bb_count++), current_funciton);
    auto true_block = BasicBlock::Create(context, "while_true_b" + std::to_string(bb_count++), current_funciton);
    auto next_block = BasicBlock::Create(context, "while_next_b" + std::to_string(bb_count++), current_funciton);

    builder.CreateBr(pred_block);
    // pre_block
    builder.SetInsertPoint(pred_block);
    node->pred->accept(*this);
//    builder.CreateCondBr(pred_block, true_block, next_block);
    builder.CreateCondBr(value_result, true_block, next_block);
    // true_block
    builder.SetInsertPoint(true_block);
    node->body->accept(*this);
    builder.CreateBr(pred_block);
    // next_block
    builder.SetInsertPoint(next_block);
}

void CodeGenerator::visit(UnaryopExpr *node) {
}

void CodeGenerator::visit(EmptyStmt *node) {
    // 什么也不用做
}

void CodeGenerator::visit(Cond *node) {
}
