#ifndef _KARNIVORA_HPP
#define _KARNIVORA_HPP
#include <string>
using namespace std;
class Karnivora: public Hewan
{
public:
    Karnivora(int ID, string code, string name, string type, int harvestweight, int price);
    ~Karnivora();
    void KasihMakan(Produk makanan);
};

#endif