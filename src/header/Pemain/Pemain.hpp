#ifndef _PEMAIN_HPP
#define _PEMAIN_HPP

#include <iostream>
using namespace std;

#include "../Grid/Inventory.hpp"
#include "../Produk/Produk.hpp"

class Pemain {
    protected:
        string username;
        string peran;
        Inventory inventory;
        int uang;
        int beratBadan;

    public:
        /* Default Constructor */
        Pemain();
        /* User-Defined Constructor */
        Pemain(string username, string peran);
        /* Destructor */
        virtual ~Pemain();
        /* Getter */
        string getUsername() const;
        string getPeran() const;
        Inventory getInventory() const;
        int getUang() const;
        int getBeratBadan() const;
        /* Makan */
        void makan(Produk produk);
        /* Menjual barang */
        void jual(int x, int y);
        /* Membeli barang */
        void beli(int x, int y);
        /* Mengecek apakah pemain memenuhi kondisi menang */
        bool isMenang();
};

#endif