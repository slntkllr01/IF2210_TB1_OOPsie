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
        Pekerja(string username, string peran);
        /* Destructor */
        virtual ~Pekerja();
        /* Menghitung KKP */
        int getKKP(int kekayaan);
        /* Menghitung kekayaan pemain */
        virtual int hitungKekayaan();
        /* Menghitung pajak yang harus dibayar oleh pemain */
        int hitungPajak(int KKP);
};

#endif