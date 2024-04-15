#ifndef PRODUK_HPP
#define PRODUK_HPP

#include <string>
#include "../Item/Item.hpp"
#include "../Loader/ConfigLoader.hpp"
using namespace std;

class Produk : public Item {
    private:
        string tipe;
        string origin;
        int addedWeight;
    public:
        Produk(int id);
        Produk(string name);
        virtual bool isEdibleBy() = 0;
        int getAddedWeight() const;
        string getType() const;
        void setType(string type);
        void setOrigin(string origin);
        void setAddedWeight(int weight);

};

class produkHewan : public Produk {
    public:
        produkHewan(int id);
        produkHewan(string name);
        bool isEdibleBy() override;
};

class produkTumbuhan : public Produk {
    public:
        produkTumbuhan(int id);
        produkTumbuhan(string name);
        bool isEdibleBy() override;
        bool isBahan();
};

#endif