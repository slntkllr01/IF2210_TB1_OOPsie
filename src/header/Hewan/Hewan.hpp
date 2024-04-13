#ifndef _HEWAN_HPP
#define _HEWAN_HPP
#include <string>
#include "../Exception/Exception.hpp"
#include "../Produk/Produk.hpp"
using namespace std;

class Hewan : public Item {
private:           
    int harvestweight;
    int actualweight;   // tambahan berat hewan sebenarnya
    int age;
// <ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>
public:
    static int DEADAGE;
    Hewan(string itemType, int id, string code, string name, int price, int harvestweight, int actualweight, int age);
    ~Hewan();
    void set_harvestweight(int harvestweight);
    int get_harvestweight() const;
    void set_actualweight(int actualweight);
    int get_actualweight() const;
    bool siapPanen();
    bool is_Dead();
    virtual bool CanEat(Produk* makanan) = 0;
};

#endif

// EXCEPTION KASIH MAKAN:
//// exception kalau peternakan kosong
//// exception kalau tidak ada makanan khusus untuk hewan tersebut di inv
////

// Ideas to add
//// add umur ke hewan biar bs mati
//// breeding hewan (huge, butuh item breeding)
//// penyakit (bs mati, butuh medicine)

// Di Inventory ada