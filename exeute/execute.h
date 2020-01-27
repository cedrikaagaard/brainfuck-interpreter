#pragma once

#include <iostream>
#include "../Memory.h"
#include "../ast/headers/MultiInstrBlock.h"

void execute(Memory &mem, std::unique_ptr<MultiInstrBlock> &instrs);