#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

int main() {
    // 1. Core LLVM objects
    LLVMContext context;
    Module module("my_module", context);
    IRBuilder<> builder(context);

    // 2. Create function: int main()
    FunctionType *funcType = FunctionType::get(builder.getInt32Ty(), false);
    Function *mainFunc = Function::Create(
        funcType,
        Function::ExternalLinkage,
        "main",
        module
    );

    // 3. Create entry block
    BasicBlock *entry = BasicBlock::Create(context, "entry", mainFunc);
    builder.SetInsertPoint(entry);

    // 4. return 42;
    Value *retVal = ConstantInt::get(builder.getInt32Ty(), 42);
    builder.CreateRet(retVal);

    // 5. Print IR
    module.print(outs(), nullptr);

    return 0;
}
