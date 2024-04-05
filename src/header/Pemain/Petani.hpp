#ifndef _PETANI_HPP
#define _PETANI_HPP

#include <iostream>
using namespace std;

#include "Pekerja.hpp"
#include "Grid/Ladang.hpp"

class Petani : public Pekerja {
    private:
        Ladang ladang;
    public:
        /* Default Constructor */
        Petani();
        /* User-Defined Constructor */
        Petani(string username, string peran);
        /* Destructor */
        ~Petani();
        /* Menghitung kekayaan petani */
        int hitungKekayaan();
        /* Menanam tanaman di ladang */
        void tanam();
        /* Memanen tanaman yang ada di ladang */
        void panenTanaman();
};

#endif