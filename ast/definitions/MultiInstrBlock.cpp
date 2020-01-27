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
    std::vector<std::unique_ptr<Block>>::iterator nb = c_block_;

    while (nb != blocks_.end()) {
        if ((*nb)->has_nxt_instr(cv))
            return true;

        nb = std::next(nb);
    }

    return false;
}

Instr MultiInstrBlock::get_nxt_instr(const unsigned char &cv) {
    while (c_block_ != blocks_.end()) {
        if ((*c_block_)->has_nxt_instr(cv)) {
            Instr i = (*c_block_)->get_nxt_instr(cv);
            return i;
        }

        c_block_ = std::next(c_block_);
    }

    throw std::out_of_range("No more instructions.");
}
