#include "../../header/Pemain/Petani.hpp"
#include "../../header/Produk/Produk.hpp"

/* Default Constructor */
Petani::Petani() : Pekerja("", "Petani", 13), ladang(Ladang()) {}

/* User-Defined Constructor */
Petani::Petani(string username) : Pekerja(username, "Petani", 13), ladang(Ladang()) {}
Petani::Petani(string username, int uang, int beratBadan) : Pekerja(username, "Petani", uang, beratBadan, 13), ladang(Ladang()) {}

/* Destructor */
Petani::~Petani() {}

/* Getter */
Ladang Petani::getLadang() const {
    return ladang;
}

/* Setter */
void Petani::setLadang(Ladang ladang){
    this->ladang = ladang;
}

/* Menghitung kekayaan petani */
int Petani::hitungKekayaan(){
    // Kekayaan dari inventory dan uang
    int kekayaan_inventory_uang = Pekerja::hitungKekayaan();
    // Kekayaan dari ladang
    int kekayaan_ladang = 0;
    for (const auto& element : ladang.getElMap()){
        if (ladang.isPresent(element.first)){
            kekayaan_ladang += element.second->getPrice();
        }
    }
    return kekayaan_inventory_uang + kekayaan_ladang;
}

void Petani::tanam(Tanaman* tanaman, string lokasi){
    ladang.addTanaman(tanaman, lokasi);
}

/* Memanen tanaman yang ada di ladang */
void Petani::panenTanaman(string lokasi){
    Tanaman* tanaman = ladang.delTanaman(lokasi);
    // Ubah tanaman menjadi produk
    produkTumbuhan* prod = new produkTumbuhan(tanaman->getID());
    simpanItemAuto(prod);
}