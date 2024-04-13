#ifndef _HERBIVORA_HPP
#define _HERBIVORA_HPP
#include <string>
#include "../Produk/Produk.hpp"
using namespace std;
class Herbivora: public Hewan
{
public:
    Herbivora(int id, string code, string name, int price, int harvestweight, int actualweight, int age);
    ~Herbivora();
    bool CanEat(Produk* makanan);
};

#endif