#pragma once
#include <vector>
#include "MultiInstrBlock.h"

class LoopBlock : public Block {
    bool is_bgn_ = true;
    std::unique_ptr<MultiInstrBlock> multiInstrBlock_;

    void wrap();

public:
    LoopBlock(std::unique_ptr<MultiInstrBlock> &multiInstrBlock);
    bool has_nxt_instr(const unsigned char &cv);
    Instr get_nxt_instr(const unsigned char &cv);
    void rst();

    LoopBlock(const LoopBlock&) = delete;
    LoopBlock& operator=(const LoopBlock&) = delete;
    ~LoopBlock() = default;
};