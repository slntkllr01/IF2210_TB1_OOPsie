#ifndef _OMNIVORA_HPP
#define _OMNIVORA_HPP
#include <string>
#include "Produk.hpp"
using namespace std;
class Omnivora: public Hewan
{
public:
    Omnivora(int ID, string code, string name, string type, int harvestweight, int price);
    ~Omnivora();
    void KasihMakan(Produk makanan);
};

#endif