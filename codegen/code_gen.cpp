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
//    auto val = lookup_variable(node->name);
//
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
    if (constexpr_expected) {
        node->lhs->accept(*this);
        auto lval = const_result;
        node->rhs->accept(*this);
        auto rval = const_result;
        switch (node->op) {
            case binop::ADD:
                const_result = lval + rval;
                break;
            case binop::SUB:
                const_result = lval - rval;
                break;
            case binop::MUL:
                const_result = lval * rval;
                break;
            case binop::MOD:
                if (!rval)
                    err.error(node->line, node->pos, "module zero is undefined");
                const_result = lval % rval;
                break;
            case binop::DIV:
                if (!rval)
                    err.error(node->line, node->pos, "divide zero is undefined");
                const_result = lval / rval;
        }
    } else {
        node->lhs->accept(*this);
        auto lval = value_result;
        node->rhs->accept(*this);
        auto rval = value_result;
        switch (node->op) {
            case binop::ADD:
                value_result = builder.CreateAdd(lval, rval, "addtmp");
                break;
            case binop::SUB:
                value_result = builder.CreateSub(lval, rval, "subtmp");
                break;
            case binop::MUL:
                value_result = builder.CreateMul(lval, rval, "multmp");
                break;
            case binop::DIV:
                value_result = builder.CreateSDiv(lval, rval, "divtmp");
                break;
            case binop::MOD:
                value_result = builder.CreateSRem(lval, rval, "modtmp");
                break;
        }
    }
}

void CodeGenerator::visit(VarDefStmt *node) {
    if (variables.front().count(node->name)) {
        std::string error_info = "variable \"" + node->name + "\" has already declared.";
        err.error(node->line, node->pos, error_info);
        error_flag = true;
        return;
    }
    // 单个变量
    if (!node->arr_len) {
        const_result = 0;// 未在定义时赋值则默认为0
        Value *value;
        // 全局变量定义
        if (in_global) {
            constexpr_expected = true;
            if (!node->initializers.empty())
                node->initializers[0]->accept(*this);
            value = new GlobalVariable(*module,
                                       Type::getInt32Ty(module->getContext()),
                                       node->is_constant,
                                       GlobalValue::ExternalLinkage,
                                       ConstantInt::get(Type::getInt32Ty(module->getContext()), const_result),
                                       node->name);
        }
            // 局部变量定义
        else {
            constexpr_expected = false;
            value = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, node->name);
            if (!node->initializers.empty()) {
                node->initializers[0]->accept(*this);
                builder.CreateStore(value_result, value);
            }
        }
        declare_variable(node->name, value, node->is_constant, false);
    }
        // 数组变量定义
    else {
        constexpr_expected = true;
        node->arr_len->accept(*this);// 计算数组长度
        unsigned array_len = const_result;
        unsigned init_len = node->initializers.size();

        if (array_len < 0) {
            // todo
        }
        if (init_len > array_len) {
            // todo
        }
        Value *array;
        // 全局数组变量定义
        if (in_global) {
            // 初始化
            std::vector<Constant *> init_array;
            for (int len = 0; len < array_len; ++len) {
                // 初始化赋值部分
                if (len < init_len) {
                    node->initializers[len]->accept(*this);
                    init_array.push_back(ConstantInt::get(Type::getInt32Ty(context), const_result));
                }
                    // 未在初始化时赋值的部分
                else {
                    init_array.push_back(ConstantInt::get(Type::getInt32Ty(context), 0));
                }
            }
            array = new GlobalVariable(*module,
                                       ArrayType::get(Type::getInt32Ty(context), array_len),
                                       node->is_constant,
                                       GlobalValue::ExternalLinkage,
                                       ConstantArray::get(ArrayType::get(Type::getInt32Ty(context), array_len),
                                                          init_array),
                                       node->name,
                                       nullptr,
                                       GlobalValue::NotThreadLocal
            );
        }
            // 局部数组变量定义
        else {
            constexpr_expected = false;
            array = builder.CreateAlloca(ArrayType::get(Type::getInt32Ty(context), array_len), nullptr, node->name);
            Value *element;// 数组元素地址
            std::vector<Value *> index;
            index.push_back((Value *) ConstantInt::get(Type::getInt32Ty(context), 0));
            for (int len = 0; len < array_len && !node->initializers.empty(); ++len) {
                // get index
                index.push_back((Value *) ConstantInt::get(Type::getInt32Ty(context), len));
                element = builder.CreateGEP(array, index);
                index.pop_back();
                if (len < init_len) {
                    node->initializers[len]->accept(*this);
                    builder.CreateStore(value_result, element);
                } else {
                    builder.CreateStore(ConstantInt::get(Type::getInt32Ty(context), 0), element);
                }
            }
        }

        declare_variable(node->name, array, node->is_constant, true);
    }
}

void CodeGenerator::visit(AssignStmt *node) {
    constexpr_expected = false;
    lval_as_rval = false;
    node->target->accept(*this);
    auto target = value_result;
    constexpr_expected = false;
    lval_as_rval = false;
    node->value->accept(*this);
    auto value = value_result;
    // 将value存入target
    builder.CreateStore(value, target);
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
    if (!constexpr_expected)
        value_result = ConstantInt::get(Type::getInt32Ty(context), node->number);
    else
        const_result = node->number;
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
    node->rhs->accept(*this);
//    auto rval =
    if (node->op == unaryop::SUB) {
        if (constexpr_expected) {
            const_result = -constexpr_expected;
        } else {
            Value *const_i32_0 = ConstantInt::get(Type::getInt32Ty(context), 0);
            value_result = builder.CreateSub(const_i32_0, value_result);
        }
    }
    // 如果前面的符号为+则不需要进行处理
}

void CodeGenerator::visit(EmptyStmt *node) {
    // 什么也不用做
}

void CodeGenerator::visit(Cond *node) {
    constexpr_expected = false;
    node->lhs->accept(*this);
    auto lval = value_result;
    node->rhs->accept(*this);
    auto rval = value_result;
    Value *result;
    switch (node->op) {
        case relop::EQ:
            result = builder.CreateICmpEQ(lval, rval, "eq_cmp");
            break;
        case relop::NE:
            result = builder.CreateICmpNE(lval, rval, "ne_cmp");
            break;
        case relop::LT:
            result = builder.CreateICmpSLT(lval, rval, "lt_cmp");
            break;
        case relop::LE:
            result = builder.CreateICmpSLE(lval, rval, "le_cmp");
            break;
        case relop::GT:
            result = builder.CreateICmpSGT(lval, rval, "gt_cmp");
            break;
        case relop::GE:
            result = builder.CreateICmpSGE(lval, rval, "ge_cmp");
            break;
    }
    value_result = result;
}
