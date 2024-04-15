#ifndef _HERBIVORA_HPP
#define _HERBIVORA_HPP
#include <string>
#include "../Produk/Produk.hpp"
using namespace std;
class Herbivora: public Hewan
{
public:
    Herbivora(int id);
    Herbivora(string name);
    ~Herbivora();
    bool CanEat(Produk* makanan);
};

#endif