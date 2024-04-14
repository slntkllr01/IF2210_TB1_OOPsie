#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include "../Pemain/Pemain.hpp"
#include "../Item/Item.hpp"
#include "../Loader/ConfigLoader.hpp"

using namespace std;

class Toko {
    private:
        map<Item, int> inventory;
    public:
        Toko();
        ~Toko();
        map<Item, int> getInventory() const;
        int InvLength() const;
        void transaksiBeli(Pemain pemain, Item* item, int kuantitas);
        void transaksiJual(Pemain pemain, Item* item, int kuantitas);
        void showInventory(ConfigLoader& config);
};

#endif