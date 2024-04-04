#ifndef _PEMAIN_HPP
#define _PEMAIN_HPP
using namespace std;
#include <iostream>
#include "Grid/Inventory.hpp"

class Pemain {
    protected:
        string username;
        string peran;
        Inventory inventory;
        int uang;
        int beratBadan;

    public:
        Pemain();
        Pemain(string username, string peran, Inventory inventory, int uang, int beratBadan);
        virtual ~Pemain();
        virtual void hitungPajak() = 0;
        string getUsername();
};

#endif