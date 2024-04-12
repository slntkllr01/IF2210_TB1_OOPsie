#include "src/header/Toko/Toko.hpp"

using namespace std;

map<Item, int> Toko::getInventory() const {
    return this->inventory;
}

int Toko::InvLength() const {
    return this->inventory.size();
}

void transaksiBeli() {
    // TO-DO
}

void transaksiJual() {
    // TO-DO
}

Toko& Toko::operator+=(const Item& barang) {
    // Cek jika barang sudah ada dalam inventory
    auto iter = inventory.find(barang);
    if (iter != inventory.end()) {
        iter->second++; // Asumsi getprice() memberikan stok yang akan ditambahkan
    } else {
        inventory[barang]++; // Asumsi getprice() mengembalikan stok awal
    }
    return *this;
}



Toko& Toko::operator-=(const Item& barang) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->first.getName() == barang.getName()) {
            inventory.erase(it);
            break;
        }
    }
    return *this;
}

void Toko::showInventory(Loader config) { // SOON gue revisi
    cout << "-- LIMITED STOCK --" << endl;
    for (size_t i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i].getNama() << " - " << inventory[i].getPrice() << " (" << inventory[i].getStok() << ")" << endl;
    }
    cout << endl;
    cout << "-- UNLIMITED STOCK --" << endl;
    cout << endl;
    cout << "-- Hewan --" << endl;
    for (size_t i = 0; i < config.configHewan.size(); i++) {
        cout << i + 1 << ". " << config.configHewan[i]->get_name() << " - " << config.configHewan[i]->get_price() << endl;
    }
    cout << endl;
    cout << "-- Tumbuhan --" << endl;
    for (size_t i = 0; i < config.configTanaman.size(); i++) {
        cout << i + 1 << ". " << config.configTanaman[i].get_name() << " - " << config.configTanaman[i].get_price() << endl;
    }
}
