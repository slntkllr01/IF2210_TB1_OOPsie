#include "../../header/Pemain/Petani.hpp"

/* Static variable */
int Petani::ktkp = 13;

/* Default Constructor */
Petani::Petani() : Pemain("", "Petani"), ladang(Ladang()) {}

/* User-Defined Constructor */
Petani::Petani(string username, string peran) : Pemain(username, peran), ladang(Ladang()) {}

/* Destructor */
Petani::~Petani() {}

/* Menghitung pajak yang harus dibayar oleh petani */
int Petani::hitungPajak(){   
}
