#pragma once

#include "Instr.h"
#include "Block.h"

class InstrBlock : public Block {
    bool has_nxt_instr_ = true;
    Instr instr_;

public:
    InstrBlock(Instr instr);
    bool has_nxt_instr(const unsigned char &cv);
    Instr get_nxt_instr(const unsigned char &cv);
    void rst();
};