#ifndef _PETANI_HPP
#define _PETANI_HPP

#include <iostream>
using namespace std;

#include "Pemain.hpp"
#include "Grid/Ladang.hpp"

class Petani : public Pemain {
    private:
        Ladang ladang;
    public:
        /* Default Constructor */
        Petani();
        /* User-Defined Constructor */
        Petani(string username, string peran);
        /* Destructor */
        ~Petani();
        /* Menghitung pajak yang harus dibayar oleh petani */
        int hitungPajak() override;
        /* Menanam tanaman di ladang */
        void tanam();
        /* Memanen tanaman yang ada di ladang */
        void panenTanaman();
};

#endif