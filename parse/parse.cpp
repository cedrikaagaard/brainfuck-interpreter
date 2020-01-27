#include <iostream>
#include "parse.h"

Parser::Parser(std::string program) : program_(program) {}

std::unique_ptr<InstrBlock>
Parser::parse_instr(std::string::iterator &it) {
    Instr instr;

    switch (*it) {
        case '>':
            instr = mvright;
            break;

        case '<':
            instr = mvleft;
            break;

        case '+':
            instr = incr;
            break;

        case '-':
            instr = decr;
            break;

        case '.':
            instr = out;
            break;

        case ',':
            instr = inp;
            break;

        default:
            instr = noop;
    }

    std::unique_ptr<InstrBlock> block(new InstrBlock(instr));
    it = std::next(it);

    return block;
}

std::unique_ptr<MultiInstrBlock>
Parser::parse_mult_instr(std::string::iterator &it) {
    std::unique_ptr<MultiInstrBlock> instrs(new MultiInstrBlock());

    while (it != program_.end()) {

        if (*it == '[') {
            it = std::next(it);

            std::unique_ptr<Block> nestedLoopBlock = parse_loop(it);
            instrs->add_block(nestedLoopBlock);
        }

        else {
            std::unique_ptr<Block> block = parse_instr(it);
            instrs->add_block(block);
        }
    }

    return instrs;
}


std::unique_ptr<LoopBlock> Parser::parse_loop(std::string::iterator &it) {
    std::unique_ptr<MultiInstrBlock> instrs(new MultiInstrBlock());

    while (true) {
        if (it == program_.end()) {
            throw new std::invalid_argument("Unexpected token");
        }

        else if (*it == '[') {
            it = std::next(it);

            std::unique_ptr<Block> nestedLoopBlock = parse_loop(it);
            instrs->add_block(nestedLoopBlock);
        }

        else if (*it == ']') {
            it = std::next(it);
            break;
        }

        else {
            std::unique_ptr<Block> block = parse_instr(it);
            instrs->add_block(block);
        }
    }

    std::unique_ptr<LoopBlock> loopBlock(new LoopBlock(instrs));

    return loopBlock;
}


std::unique_ptr<MultiInstrBlock> Parser::parse() {
    std::string::iterator it = program_.begin();
    return parse_mult_instr(it);
}
