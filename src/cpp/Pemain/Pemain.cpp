#include "Pemain.hpp"

/* Default Constructor */
Pemain::Pemain() : username(""), peran(""), inventory(Inventory()), uang(50), beratBadan(40) {}

/* User-Defined Constructor */
Pemain::Pemain(string username, string peran, Inventory inventory, int uang, int beratBadan) : username(username), peran(peran), inventory(inventory), uang(uang), beratBadan(beratBadan) {}

/* Destructor */
Pemain::~Pemain() {}

/* Getter */
string Pemain::getUsername(){
    return username;
}

/* Makan */
void Pemain::makan(Produk produk){
    beratBadan += produk.getAddedWeight();
}
