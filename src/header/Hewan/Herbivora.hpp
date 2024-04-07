#ifndef _HERBIVORA_HPP
#define _HERBIVORA_HPP
#include <string>
#include "../Produk/Produk.hpp"
using namespace std;
class Herbivora: public Hewan
{
public:
    Herbivora(int ID, string code, string name, string type, int harvestweight, int price);
    ~Herbivora();
    void KasihMakan(Produk makanan);
    bool CanEat(string tipe);
};

#endif