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

static std::unique_ptr

class ASTVisitor : public SillyBaseVisitor {
private:
    antlrcpp::Any RES = antlrcpp::Any(true);
    static std::unique_ptr<LLVMContext> TheContext;
    static std::unique_ptr<Module> TheMoudle;
    static std::unique_ptr<IRBuilder> Builder;
    static std::map<std::string,Value *> NamedValues;

public:
    antlrcpp::Any visitCompUnit(SillyParser::CompUnitContext *ctx) override;

    // antlrcpp::Any visitFuncCall(SillyParser::FuncCallContext *ctx) override;

    // antlrcpp::Any visitFuncCall(MyGrammarParser::FuncCallContext *ctx) override {
    //     std::string func_name = ctx->funcname->getText();
    //     std::cout << func_name << "'s result is : " << std::endl;
    //     std::string param = ctx->params->getText();
    //     std::cout << param << std::endl;
    // }
    antlrcpp::Any visitConstExp(SillyParser::ConstExpContext * ctx) override;
};