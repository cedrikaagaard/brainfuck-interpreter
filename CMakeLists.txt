cmake_minimum_required(VERSION 3.13)
project(brainfuck)

set(CMAKE_CXX_STANDARD 11)

add_executable(brainfuck main.cpp Memory.cpp Memory.h block/headers/Instr.h block/definitions/Block.cpp block/headers/Block.h block/definitions/InstrBlock.cpp block/headers/InstrBlock.h block/definitions/MultiInstrBlock.cpp block/headers/MultiInstrBlock.h block/definitions/LoopBlock.cpp block/headers/LoopBlock.h)