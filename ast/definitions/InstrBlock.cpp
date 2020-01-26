#include <stdexcept>
#include <iostream>
#include "../headers/InstrBlock.h"

InstrBlock::InstrBlock(Instr instr) : instr_(instr) {}

Instr InstrBlock::get_nxt_instr(const unsigned char &cv) {
    if (!has_nxt_instr_)
        throw std::out_of_range("No more instructions.");

    has_nxt_instr_ = false;
    return instr_;
}

bool InstrBlock::has_nxt_instr(const unsigned char &cv) {
    return has_nxt_instr_;
}

void InstrBlock::rst() {
    has_nxt_instr_ = true;
}
