#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <string>
using namespace std;

class product {
    private:
        int id;
        string kodeHuruf;
        string nama;
        string tipe;
        string origin;
        int addedWeight;
        int price;
    public:

};

class produkHewan : public product {

};

class produkTumbuhan : public product {
    
};

#endif