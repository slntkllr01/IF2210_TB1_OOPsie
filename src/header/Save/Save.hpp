#ifndef SAVE_HPP
#define SAVE_HPP

#include "./header/ListPemain/ListPemain.hpp"
#include "./header/Toko/Toko.hpp"
#include <fstream>

class Save {
    public:
        void saveState(ListPemain listPemain, Toko toko, string fileName);
};

#endif