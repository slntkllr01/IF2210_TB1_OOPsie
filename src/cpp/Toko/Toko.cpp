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

void Toko::showInventory(Loader config) {
    cout << "-- LIMITED STOCK --" << endl;
    for (int i = 0; i < InvLength(); i++) {
        cout << i + 1 <<  getInventory()[i].getNama() << " - " << getInventory()[i].getHarga() << " (" << getInventory()[i].getStok() << ")" << endl;
    }
    cout << endl;
    cout << "-- UNLIMITED STOCK --" << endl;
    cout << endl;
    cout << "-- Hewan --" << endl;
    for (int i = 0; i < config.configHewan.size(); i++) {
        cout << i + 1 << config.configHewan[i]->get_name() << " - " << config.configHewan[i]->get_price() << endl;
    }
    cout << endl;
    cout << "-- Tumbuhan --" << endl;
    for (int i = 0; i < config.configTanaman.size(); i++) {
    cout << i + 1 << config.configTanaman[i].get_name() << " - " << config.configTanaman[i].get_price() << endl;
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
