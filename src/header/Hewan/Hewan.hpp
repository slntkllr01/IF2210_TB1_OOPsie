#ifndef _HEWAN_HPP
#define _HEWAN_HPP
#include <string>
#include "../Exception/Exception.hpp"
#include "../Produk/Produk.hpp"
using namespace std;

class Hewan
{
private:
    int ID;             
    string code;
    string name;
    string type;
    int harvestweight;
    int actualweight;   // tambahan berat hewan sebenarnya
    int price;
    int age;
// <ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>
public:
    static int DEADAGE;
    Hewan(int ID, string code, string name, string type, int harvestweight, int price);
    ~Hewan();
    void set_actualweight(int actualweight);
    string get_name() const;
    int get_price() const;
    int get_actualweight() const;
    bool siapPanen();
    bool is_Dead();
    virtual bool CanEat(string tipe) = 0;
    void printInfo();
    // batal panen?
    // batal kasih makan? tp keknya gausah bs sih
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