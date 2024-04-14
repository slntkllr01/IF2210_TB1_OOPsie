#include "../../header/Pemain/Peternak.hpp"

/* Default Constructor */
Peternak::Peternak() : Pekerja("", "Peternak", 11), peternakan(Peternakan()) {}

/* User-Defined Constructor */
Peternak::Peternak(string username) : Pekerja(username, "Peternak", 11), peternakan(Peternakan()) {}
Peternak::Peternak(string username, int uang, int beratBadan) : Pekerja(username, "Peternak", uang, beratBadan, 11), peternakan(Peternakan()) {}

/* Destructor */
Peternak::~Peternak() {}

/* Getter */
Peternakan Peternak::getPeternakan() const {
    return peternakan;
}

/* Setter */
void Peternak::setPeternakan(Peternakan peternakan){
    this->peternakan = peternakan;
}

/* Menghitung kekayaan Peternak */
int Peternak::hitungKekayaan(){
    // Kekayaan dari inventory dan uang
    int kekayaan_inventory_uang = Pekerja::hitungKekayaan();
    // Kekayaan dari peternakan
    int kekayaan_peternakan = 0;
    for (const auto& element : peternakan.getKotak().getElMap()){
        if (peternakan.getKotak().isPresent(element.first)){
            kekayaan_peternakan += element.second->getPrice();
        }
    }
    return kekayaan_inventory_uang + kekayaan_peternakan;
}

/* Meletakkan hewan di peternakan */
void Peternak::ternak(Hewan* hewan, string lokasi){
    peternakan.addHewan(hewan, lokasi);
}

/* Memberi makan hewan */
void Peternak::beriMakanHewan(Hewan* hewan, Produk* makanan){
    hewan->set_actualweight(hewan->get_actualweight() + makanan->getAddedWeight());
}

/* Memanen hewan yang ada di peternakan */
void Peternak::panenHewan(string lokasi){
    Hewan* hewan = peternakan.delHewan(lokasi);
    Produk* produk = hewan->hasilHewan();
    inventory.SimpanBarang(produk);
}