#pragma once

#include <vector>
#include <bits/unique_ptr.h>
#include "Block.h"
#include "InstrBlock.h"

class MultiInstrBlock {
    std::vector<std::unique_ptr<Block>> blocks_;
    std::vector<std::unique_ptr<Block>>::iterator c_block_;

public:
    MultiInstrBlock();
    void add_block(std::unique_ptr<Block> &b);
    bool has_nxt_instr(const unsigned char &cv);
    Instr get_nxt_instr(const unsigned char &cv);
    void rst();

    MultiInstrBlock(const MultiInstrBlock&) = delete;
    MultiInstrBlock& operator=(const MultiInstrBlock&) = delete;
    ~MultiInstrBlock() = default;
};