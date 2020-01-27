#include <iostream>
#include <bits/unique_ptr.h>
#include <fstream>
#include "Memory.h"
#include "ast/headers/Instr.h"
#include "ast/headers/Block.h"
#include "ast/headers/InstrBlock.h"
#include "ast/headers/MultiInstrBlock.h"
#include "ast/headers/LoopBlock.h"
#include "parse/parse.h"
#include "exeute/execute.h"

std::string read_file(const std::string &file_path) {
    std::ifstream s(file_path);
    std::string str((std::istreambuf_iterator<char>(s)),
                    std::istreambuf_iterator<char>());

    return str;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "No brainfuck file specified, Aborting." << std::endl;
        return 0;
    }

    std::string inp_file = argv[1];
    std::string file_data = read_file(inp_file);

    Parser parser(file_data);
    auto p = parser.parse();
    Memory memory(2048);
    execute(memory, p);
}
