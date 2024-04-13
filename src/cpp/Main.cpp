#include <iostream>
#include "../header/Game/Game.hpp"
#include "../header/Exception/Exception.hpp"
using namespace std;

int main(){
    int method;
    bool stop=false;
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

// g++ -o HM Main.cpp