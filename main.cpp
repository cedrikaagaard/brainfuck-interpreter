#include <iostream>
#include <bits/unique_ptr.h>
#include "Memory.h"
#include "block/headers/Instr.h"
#include "block/headers/Block.h"
#include "block/headers/InstrBlock.h"
#include "block/headers/MultiInstrBlock.h"
#include "block/headers/LoopBlock.h"


std::unique_ptr<MultiInstrBlock> get_mib() {
    std::unique_ptr<MultiInstrBlock> mib(new MultiInstrBlock());
    return mib;
}


int main() {
    auto mib = get_mib();


    for (int i = 0; i < 3; ++i) {
        std::unique_ptr<Block> bPtr(new InstrBlock(incr));
        mib->add_block(bPtr);
    }

    for (int i = 0; i < 2; ++i) {
        std::unique_ptr<Block> bPtr(new InstrBlock(mvright));
        mib->add_block(bPtr);
    }


    LoopBlock lb(mib);

    int i = 25;

    while (lb.has_nxt_instr(i)) {
        std::cout << lb.get_nxt_instr(i) << std::endl;

        i--;

        if (i < 0)
            i = 0;
    }
}