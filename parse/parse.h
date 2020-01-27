#pragma once

#include <bits/unique_ptr.h>
#include "../ast/headers/InstrBlock.h"
#include "../ast/headers/MultiInstrBlock.h"
#include "../ast/headers/LoopBlock.h"


class Parser {
    std::string program_;
    std::unique_ptr<InstrBlock> parse_instr(std::string::iterator &it);

    std::unique_ptr<MultiInstrBlock>
        parse_mult_instr(std::string::iterator &it);

    std::unique_ptr<LoopBlock> parse_loop(std::string::iterator &it);

public:
    std::unique_ptr<MultiInstrBlock> parse();
    Parser(std::string program);
};



