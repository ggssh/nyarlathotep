#include <iostream>
#include <fstream>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h> // 添加目标机器的支持
#include <llvm/Support/Host.h> // getDefaultTargetTriple
#include <llvm/Support/FileSystem.h>

#include "antlr4-runtime.h"
#include "NyarLexer.h"
#include "NyarParser.h"

#include "ast_builder.h"
#include "code_gen.h"
#include "error_reporter.h"

using namespace antlr4;
using namespace antlrcpp;
using namespace nyar::ast;
using namespace tree;
using namespace llvm::sys;

int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    NyarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    NyarParser parser(&tokens);
    auto *tree = parser.compUnit();
    // 生成抽象语法树
    ASTBuilder astBuilder;
    auto ast = astBuilder(tree);
    LLVMContext context;
    nyar::ErrorReporter err(std::cerr);
    CodeGenerator codegen(context, err);
    codegen.build("nyar", ast);
    auto module = codegen.get_module();
    module->print(outs(), nullptr);
//    std::ofstream out("hhh.txt");
//    out<<"nihao"<<std::endl;
    // 添加目标机器的支持
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = sys::getDefaultTargetTriple();
    module->setTargetTriple(TargetTriple);
    outs() << "generating target code(" << TargetTriple << ")...\n";
    std::string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);
    if (!Target) {
        errs() << Error;
        return 1;
    }
    auto CPU = "generic";
    auto Features = "";
    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TheTargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    module->setDataLayout(TheTargetMachine->createDataLayout());
    auto Filename = "output.o";
    std::error_code EC;
    raw_fd_ostream dest(Filename, EC, sys::fs::F_None);
    if (EC) {
        errs() << "Could not open file:" << EC.message();
        return 1;
    }
    legacy::PassManager pass;
    auto FileType = CodeGenFileType::CGFT_AssemblyFile;
    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        errs() << "TheTargetMachine can't emit a file of this type";
        return 1;
    }
    pass.run(*module);
    dest.flush();
    outs() << "Wrote " << Filename << "\n";
    return 0;
}