#include "../../header/Pemain/Walikota.hpp"
#include "../../header/Pemain/Pekerja.hpp"
#include "../../header/Pemain/Peternak.hpp"
#include "../../header/Pemain/Petani.hpp"

/* Inisialisasi instance Walikota */
Walikota* Walikota::instance = nullptr;

/* User-Defined Constructor */
Walikota::Walikota(string username) : Pemain(username, "Walikota") {}

/* Mengembalikan instance dari Walikota */
Walikota* Walikota::getInstance(string username){
    if (instance == nullptr){
        instance = new Walikota(username);
    }
    return instance;
}

/* Destructor */
Walikota::~Walikota() {}

/* Inisialisasi nilai atribut */
void Walikota::initialize(string username, int uang, int beratBadan){
    this->username = username;
    this->uang = uang;
    this->beratBadan = beratBadan;
}

/* Mengecek apakah pemain bisa membeli barang */
bool Walikota::bisaBeli(Item* item){
    return !(dynamic_cast<Bangunan*>(item));
}

/* Menagih pajak */
void Walikota::tagihPajak(ListPemain& list_pemain){
    int totalPajak = 0;
    vector<Pemain*> pemains = list_pemain.get_ArrPemain();
    for (Pemain* pemain : pemains){
        // Jika dynamic_cast ke Walikota* mengembalikan nullptr, berarti pemain bukan Walikota
        if (dynamic_cast<Walikota*>(pemain) == nullptr){
            Pekerja* pekerja = dynamic_cast<Pekerja*>(pemain);
            totalPajak += pekerja->hitungPajak();
            pekerja->bayarPajak();
        }
    }
    uang += totalPajak;
}

/* Membangun bangunan */
void Walikota::bangunBangunan(Bangunan* bangunan){
    map<Item*, pair<int, vector<string>>> item = Inventory::listBahanBangunan(this->getInventory().getElMap());
    for (const auto& it : item) {
        for (int i = 0; i < it.second.second.size(); i++) {
            this->ambilItem(it.second.second[i]);
        }
    }

    this->simpanItemAuto(bangunan);
}

/* Menambah pemain */
void Walikota::tambahPemain(string username, string peran, ListPemain& list_pemain){
    Pemain* pemainPtr = nullptr;
    if (peran == "Petani"){
        pemainPtr = new Petani(username);
    } else if (peran == "Peternak"){
        pemainPtr = new Peternak(username);
    }
    if (pemainPtr != nullptr){
        list_pemain.add_Pemain(pemainPtr);
        uang -= 50;
    }
}