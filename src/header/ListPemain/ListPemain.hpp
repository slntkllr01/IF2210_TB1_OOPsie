#ifndef _LIST_PEMAIN_HPP
#define _LIST_PEMAIN_HPP
using namespace std;
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"
#include <iostream>
#include <vector>
class ListPemain{
    private:
        vector<Pemain*> ArrPemain;
    public:
        ListPemain();
        ~ListPemain();
        void add_Pemain(Pemain* pemain);     // add new pemain and sort it's order
        void check_Dupe(string nama);       // check if there is a dupe name
        void print_AllPemain();
        vector<Pemain*> get_ArrPemain();
        bool compareNames(const Pemain* a, const Pemain* b);
};

#endif