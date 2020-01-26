#pragma once
#include <cstddef>
#include <vector>

class Memory {
    std::size_t mem_size;
    std::vector<unsigned char> mem_repr;
    std::vector<unsigned char>::iterator p_cntr;

public:
    Memory(std::size_t);
    void mv_right();
    void mv_left();
    void incr();
    void decr();
    unsigned char get_val();
    void set_val(unsigned char new_val);
};
