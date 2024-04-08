#ifndef _PETANI_HPP
#define _PETANI_HPP

#include <iostream>
using namespace std;

#include "Pekerja.hpp"
#include "../Grid/Ladang.hpp"
#include "../Tanaman/Tanaman.hpp"

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
        /* Getter */
        Ladang getLadang();
        /* Menghitung kekayaan petani */
        int hitungKekayaan();
        /* Menanam tanaman di ladang */
        void tanam(int x, int y);
        /* Memanen tanaman yang ada di ladang */
        void panenTanaman(int x, int y);
};

#endif