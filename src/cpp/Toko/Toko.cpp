#include "../../header/Toko/Toko.hpp"

using namespace std;

Toko::Toko() {
    addInvHewanandTanaman();
}

Toko::~Toko() {}

map<Item, int> Toko::getInventory() const {
    return this->inventory;
}

vector<Hewan*> Toko::getInvHewan() const {
    return this->invHewan;
}

vector<Tanaman> Toko::getInvTanaman() const {
    return this->invTanaman;
}

int Toko::InvLength() const {
    return this->inventory.size();
}

void Toko::transaksiBeli(Pemain* pemain, const Item* item, int kuantitas) {
    if (item->getItemType() != "Hewan" || item->getItemType() != "Tanaman") {
        for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
            if (itr->first.getName() == item->getName()) {
                if (itr->second - kuantitas > 0) {
                    itr->second -= kuantitas;
                } else {
                    inventory.erase(itr);
                }
            }
        }
    }
    pemain->beli(item, kuantitas);
}

void Toko::transaksiJual(Pemain* pemain, Item* item, int kuantitas) {
    if (item->getItemType() != "Hewan" || item->getItemType() != "Tanaman") {
        bool found = false;

        for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
            if (itr->first.getName() == item->getName()) {
                itr->second += kuantitas;
                found = true;
                break;
            }
        }

        if (!found) {
            inventory.insert({*item, 0});
        }   
    }
    pemain->jual(item, kuantitas);
}

void Toko::showInventory() {
    cout << "-- BANGUNAN DAN PRODUK --" << endl;
    int i = 0;
    for (const auto& itr : inventory){
        cout << "["<< i + 1 << "] " << itr.first.getName() << " - " << itr.first.getPrice() << " (Stok: " << itr.second << ")" << endl;
        i++;
        // if (itr.first.getItemType() != "Hewan" && itr.first.getItemType() != "Tanaman"){
        //     cout << "["<< i + 1 << "] " << itr.first.getName() << " - " << itr.first.getPrice() << " (Stok: " << itr.second << ")" << endl;
        //     i++;
        // }
    }
    cout << endl;
}

int Toko::getStock(Item* item) {
    for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
        if (itr->first.getName() == item->getName()) {
            return itr->second;
        }
    }
    return 0;
}

void Toko::addBarang(Item* item, int jumlah){
    bool found = false;
    for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
        if (itr->first.getName() == item->getName()) {
            itr->second += jumlah;
            found = true;
            break;
        }
    }

    if (!found) {
        inventory.insert({*item, jumlah});
    }
}

void Toko::addInvHewanandTanaman() {
    ConfigLoader& config = ConfigLoader::getInstance();
    for (const auto& itr : config.hewanConfigs) {
        if (itr.second.type == "HERBIVORE") {
            Herbivora* hewan = new Herbivora(itr.first);
            this->invHewan.push_back(hewan);
        } else if (itr.second.type == "CARNIVORE") {
            Karnivora* hewan = new Karnivora(itr.first);
            this->invHewan.push_back(hewan);
        } else if (itr.second.type == "OMNIVORE") {
            Omnivora* hewan = new Omnivora(itr.first);
            this->invHewan.push_back(hewan);
        }   
    }

    for (const auto& itr : config.tanamanConfigs) {
        Tanaman tanaman(itr.first);
        this->invTanaman.push_back(tanaman);
    }
}