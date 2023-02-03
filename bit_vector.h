#ifndef BIT_VECTOR_H
#define BIT_VECTOR_H
#include <iostream>

class Bit_vector
{
public:
    Bit_vector();
    Bit_vector(unsigned long);
    ~Bit_vector();
public:
    bool operator[](unsigned long);
    unsigned long operator[](unsigned long) const;
    friend std::ostream& operator<<(std::ostream&, const Bit_vector&);
public:
    void bit_set(unsigned long);
    void bit_reset(unsigned long);    
    bool bit_get(unsigned long) const;
    void resize(unsigned long);
    unsigned long get_size() const;
    std::string to_bin(unsigned long, unsigned long) const;
private:    
    unsigned long bit_size;
    unsigned long* bit_arr;
};
#endif // BIT_VECTOR_H