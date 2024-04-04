#include "Pemain.hpp"

Pemain::Pemain() : username(""), peran(""), inventory(Inventory()), uang(50), beratBadan(40) {}

Pemain::Pemain(string username, string peran, Inventory inventory, int uang, int beratBadan) : username(username), peran(peran), inventory(inventory), uang(uang), beratBadan(beratBadan) {}

Pemain::~Pemain() {}

string Pemain::getUsername() {
    return username;
}

