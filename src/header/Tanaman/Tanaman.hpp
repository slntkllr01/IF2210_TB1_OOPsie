#ifndef TANAMAN_HPP
#define TANAMAN_HPP

#include <string>
#include "../Item/Item.hpp"
using namespace std;

class Tanaman : public Item {
    private:
        int id;
        string kodeHuruf;
        string name;
        string type;
        int durationToHarvest;
        int price;
        int umur;
    public:
        Tanaman(int id, string kodeHuruf, string name, string type, int durationToHarvest, int price);
        ~Tanaman();
        int get_id();
        string get_kodeHuruf();
        string get_name();
        string get_type();
        int get_durationToHarvest();
        int get_price();
        int get_umur();
        void add_umur();
        bool siapPanen();
};

#endif