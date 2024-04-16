#include "../../header/Toko/Toko.hpp"

using namespace std;

Toko::Toko() {}

Toko::~Toko() {}

map<Item, int> Toko::getInventory() const {
    return this->inventory;
}

int Toko::InvLength() const {
    return this->inventory.size();
}

void Toko::transaksiBeli(Pemain* pemain, Item* item, int kuantitas) {
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
    ConfigLoader& config = ConfigLoader::getInstance();
    cout << "-- LIMITED STOCK --" << endl;
    int i = 0;
    for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
        cout << "["<< i + 1 << "] " << itr->first.getName() << " - " << itr->first.getPrice() << " (" << itr->second << ")" << endl;
    }
    cout << endl;
    cout << "-- UNLIMITED STOCK --" << endl;
    cout << endl;
    cout << "-- Hewan --" << endl;
    for (auto itr = config.hewanConfigs.begin(); itr != config.hewanConfigs.begin(); ++itr) {
        cout << "[H"<< itr->first << "] " << itr->second.name << " - " << itr->second.price << endl;
    }
    cout << endl;
    cout << "-- Tanaman --" << endl;
    for (auto itr = config.tanamanConfigs.begin(); itr != config.tanamanConfigs.begin(); ++itr) {
        cout << "[T"<< itr->first << "] " << itr->second.name << " - " << itr->second.price << endl;
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