#include "src/header/Toko/Toko.hpp"

using namespace std;

map<Item, int> Toko::getInventory() const {
    return this->inventory;
}

int Toko::InvLength() const {
    return this->inventory.size();
}

void Toko::transaksiBeli(Pemain pemain, Item item, int kuantitas) {
    if (item.getItemType() != "Hewan" || item.getItemType() != "Tanaman") {
        for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
            if (itr->first.getName() == item.getName()) {
                if (itr->second - kuantitas > 0) {
                    itr->second -= kuantitas;
                } else {
                    inventory.erase(itr);
                }
            }
        }
    }
    // Asumsikan sudah terimplementasi
    pemain.beli(item, kuantitas);
}

void Toko::transaksiJual(Pemain pemain, Item item, int kuantitas) {
    if (item.getItemType() != "Hewan" || item.getItemType() != "Tanaman") {
        bool found = false;

        for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
            if (itr->first.getName() == item.getName()) {
                itr->second += kuantitas;
                found = true;
                break;
            }
        }

        if (!found) {
            inventory.insert({item, 0});
        }   
    }
    // Asumsikan sudah terimplementasi
    pemain.jual(item, kuantitas);
}

void Toko::showInventory(ConfigLoader config) {
    cout << "-- LIMITED STOCK --" << endl;
    int i = 0;
    for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
        cout << i + 1 << ". " << itr->first.getName() << " - " << itr->first.getPrice() << " (" << itr->second << ")" << endl;
    }
    cout << endl;
    cout << "-- UNLIMITED STOCK --" << endl;
    cout << endl;
    cout << "-- Hewan --" << endl;
    for (auto itr = config.hewanConfigs.begin(); itr != config.hewanConfigs.begin(); ++itr) {
        cout << itr->first << ". " << itr->second.name << " - " << itr->second.price << endl;
    }
    cout << endl;
    for (auto itr = config.tanamanConfigs.begin(); itr != config.tanamanConfigs.begin(); ++itr) {
        cout << itr->first << ". " << itr->second.name << " - " << itr->second.price << endl;
    }
}
