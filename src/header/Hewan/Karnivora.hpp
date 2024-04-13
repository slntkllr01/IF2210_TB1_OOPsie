#ifndef _KARNIVORA_HPP
#define _KARNIVORA_HPP
#include <string>
using namespace std;

class Karnivora: public Hewan {
public:
    Karnivora(int id);
    ~Karnivora();
    bool CanEat(Produk* makanan);
};

#endif