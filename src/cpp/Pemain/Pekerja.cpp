#include "Pekerja.hpp"

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
    return uang;
}