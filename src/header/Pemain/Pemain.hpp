#ifndef _PEMAIN_HPP
#define _PEMAIN_HPP

#include <iostream>
using namespace std;

#include "../Item/Item.hpp"
#include "../Produk/Produk.hpp"
#include "../Grid/Inventory.hpp"

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
        Pemain(string username, string peran, int uang, int beratBadan);
        /* Destructor */
        virtual ~Pemain();
        /* Operator == */
        bool operator==(const Pemain& pemain);
        /* Getter */
        string getUsername() const;
        string getPeran() const;
        Inventory getInventory() const;
        int getUang() const;
        int getBeratBadan() const;
        /* Setter */
        void setUsername(string username);
        void setPeran(string peran);
        void setInventory(Inventory inventory);
        void setUang(int uang);
        void setBeratBadan(int beratBadan);
        /* Menyimpan item ke inventory */
        void simpanItem(Item* item, string lokasi);
        /* Mengambil item dari inventory */
        Item* ambilItem(string lokasi);
        /* Makan */
        void makan(Produk* produk);
        /* Mengecek apakah uang cukup */
        bool isUangCukup(int uang);
        /* Mengecek apakah pemain bisa membeli barang */
        virtual bool bisaBeli(Item* item);
        /* Mengecek apakah pemain bisa menjual barang */
        virtual bool bisaJual(Item* item);
        /* Membeli barang */
        void beli(const Item* item, int kuantitas);
        /* Menjual barang */
        void jual(Item* item, int kuantitas);
        /* Mengecek apakah pemain memenuhi kondisi menang */
        bool isMenang();
        /* Operator == untuk membandingkan pointer pemain */
        bool operator==(const Pemain* other) const;
};

#endif