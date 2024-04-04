#ifndef _PEMAIN_HPP
#define _PEMAIN_HPP

#include <iostream>
using namespace std;

#include "Grid/Inventory.hpp"
#include "Produk/Produk.hpp"

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
        string getUsername();
        /* Menghitung kekayaan pemain */
        virtual int hitungKekayaan();
        /* Menghitung pajak yang harus dibayar oleh pemain */
        virtual int hitungPajak() = 0;
        /* Makan */
        void makan(Produk produk);
};

#endif