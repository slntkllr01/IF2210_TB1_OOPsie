#ifndef _KARNIVORA_HPP
#define _KARNIVORA_HPP
#include <string>
using namespace std;

class Karnivora: public Hewan {
public:
    Karnivora(int id, string code, string name, int price, int harvestweight, int actualweight, int age);
    ~Karnivora();
    bool CanEat(Produk* makanan);
};

#endif