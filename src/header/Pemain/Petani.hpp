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
        Petani(string username);
        Petani(string username, int uang, int beratBadan);
        /* Destructor */
        ~Petani();
        /* Getter */
        Ladang getLadang() const;
        /* Setter */
        void setLadang(Ladang ladang);
        /* Menghitung kekayaan petani */
        int hitungKekayaan() override;
        /* Menanam tanaman di ladang */
        void tanam(Tanaman* tanaman, string lokasi);
        /* Memanen tanaman yang ada di ladang */
        void panenTanaman(string lokasi);
};

#endif