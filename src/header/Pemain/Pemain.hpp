#ifndef _PEMAIN_HPP
#define _PEMAIN_HPP
using namespace std;
#include <iostream>
#include "Grid.hpp"
class Pemain{
    private:

    public:
        void add_player();                      // menambah pemain, validasi unique name, validasi name bukan string kosong
        bool is_namedupe(string inputname);     // cek apakah ada duplikasi nama pemain
};

#endif