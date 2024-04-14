#ifndef SAVE_HPP
#define SAVE_HPP

#include "../ListPemain/ListPemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Toko/Toko.hpp"
#include <fstream>

class Save {
    public:
        void saveState(ListPemain listPemain, Toko toko, string fileName);
};

#endif