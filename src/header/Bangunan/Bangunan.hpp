#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <string>
#include <map>
#include "../Item/Item.hpp"
using namespace std;

class Bangunan : public Item {
    private:
        int ID;
        string kode;
        string nama;
        map<string, int> listOfResep; // ganti jadi map > kuantitas!
        int price;
    public:
        Bangunan(int ID, string kode, string nama, map<string, int> listOfResep, int price);
};

#endif