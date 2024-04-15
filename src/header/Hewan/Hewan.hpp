#ifndef _HEWAN_HPP
#define _HEWAN_HPP
#include <string>
#include "../Exception/Exception.hpp"
#include "../Produk/Produk.hpp"
#include "../Loader/ConfigLoader.hpp"
using namespace std;

class Hewan : public Item {
private:        
    string type;
    int harvestweight;
    int actualweight;   // tambahan berat hewan sebenarnya
    int age;
// <ID> <KODE_HURUF> <NAME> <TYPE> <WEIGHT_TO_HARVEST> <PRICE>
public:
    static int DEADAGE;
    Hewan(int id);
    Hewan(string name);
    ~Hewan();
    void set_type(string type);
    string get_type();
    void set_age(int age);
    int get_age();
    void set_harvestweight(int harvestweight);
    int get_harvestweight() const;
    void set_actualweight(int actualweight);
    int get_actualweight() const;
    bool siapPanen();
    bool is_Dead();
    string getType() const;
    void setType(string type);
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