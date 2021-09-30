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
};