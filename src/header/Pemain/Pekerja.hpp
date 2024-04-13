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
        /* Setter */
        void setKTKP(int KTKP);
        /* Mengecek apakah pemain bisa menjual barang */
        bool bisaJual(Item* item) override;
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