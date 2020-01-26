#include "Memory.h"

Memory::Memory(std::size_t ms) : mem_size(ms), mem_repr(ms, 0) {
    p_cntr = mem_repr.begin();
}

void Memory::mv_right() {
    ++p_cntr;
}

void Memory::mv_left() {
    --p_cntr;
}

void Memory::incr() {
    ++(*p_cntr);
}

void Memory::decr() {
    --(*p_cntr);
}

unsigned char Memory::get_val() {
    return *p_cntr;
}

void Memory::set_val(unsigned char new_val) {
    *p_cntr = new_val;
}
