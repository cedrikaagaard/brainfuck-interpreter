#include <stdexcept>
#include "../headers/LoopBlock.h"

LoopBlock::LoopBlock(std::unique_ptr<MultiInstrBlock> &multiInstrBlock) {
    this->multiInstrBlock_ = std::move(multiInstrBlock);
}

bool LoopBlock::has_nxt_instr(const unsigned char &cv) {
    if (is_bgn_ && cv == 0) {
        return false;
    }

    if (multiInstrBlock_->has_nxt_instr(cv))
        return true;

    return cv != 0;
}

Instr LoopBlock::get_nxt_instr(const unsigned char &cv) {
    if (is_bgn_ && cv == 0)
        throw std::out_of_range("No more instructions.");

    if (!multiInstrBlock_->has_nxt_instr(cv) && cv != 0)
        wrap();

    if (multiInstrBlock_->has_nxt_instr(cv)) {
        is_bgn_ = false;
        return multiInstrBlock_->get_nxt_instr(cv);
    }

    throw std::out_of_range("No more instructions.");
}

void LoopBlock::wrap() {
    is_bgn_ = true;
    multiInstrBlock_->rst();
}
