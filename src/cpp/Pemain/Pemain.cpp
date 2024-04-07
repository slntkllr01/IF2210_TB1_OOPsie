#include "../../header/Pemain/Pemain.hpp"

/* Default Constructor */
Pemain::Pemain() : username(""), peran(""), inventory(Inventory()), uang(50), beratBadan(40) {}

/* User-Defined Constructor */
Pemain::Pemain(string username, string peran) : username(username), peran(peran), inventory(Inventory()), uang(50), beratBadan(40) {}

/* Destructor */
Pemain::~Pemain() {}

/* Getter */
string Pemain::getUsername() const{
    return username;
}
string Pemain::getPeran() const{
    return peran;
}

/* Makan */
void Pemain::makan(Produk produk){
    beratBadan += produk.getAddedWeight();
}