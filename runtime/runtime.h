//
// Created by ggssh on 2021/10/9 0009.
//

#ifndef SILLYLANG_RUNTIME_H
#define SILLYLANG_RUNTIME_H

#include <vector>
#include <tuple>

#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>

class RuntimeInfo {
    llvm::GlobalVariable *input_var;
    llvm::GlobalVariable *output_var;
    llvm::Function *input_func;
    llvm::Function *output_func;

public:
    RuntimeInfo(llvm::Module *module);
    std::vector<std::tuple<std::string, llvm::GlobalValue *, bool, bool, bool>> get_language_symbols();

    std::vector<std::tuple<std::string, void *>> get_runtime_symbols();
};

#endif // SILLYLANG_RUNTIME_H
