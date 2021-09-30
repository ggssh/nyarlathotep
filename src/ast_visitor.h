#include "SillyBaseVisitor.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Constant.h"
#include <memory>

using namespace llvm;

// static std::unique_ptr

class ASTVisitor : public SillyBaseVisitor {
private:
    antlrcpp::Any RES = antlrcpp::Any(true);
    static std::unique_ptr<LLVMContext> TheContext;
    static std::unique_ptr<Module> TheMoudle;
    static std::unique_ptr<IRBuilder<LLVMContext>> Builder;
    static std::map<std::string, Value *> NamedValues;

public:
    antlrcpp::Any visitCompUnit(SillyParser::CompUnitContext *ctx) override;
    antlrcpp::Any visitFuncType(SillyParser::FuncTypeContext *ctx) override;
    antlrcpp::Any visitTerminal(antlr4::tree::TerminalNode *node) override;
    antlrcpp::Any visitChildren(antlr4::tree::ParseTree *node) override;
    antlrcpp::Any visitBType(SillyParser::BTypeContext *ctx) override;
    antlrcpp::Any visitNumber(SillyParser::NumberContext *ctx) override;
    antlrcpp::Any visitFuncDef(SillyParser::FuncDefContext *ctx) override;
    antlrcpp::Any visitFuncFParams(SillyParser::FuncFParamsContext *ctx) override;
    antlrcpp::Any visitFuncFParam(SillyParser::FuncFParamContext *ctx) override;
};