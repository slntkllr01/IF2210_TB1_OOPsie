#ifndef _WALIKOTA_HPP
#define _WALIKOTA_HPP

#include <iostream>
using namespace std;

#include "Pemain.hpp"
#include "../ListPemain/ListPemain.hpp"
#include "../Bangunan/Bangunan.hpp"

class Walikota : public Pemain {
    private:
        /* User-Defined Constructor */
        Walikota(string username);
        /* Membuat instance dari Walikota */
        static Walikota* instance;
    public:
        /* Mengembalikan instance dari Walikota */
        static Walikota* getInstance(string username);
        /* Destructor */
        ~Walikota();
        /* Menagih pajak */
        void tagihPajak(ListPemain list_pemain);
        /* Membangun bangunan */
        void bangunBangunan(Bangunan bangunan);
        /* Menambah pemain */
        void tambahPemain(string username, string peran);
};

#endif