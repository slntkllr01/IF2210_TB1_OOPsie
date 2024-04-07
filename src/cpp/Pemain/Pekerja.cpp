#include "../../header/Pemain/Pekerja.hpp"

/* User-Defined Constructor */
Pekerja::Pekerja(string username, string peran, int KTKP) : Pemain(username, peran), KTKP(KTKP) {}

/* Destructor */
Pekerja::~Pekerja() {}

/* Menghitung KKP */
int Pekerja::getKKP(int kekayaan){
    return kekayaan - KTKP;
}

/* Menghitung kekayaan pemain */
int Pekerja::hitungKekayaan(){
    // Kekayaan dari inventory
    return 0;
}

/* Menghitung pajak yang harus dibayar oleh pemain */
int Pekerja::hitungPajak(int KKP){
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