cmake_minimum_required(VERSION 3.13)
project(brainfuck)

set(CMAKE_CXX_STANDARD 11)

add_executable(brainfuck main.cpp Memory.cpp Memory.h ast/headers/Instr.h ast/definitions/Block.cpp ast/headers/Block.h ast/definitions/InstrBlock.cpp ast/headers/InstrBlock.h ast/definitions/MultiInstrBlock.cpp ast/headers/MultiInstrBlock.h ast/definitions/LoopBlock.cpp ast/headers/LoopBlock.h parse/parse.cpp parse/parse.h exeute/execute.cpp exeute/execute.h)