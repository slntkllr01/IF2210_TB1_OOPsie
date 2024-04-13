#include <iostream>
#include "../header/Pemain/Walikota.hpp"
#include "../header/Pemain/Petani.hpp"
#include "../header/Pemain/Peternak.hpp"
#include "../header/Game/Game.hpp"
#include "../header/Toko/Toko.hpp"
#include "../header/Exception/Exception.hpp"
using namespace std;

int main(){
    int method;
    bool stop=false;
    try{
        ConfigLoader& loader = ConfigLoader::getInstance();
        loader.initConfig("tanaman.txt","hewan.txt","product.txt","recipe.txt","misc.txt");
        cout << "Selamat datang di Harvest Moon~" << endl;
        ListPemain listPemain;
        while (!stop){
            cout << "Pilih metode untuk inisialisasi:" << endl;
            cout << "1. File Konfigurasi" << endl;
            cout << "2. Nonkonfigurasi" << endl;
            cout << "> ";
            cin >> method;
            if (method == 1){   //baca config
                stop = true;
                

            }
            else if (method == 2){     //nonconfig
                stop = true;
                Petani* newPetani1 = new Petani("Petani1");
                listPemain.add_Pemain(newPetani1);
                Peternak* newPeternak1 = new Peternak("Peternak1");
                listPemain.add_Pemain(newPeternak1);
                Walikota* newWalikota1 = Walikota::getInstance("Walikota"); //bener kah
                listPemain.add_Pemain(newWalikota1);
            }
            else{
                cout << "Masukan tidak valid. Masukan pilihan metode insialisasi 1 (config) atau 2 (nonconfig)." << endl;
            }
        }
        Game game = Game(listPemain);
        game.start_game();
    }
    catch (const exception& e){
        cerr << "Exception caught: " << e.what() << endl;
    }
    
}

// g++ -o main  src/command/Toko.cpp src/command/addPemain.cpp src/command/tanam.cpp src/command/ternak.cpp src/cpp/Main.cpp src/cpp/Bangunan/Bangunan.cpp src/cpp/Game/Game.cpp src/cpp/Grid/Inventory.cpp src/cpp/Grid/Ladang.cpp src/cpp/Grid/Peternakan.cpp src/cpp/Hewan/Herbivora.cpp src/cpp/Hewan/Hewan.cpp src/cpp/Hewan/Karnivora.cpp src/cpp/Hewan/Omnivora.cpp src/cpp/Item/Item.cpp src/cpp/ListPemain/ListPemain.cpp src/cpp/Pemain/Pekerja.cpp src/cpp/Pemain/Pemain.cpp src/cpp/Pemain/Petani.cpp src/cpp/Pemain/Walikota.cpp src/cpp/Produk/Produk.cpp src/cpp/Save/Save.cpp src/cpp/Tanaman/Tanaman.cpp src/cpp/Toko/Toko.cpp