#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include <string>
#include "../Produk/Produk.hpp"
#include "../Item/Item.hpp"
using namespace std;

class Tanaman : public Item {
    private:
        string type;
        int durationToHarvest;
        int umur;
    public:
        Tanaman(int ID);
        Tanaman(string name);
        ~Tanaman();
        string get_type();
        void set_durationToHarvest(int durationToHarvest);
        void set_umur(int umur);
        int get_durationToHarvest();
        int get_umur();
        void add_umur();
        bool siapPanen();
};

#endif