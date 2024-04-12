#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <vector>
#include "header/Pemain/Pemain.hpp"
#include "header/Item/Item.hpp"
#include "src/header/Loader/ConfigLoader.hpp"

using namespace std;

class Toko {
    private:
        map<Item, int> inventory; // map<Item, int>
    public:
        map<Item, int> getInventory() const;
        int InvLength() const;
        void transaksiBeli();
        void transaksiJual();
        void showInventory(Loader config); // SOON mo beli makan dl
        Toko& operator+=(const Item& barang); // aga kurang srek si gue (revisi soon)
        Toko& operator-=(const Item& barang);// aga kurang srek si gue (revisi soon)
};

#endif