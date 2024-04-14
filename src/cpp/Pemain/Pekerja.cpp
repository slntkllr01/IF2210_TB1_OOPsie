#include "../../header/Pemain/Pekerja.hpp"
#include "../../header/Bangunan/Bangunan.hpp"

/* User-Defined Constructor */
Pekerja::Pekerja(string username, string peran, int KTKP) : Pemain(username, peran), KTKP(KTKP) {}
Pekerja::Pekerja(string username, string peran, int uang, int beratBadan, int KTKP) : Pemain(username, peran, uang, beratBadan), KTKP(KTKP) {}

/* Destructor */
Pekerja::~Pekerja() {}

/* Getter */
int Pekerja::getKTKP() const {
    return KTKP;
}

/* Setter */
void Pekerja::setKTKP(int KTKP){
    this->KTKP = KTKP;
}

/* Mengecek apakah pemain bisa menjual barang */
bool Pekerja::bisaJual(Item* item){
    return !(dynamic_cast<Bangunan*>(item)); 
}

/* Menghitung kekayaan pemain */
int Pekerja::hitungKekayaan(){
    // Kekayaan dari inventory
    int kekayaan_inventory = 0;
    for (const auto& element : inventory.getKotak().getElMap()){
        if (inventory.getKotak().isPresent(element.first)){
            kekayaan_inventory += element.second->getPrice();
        }
    }
    return uang + kekayaan_inventory;
}

/* Menghitung KKP */
int Pekerja::getKKP(){
    int kekayaan = hitungKekayaan();
    return kekayaan - KTKP;
}

/* Menghitung pajak yang harus dibayar oleh pemain */
int Pekerja::hitungPajak(){
    int KKP = getKKP();
    if (KKP <= 0){
        return 0;
    } else if (KKP <= 6){
        return 0.05 * KKP;
    } else if (6 < KKP && KKP <= 25){
        return 0.15 * KKP;
    } else if (25 < KKP && KKP <= 50){
        return 0.25 * KKP;
    } else if (50 < KKP && KKP <= 500){
        return 0.30 * KKP;
    } else{
        return 0.35 * KKP;
    }
}

/* Membayar pajak */
void Pekerja::bayarPajak(){
    int pajak = hitungPajak();
    uang -= pajak;
}