#ifndef _FRUIT_HPP
#define _FRUIT_HPP

#include <string>
#include "../Produk/Produk.hpp"

using namespace std;

class Material : public Tanaman {
    public:
        Material(int ID);
        Material(string name);
        ~Material();
        bool CanEat(Produk* makanan);
};

#endif