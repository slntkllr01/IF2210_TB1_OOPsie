#ifndef _PEKERJA_HPP
#define _PEKERJA_HPP

#include <iostream>
using namespace std;

#include "Pemain.hpp"

class Pekerja : public Pemain {
    protected:
        int KTKP;
    public:
        /* User-Defined Constructor */
        Pekerja(string username, string peran, int KTKP);
        Pekerja(string username, string peran, int uang, int beratBadan, int KTKP);
        /* Destructor */
        virtual ~Pekerja();
        /* Getter */
        int getKTKP() const;
        /* Membeli barang */
        void beli(Item* item, int kuantitas);
        /* Menghitung KKP */
        int getKKP(int kekayaan);
        /* Menghitung kekayaan pemain */
        virtual int hitungKekayaan();
        /* Menghitung pajak yang harus dibayar oleh pemain */
        int hitungPajak(int KKP);
        /* Membayar pajak */
        void bayarPajak(int pajak);
};

#endif