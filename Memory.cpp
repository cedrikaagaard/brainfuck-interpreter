#include "Memory.h"

Memory::Memory(std::size_t ms) : mem_size_(ms), mem_repr_(ms, 0) {
    p_cntr_ = mem_repr_.begin();
}

void Memory::mv_right() {
    ++p_cntr_;

    if (p_cntr_ == mem_repr_.end())
        p_cntr_ = mem_repr_.begin();
}

void Memory::mv_left() {
    if (p_cntr_ == mem_repr_.begin())
        p_cntr_ = mem_repr_.end();

    --p_cntr_;
}

void Memory::incr() {
    ++(*p_cntr_);
}

void Memory::decr() {
    --(*p_cntr_);
}

unsigned char Memory::get_val() {
    return *p_cntr_;
}

void Memory::set_val(unsigned char new_val) {
    *p_cntr_ = new_val;
}
