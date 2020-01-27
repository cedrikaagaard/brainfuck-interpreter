#include <iostream>
#include <bits/unique_ptr.h>
#include "Memory.h"
#include "ast/headers/Instr.h"
#include "ast/headers/Block.h"
#include "ast/headers/InstrBlock.h"
#include "ast/headers/MultiInstrBlock.h"
#include "ast/headers/LoopBlock.h"
#include "parse/parse.h"


std::unique_ptr<MultiInstrBlock> get_mib() {
    std::unique_ptr<MultiInstrBlock> mib(new MultiInstrBlock());
    return mib;
}


int main() {
    Parser parser("+[][--][++]");
    auto p = parser.parse();
}