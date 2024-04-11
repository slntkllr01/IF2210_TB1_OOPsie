#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <string>
#include "../Item/Item.hpp"
using namespace std;

class Produk : public Item {
    private:
        int id;
        string kodeHuruf;
        string nama;
        string tipe;
        string origin;
        int addedWeight;
        int price;
    public:
        Produk(int id, string kodeHuruf, string nama, string tipe, string origin, int addedWeight, int price);
        virtual bool isEdibleBy(string animalType) = 0;
        virtual int getAddedWeight() const;
        virtual string getType() const;

};

class produkHewan : public Produk {
    public:
        produkHewan(int id, string kodeHuruf, string nama, string tipe, string origin, int addedWeight, int price);
        bool isEdibleBy(string animalType) override;
};

class produkTumbuhan : public Produk {
    public:
        produkTumbuhan(int id, string kodeHuruf, string nama, string tipe, string origin, int addedWeight, int price);
        bool isEdibleBy(string animalType) override;
};

#endif