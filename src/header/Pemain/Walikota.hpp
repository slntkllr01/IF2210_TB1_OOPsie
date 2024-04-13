#ifndef _WALIKOTA_HPP
#define _WALIKOTA_HPP

#include <iostream>
using namespace std;

#include "Pemain.hpp"
#include "../ListPemain/ListPemain.hpp"
#include "../Bangunan/Bangunan.hpp"
#include "../Exception/Exception.hpp"

class Walikota : public Pemain {
    private:
        /* Membuat instance dari Walikota */
        static Walikota* instance;
        /* User-Defined Constructor */
        Walikota(string username);
        // Walikota(string username, int uang, int beratBadan);
    public:
        /* Mengembalikan instance dari Walikota */
        static Walikota* getInstance(string username);
        /* Destructor */
        ~Walikota();
        /* Mengecek apakah pemain bisa membeli barang */
        bool bisaBeli(Item* item) override;
        /* Menagih pajak */
        void tagihPajak(ListPemain list_pemain);
        /* Membangun bangunan */
        void bangunBangunan(Bangunan bangunan);
        /* Menambah pemain */
        void tambahPemain(string username, string peran, ListPemain list_pemain);
};

// Inisialisasi instance Walikota
Walikota* Walikota::instance = nullptr;

#endif