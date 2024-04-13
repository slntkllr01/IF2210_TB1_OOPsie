#include "../../header/Pemain/Petani.hpp"

/* Default Constructor */
Petani::Petani() : Pekerja("", "Petani", 13), ladang(Ladang()) {}

/* User-Defined Constructor */
Petani::Petani(string username) : Pekerja(username, "Petani", 13), ladang(Ladang()) {}

/* Destructor */
Petani::~Petani() {}

/* Getter */
Ladang Petani::getLadang() const {
    return ladang;
}

/* Menghitung kekayaan petani */
int Petani::hitungKekayaan(){
    // Kekayaan dari inventory
    int kekayaan_inventory = Pekerja::hitungKekayaan();
    // Kekayaan dari ladang
    return 0;
}

/* Menanam tanaman di ladang */
void Petani::tanam(int x, int y){

}

/* Memanen tanaman yang ada di ladang */
void Petani::panenTanaman(int x, int y){

}