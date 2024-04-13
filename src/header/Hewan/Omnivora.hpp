#ifndef _OMNIVORA_HPP
#define _OMNIVORA_HPP
#include <string>
#include "Produk.hpp"
using namespace std;
class Omnivora: public Hewan
{
public:
    Omnivora(int id);
    ~Omnivora();
    bool CanEat(Produk* makanan);
};

#endif