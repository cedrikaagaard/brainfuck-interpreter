#pragma once
#include "Instr.h"

class Block {
public:
    virtual bool has_nxt_instr(const unsigned char &cv) = 0;
    virtual Instr get_nxt_instr(const unsigned char &cv) = 0;
    virtual void rst() = 0;
};