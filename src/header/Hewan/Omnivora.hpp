#ifndef _OMNIVORA_HPP
#define _OMNIVORA_HPP
#include <string>
#include "Produk.hpp"
using namespace std;
class Omnivora: public Hewan
{
public:
    Omnivora(string itemType, int id, string code, string name, int price, int harvestweight, int actualweight, int age);
    ~Omnivora();
    bool CanEat(Produk* makanan);
};

#endif