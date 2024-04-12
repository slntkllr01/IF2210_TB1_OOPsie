#ifndef _CONFIGLOADER_HPP
#define _CONFIGLOADER_HPP

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class TanamanConfig {
public:
    string code;
    string name;
    string type;
    int duration;
    int price;
    TanamanConfig(string code, string name, string type, int duration, int price) : code(code), name(name), type(type), duration(duration), price(price) {}
};

class HewanConfig {
public:
    string code;
    string name;
    string type;
    int weight;
    int price;
    HewanConfig(string code, string name, string type, int weight, int price) : code(code), name(name), type(type), weight(weight), price(price) {}
};

class ProdukConfig {
public:
    string code;
    string name;
    string type;
    string origin;
    int added_weight;
    int price;
    ProdukConfig(string code, string name, string type, string origin, int added_weight, int price) : code(code), name(name), type(type), origin(origin), added_weight(added_weight), price(price) {}
};

class BangunanConfig {
public:
    string code;
    string name;
    int price;
    map<string, int> resep;
    BangunanConfig(string code, string name, int price, map<string, int> resep) : code(code), name(name), price(price), resep(resep) {}
};

class ConfigLoader {
private:
    ConfigLoader() {}
    ConfigLoader(const ConfigLoader&) = delete;
    ConfigLoader& operator=(const ConfigLoader&) = delete;
public:
    static ConfigLoader& getInstance(){
        static ConfigLoader instance;
        return instance;
    }
    /* Atribut */ 
    int uangMenang;
    int beratMenang;
    pair<int, int> ukuranInventory;
    pair<int, int> ukuranLahan;
    pair<int, int> ukuranPeternakan;
    map<int, TanamanConfig> tanamanConfigs;
    map<int, HewanConfig> hewanConfigs;
    map<int, ProdukConfig> produkConfigs;
    map<int, BangunanConfig> bangunanConfigs;

    /* Inisialisasi konfigurasi */
    void initConfig(const string& filenameTanaman, const string& filenameHewan, const string& filenameProduk, const string& filenameBangunan, const string& filenameMisc){
        loadTanaman(filenameTanaman);
        loadHewan(filenameHewan);
        loadProduk(filenameProduk);
        loadBangunan(filenameBangunan);
        loadMisc(filenameMisc);
    }

    /* Destructor */
    ~ConfigLoader() {}

    /* Load konfigurasi untuk tanaman */
    void loadTanaman(const string& filename){
        ifstream file(filename);
        string line;
        while(getline(file, line)){
            stringstream ss(line);
            string code, name, type;
            int id, duration, price;
            ss >> id >> code >> name >> type >> duration >> price;
            tanamanConfigs.insert({id, TanamanConfig(code, name, type, duration, price)});
        }
    }

    /* Load konfigurasi untuk hewan */
    void loadHewan(const string& filename){
        ifstream file(filename);
        string line;
        while(getline(file, line)){
            stringstream ss(line);
            string code, name, type;
            int id, weight, price;
            ss >> id >> code >> name >> type >> weight >> price;
            hewanConfigs.insert({id, HewanConfig(code, name, type, weight, price)});
        }
    }

    /* Load konfigurasi untuk produk */
    void loadProduk(const string& filename){
        ifstream file(filename);
        string line;
        while(getline(file, line)){
            stringstream ss(line);
            string code, name, type, origin;
            int id, added_weight, price;
            ss >> id >> code >> name >> type >> origin >> added_weight >> price;
            produkConfigs.insert({id, ProdukConfig(code, name, type, origin, added_weight, price)});
        }
    }

    /* Load konfigurasi untuk bangunan */
    void loadBangunan(const string& filename){
        ifstream file(filename);
        string line;
        while(getline(file, line)){
            stringstream ss(line);
            string code, name;
            int id, price;
            map<string, int> resep;
            ss >> id >> code >> name >> price;
            string resepStr;
            getline(file, resepStr);
            stringstream ssResep(resepStr);
            string item;
            int jumlah;
            while(ssResep >> item >> jumlah){
                resep.insert({item, jumlah});
            }
            bangunanConfigs.insert({id, BangunanConfig(code, name, price, resep)});
        }
    }

    /* Load konfigurasi untuk lain-lain */
    void loadMisc(const string& filename){
        ifstream file(filename);
        file >> uangMenang;
        file >> beratMenang;
        file >> ukuranInventory.first >> ukuranInventory.second;
        file >> ukuranLahan.first >> ukuranLahan.second;
        file >> ukuranPeternakan.first >> ukuranPeternakan.second;
    }
};

#endif