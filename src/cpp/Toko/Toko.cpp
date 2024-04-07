#include "src/header/Toko/Toko.hpp"

using namespace std;

vector<Barang> Toko::getInventory() const {
    return this->inventory;
}

int Toko::InvLength() const {
    return this->inventory.size();
}

void Toko::terbeli(string namaBarang) {
    if (!this->inventory.empty()) {
        *this -= namaBarang;
    }
}
        
void Toko::dijual() {

}

Toko& Toko::operator+=(const Barang& barangBaru) {
    bool found = false;
    for (auto& barang : inventory) {
        if (barang.getNama() == barangBaru.getNama()) {
            barang.tambahStok(barangBaru.getStok());
            found = true;
            break;
        }
    }
    if (!found) {
        inventory.push_back(barangBaru);
    }

    return *this;
}


Toko& Toko::operator-=(const string& namaBarang) {
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        if (it->getNama() == namaBarang) {
            inventory.erase(it);
            break;
        }
    }
}

Barang::Barang(int id, string nama, double harga, string tipe, int stok) {
    this->id = id;
    this->nama = nama;
    this->harga = harga;
    this->tipe = tipe;
    this->stok = stok;
}

string Barang::getNama() const {
    return this->nama;
}

int Barang::getStok() const {
    return this->stok;
}

void Barang::tambahStok(int num) {
    this->stok += num;
}

void Barang::kurangiStok(int num) {
    this->stok -= num;
}

Barang::~Barang() {
}
