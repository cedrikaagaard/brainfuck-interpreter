#include <stdexcept>
#include <iostream>
#include "../headers/MultiInstrBlock.h"

MultiInstrBlock::MultiInstrBlock() {
    c_block_ = blocks_.begin();
}

void MultiInstrBlock::rst() {
    for (const auto &b : blocks_)
        b->rst();

    c_block_ = blocks_.begin();
}

void MultiInstrBlock::add_block(std::unique_ptr<Block> &block) {
    blocks_.emplace_back(std::move(block));
    c_block_ = blocks_.begin();
}

bool MultiInstrBlock::has_nxt_instr(const unsigned char &cv) {
    if (c_block_ == blocks_.end()) {
        return false;
    }

    return (*c_block_)->has_nxt_instr(cv);
}

Instr MultiInstrBlock::get_nxt_instr(const unsigned char &cv) {
    if (c_block_ == blocks_.end())
        throw std::out_of_range("No more instructions.");

    Instr i = (*c_block_)->get_nxt_instr(cv);
    c_block_ = std::next(c_block_);
    return i;
}
