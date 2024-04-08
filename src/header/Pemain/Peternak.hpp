#ifndef _PETERNAK_HPP
#define _PETERNAK_HPP

#include <iostream>
using namespace std;

#include "Pekerja.hpp"
#include "Grid/Peternakan.hpp"
#include "Hewan/Hewan.hpp"

class Peternak : public Pekerja {
    private:
        Peternakan peternakan;
    public:
        /* Default Constructor */
        Peternak();
        /* User-Defined Constructor */
        Peternak(string username, string peran);
        /* Destructor */
        ~Peternak();
        /* Getter */
        Peternakan getPeternakan();
        /* Menghitung kekayaan Peternak */
        int hitungKekayaan();
        /* Meletakkan hewan di peternakan */
        void taruhHewan(int x, int y);
        /* Memberi makan hewan */
        void beriMakanHewan(int x, int y);
        /* Memanen hewan */
        void panenHewan(int x, int y);
};

#endif