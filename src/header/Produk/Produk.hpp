#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <string>
using namespace std;

class Produk {
    private:
        int id;
        string kodeHuruf;
        string nama;
        string tipe;
        string origin;
        int addedWeight;
        int price;
    public:
        Produk();
        int getAddedWeight();
};

class produkHewan : public Produk {

};

class produkTumbuhan : public Produk {
    
};

#endif