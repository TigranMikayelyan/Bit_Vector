#include "bit_vector.h"
#include <iostream>
#include <exception>

Bit_vector::Bit_vector()
{
    bit_size = 1;
    bit_arr = new unsigned long[bit_size];
}

Bit_vector::~Bit_vector()
{
    delete[] bit_arr;
    bit_arr = nullptr;
}

bool Bit_vector::operator[](unsigned long pos)
{
     if (pos >= bit_size * (sizeof(unsigned long) * 8))
    {
        throw std::out_of_range("Invalid index!!!");
    }
    unsigned long index = pos / (sizeof(unsigned long) * 8);
    return bit_arr[index] & ((1ul << (pos - (sizeof(unsigned long) * 8 * index))));
}

unsigned long Bit_vector::operator[](unsigned long pos) const
{
    if (pos >= bit_size * (sizeof(unsigned long) * 8))
    {
        throw std::out_of_range("Invalid index!!!");
    }
    return bit_arr[pos];
}

std::ostream& operator<<(std::ostream& os, const Bit_vector& vec)
{
    std::string res = "";
    int tmp_size = (8 * 8);
    std::cout << vec.bit_size << std::endl;
    for (int i = vec.bit_size - 1; i >= 0; --i)
    {
        res += vec.to_bin(vec[i], tmp_size);
    }
    os << res;
    std::cout << std::endl;
    return os;
}

void Bit_vector::resize(unsigned long position)
{   
    unsigned long new_size = position / (sizeof(unsigned long) * 8);
    unsigned long* tmp = new unsigned long[++new_size];
    for (int i = 0; i < bit_size; ++i)
    {
        tmp[i] = bit_arr[i];
    }
    delete[] bit_arr;
    bit_arr = tmp;
    tmp = nullptr;
    bit_size = new_size;
}

void Bit_vector::bit_set(unsigned long pos)
{
    if (pos >= bit_size * (sizeof(unsigned long) * 8))
    {
        resize(pos);
    }
    unsigned long index = pos / (sizeof(unsigned long) * 8);
    bit_arr[index] |= ((1ul << (pos - (sizeof(unsigned long) * 8 * index))));
}

void Bit_vector::bit_reset(unsigned long pos)
{
    if (pos >= bit_size * (sizeof(unsigned long) * 8))
    {
        resize(pos);
    }
    unsigned long index = pos / (sizeof(unsigned long) * 8);
    bit_arr[index] &= ~((1ul << (pos - (sizeof(unsigned long) * 8 * index))));
} 

bool Bit_vector::bit_get(unsigned long pos) const
{
    if (pos >= bit_size * (sizeof(unsigned long) * 8))
    {
        throw std::out_of_range("Invalid index!!!");
    }
    unsigned long index = pos / (sizeof(unsigned long) * 8);
    return bit_arr[index] & ((1ul << (pos - (sizeof(unsigned long) * 8 * index))));
}

unsigned long Bit_vector::get_size() const
{
    return bit_size;
}

std::string Bit_vector::to_bin(unsigned long num, unsigned long count) const
{
    std::string str = "";
    for (int i = 0; i < count; ++i)
    {
        str.insert(0, std::to_string(num % 2));
        num /= 2;
    }
    return str;
}
