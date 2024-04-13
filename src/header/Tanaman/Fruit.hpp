#ifndef _FRUIT_HPP
#define _FRUIT_HPP

#include <string>
#include "../Tanaman.hpp"
#include "../Produk/Produk.hpp"

using namespace std;

class Fruit: public Tanaman {
    public:
        Fruit(int ID);
        ~Fruit();
        bool CanEat(Produk* makanan);
};

#endif