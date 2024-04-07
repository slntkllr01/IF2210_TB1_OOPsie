#ifndef _OMNIVORA_HPP
#define _OMNIVORA_HPP
#include <string>
#include "Produk.hpp"
using namespace std;
class Omnivora: public Hewan
{
public:
    Omnivora(int ID, string code, string name, int harvestweight, int price);
    ~Omnivora();
    bool CanEat(string tipe);
};

#endif