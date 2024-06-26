#ifndef _STATELOADER_HPP
#define _STATELOADER_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <vector>
#include "../ListPemain/ListPemain.hpp"
#include "../Pemain/Pemain.hpp"
#include "../Pemain/Petani.hpp"
#include "../Pemain/Peternak.hpp"
#include "../Pemain/Walikota.hpp"
#include "../Toko/Toko.hpp"
#include "../Hewan/Herbivora.hpp"
#include "../Hewan/Karnivora.hpp"
#include "../Hewan/Omnivora.hpp"
#include "ConfigLoader.hpp"

using namespace std;

class StateLoader {
public:
    static void loadState(const string& filename, ListPemain& list_pemain, Toko& toko){
        ifstream file(filename);
        if (!file.is_open()){
            throw runtime_error("Unable to open file: " + filename);
        }
        int num_players;
        file >> num_players;
        string line;
        getline(file, line); 

        for (int i = 0; i < num_players; i++){
            getline(file, line);
            istringstream iss(line);
            string username, role;
            int berat, uang;
            iss >> username >> role >> berat >> uang;
            // Membuat pemain
            Pemain* pemain;
            if (role == "Petani"){
                pemain = new Petani(username, uang, berat);
                // Load inventory
                pemain->setInventory(loadInventory(file));
                // Load state ladang
                loadLadang(file, dynamic_cast<Petani*>(pemain));
            } else if (role == "Peternak"){
                pemain = new Peternak(username, uang, berat);
                // Load inventory
                pemain->setInventory(loadInventory(file));
                // load state peternakan
                loadPeternakan(file, dynamic_cast<Peternak*>(pemain));
            } else if (role == "Walikota"){
                // buat instance walikota
                pemain = Walikota::getInstance(username);
                dynamic_cast<Walikota*>(pemain)->initialize(username, uang, berat);
                // Load inventory
                pemain->setInventory(loadInventory(file));
            }

            list_pemain.add_Pemain(pemain);
        }
        // Load state toko
        loadTokoState(file, toko);
    }

private:
    static Inventory loadInventory(ifstream& file){
        Inventory inventory;
        string line;
        getline(file, line);
        istringstream iss2(line);
        int jumlah_item;
        iss2 >> jumlah_item;
        for (int j = 0; j < jumlah_item; j++){
            getline(file, line);
            istringstream iss3(line);
            string item_name;
            iss3 >> item_name;
            Item* item = createItemByName(item_name);
            inventory.SimpanBarang(item);
        }
        return inventory;
    }

    static void loadLadang(ifstream& file, Petani* petani){
        int jumlah_tanaman;
        string line;
        getline(file, line);
        istringstream iss4(line);
        iss4 >> jumlah_tanaman;
        for (int k = 0; k < jumlah_tanaman; k++){
            getline(file, line);
            istringstream iss5(line);
            string lokasi, nama_tanaman;
            int umur;
            iss5 >> lokasi >> nama_tanaman >> umur;
            Tanaman* tanaman = dynamic_cast<Tanaman*>(createItemByName(nama_tanaman));
            tanaman->set_umur(umur);
            petani->tanam(tanaman, lokasi);
        }
    }

    static void loadPeternakan(ifstream& file, Peternak* peternak){
        int jumlah_hewan;
        string line;
        getline(file, line);
        istringstream iss6(line);
        iss6 >> jumlah_hewan;
        for (int k = 0; k < jumlah_hewan; k++){
            getline(file, line);
            istringstream iss7(line);
            string lokasi, nama_hewan;
            int berat;
            iss7 >> lokasi >> nama_hewan >> berat;
            Hewan* hewan = dynamic_cast<Hewan*>(createItemByName(nama_hewan));
            hewan->set_actualweight(berat);
            peternak->ternak(hewan, lokasi);
        }
    }

    static void loadTokoState(ifstream& file, Toko& toko){
        int banyak_item;
        file >> banyak_item;
        for (int l = 0; l < banyak_item; l++){
            string nama_item;
            int jumlah;
            file >> nama_item >> jumlah;
            Item* item = createItemByName(nama_item);
            toko.addBarang(item, jumlah);
        }
    }

    static Item* createItemByName(const string& itemName){
        ConfigLoader& config = ConfigLoader::getInstance();
        string itemType = config.getItemType(itemName);
        if (itemType == "Tanaman"){
            return new Tanaman(itemName);
        } else if (itemType == "HERBIVORE"){
            return new Herbivora(itemName);
        } else if (itemType == "CARNIVORE"){
            return new Karnivora(itemName);
        } else if (itemType == "OMNIVORE"){
            return new Omnivora(itemName);
        } else if (itemType == "PRODUCT_MATERIAL_PLANT" || itemType == "PRODUCT_FRUIT_PLANT"){
            return new produkTumbuhan(itemName);
        } else if (itemType == "PRODUCT_ANIMAL"){
            return new produkHewan(itemName);
        } else if (itemType == "Bangunan"){
            return new Bangunan(itemName);
        } else {
            throw runtime_error("Invalid item type");
        }
    }
};

#endif