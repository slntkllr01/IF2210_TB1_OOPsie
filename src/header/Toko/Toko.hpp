#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <map>
#include "../Pemain/Pemain.hpp"
#include "../Item/Item.hpp"
#include "../Hewan/Hewan.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "../Tanaman/Tanaman.hpp"
#include "../Loader/ConfigLoader.hpp"

using namespace std;

class Toko {
    private:
        map<Item, int> inventory;
        vector<Hewan*> invHewan;
        vector<Tanaman> invTanaman;
    public:
        Toko();
        ~Toko();
        map<Item, int> getInventory() const;
        vector<Hewan*> getInvHewan() const;
        vector<Tanaman> getInvTanaman() const;
        int InvLength() const;
        void transaksiBeli(Pemain* pemain, const Item* item, int kuantitas);
        void transaksiJual(Pemain* pemain, Item* item, int kuantitas);
        void showInventory();
        int getStock(Item* item);
        void addBarang(Item* item, int jumlah);
        void addInvHewanandTanaman();
};

#endif