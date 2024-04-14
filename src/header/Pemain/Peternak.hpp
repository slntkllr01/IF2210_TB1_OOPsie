#ifndef _PETERNAK_HPP
#define _PETERNAK_HPP

#include <iostream>
using namespace std;

#include "Pekerja.hpp"
#include "../Grid/Peternakan.hpp"
#include "../Produk/Produk.hpp"
#include "../Hewan/Hewan.hpp"

class Peternak : public Pekerja {
    private:
        Peternakan peternakan;
    public:
        /* Default Constructor */
        Peternak();
        /* User-Defined Constructor */
        Peternak(string username);
        Peternak(string username, int uang, int beratBadan);
        /* Destructor */
        ~Peternak();
        /* Getter */
        Peternakan getPeternakan() const;
        /* Setter */
        void setPeternakan(Peternakan peternakan);
        /* Menghitung kekayaan Peternak */
        int hitungKekayaan() override;
        /* Meletakkan hewan di peternakan */
        void ternak(Hewan* hewan, string lokasi);
        /* Memberi makan hewan */
        void beriMakanHewan(Hewan* hewan, Produk* makanan);
        /* Memanen hewan yang ada di peternakan */
        void panenHewan(string lokasi);
};

#endif