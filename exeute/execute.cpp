#include "execute.h"

void execute(Memory &mem, std::unique_ptr<MultiInstrBlock> &instrs) {
    while (instrs->has_nxt_instr(mem.get_val())) {
        Instr instr = instrs->get_nxt_instr(mem.get_val());

        switch (instr) {
            case mvright:
                mem.mv_right();
                break;

            case mvleft:
                mem.mv_left();
                break;

            case incr:
                mem.incr();
                break;

            case decr:
                mem.decr();
                break;

            case out:
                putchar(mem.get_val());
                break;

            case inp:
                unsigned char in = (unsigned char) getchar();
                mem.set_val(in);
                break;
        }
    }
}
