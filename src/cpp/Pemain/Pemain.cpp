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

Inventory Pemain::getInventory() const{
    return inventory;
}

int Pemain::getUang() const{
    return uang;
}

int Pemain::getBeratBadan() const{
    return beratBadan;
}

/* Makan */
void Pemain::makan(Produk* produk){
    beratBadan += produk->getAddedWeight();
}

// JUAL
void Pemain::jual(Item item, int kuantitas){}

// IS MENANG
bool Pemain::isMenang(){}


bool Pemain::operator==(const Pemain* other) const{
    if((this -> username == other->getUsername()) && (this -> peran == other -> getPeran())){
        return true;
    }
    else{
        return false;
    }
}

