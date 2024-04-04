#ifndef _PETANI_HPP
#define _PETANI_HPP

#include <iostream>
using namespace std;

#include "Pemain.hpp"

class Petani : public Pemain {
    public:
        Petani();
        Petani(string username, string peran, Inventory inventory, int uang, int beratBadan);
        ~Petani();
        void hitungPajak();
};