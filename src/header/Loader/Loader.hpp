#ifndef _LOADER_HPP
#define _LOADER_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

#include "Hewan/Hewan.hpp"
#include "Hewan/Herbivora.hpp"
#include "Hewan/Karnivora.hpp"
#include "Hewan/Omnivora.hpp"
#include "Tanaman/Tanaman.hpp"
#include "Produk/Produk.hpp"
#include "Bangunan/Bangunan.hpp"


class Loader {
public:
    vector<Tanaman> configTanaman;
    vector<Hewan*> configHewan;
    vector<Produk> configProduk;
    vector<Bangunan> configBangunan;

    Loader::~Loader(){
        for (Hewan* hewan : configHewan){
            delete h;
        }
    }

    void loadTanaman(const string& filename){
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            int id;
            string code;
            string name;
            string type;
            int duration;
            int price;
            if (iss >> id >> code >> name >> type >> duration >> price){
                configTanaman.push_back(Tanaman(id, code, name, type, duration, price));
            }
        }
    }

    void loadHewan(const string& filename){
        ifstream file(filename);
        string line;
        while (getline(file, line)){
            istringstream iss(line);
            int id;
            string code;
            string name;
            int weight;
            int price;
            if (iss >> id >> code >> name >> type >> weight >> price){
                if (type == "HERBIVORE"){
                    configHewan.push_back(new Herbivora(id, code, name, weight, price));
                } else if (type == "CARNIVORE"){
                    configHewan.push_back(new Karnivora(id, code, name, weight, price));
                } else if (type == "OMNIVORE"){
                    configHewan.push_back(new Omnivora(id, code, name, weight, price));
                } // perlu exception?
            } // perlu exception?
        }
    }

    void loadProduk(const string& filename){
        ifstream file(filename);
        string line;
        while (getline(file, line)){
            istringstream iss(line);
            int id;
            string code;
            string name;
            string type;
            string origin;
            int added_weight;
            int price;
            if (iss >> id >> code >> name >> type >> origin >> added_weight >> price){
                configProduk.push_back(Produk(id, code, name, type, origin, added_weight, price));
            }
        }
    }

    void loadBangunan(const string& filename){
        ifstream file(filename);
        string line;
        while (getline(file, line)){
            istringstream iss(line);
            int id;
            string code;
            string name;
            // belum selesai
        }
    }
};

#endif