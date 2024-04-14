#include <iostream>
#include "../header/Pemain/Walikota.hpp"
#include "../header/Pemain/Petani.hpp"
#include "../header/Pemain/Peternak.hpp"
#include "../header/Game/Game.hpp"
#include "../header/Toko/Toko.hpp"
#include "../header/Exception/Exception.hpp"
using namespace std;

// int main(){
//     int method;
//     // bool valid = false;
//     bool stop=false;
//     try{
//         ConfigLoader& loader = ConfigLoader::getInstance();
//         loader.initConfig("tanaman.txt","hewan.txt","product.txt","recipe.txt","misc.txt");
//         cout << "Selamat datang di Harvest Moon~" << endl;
//         ListPemain listPemain;
//         string ans;
//         while (!stop){
//             cout << "Pilih metode untuk inisialisasi:" << endl;
//             cout << "1. Load state" << endl;
//             cout << "2. Nonload, use template" << endl;
//             cout << "> ";
//             cin >> method;
//             if (method == 1){   //muat state
//                 bool stop1 = false;
//                 while(!stop1){
//                     cout << "Apakah Anda ingin memuat state? (y/n)";
//                     cin >> ans;
//                     if (ans == "y"){
//                         stop = true;
//                         stop1 = true;
//                         string dir;
//                         // while (!valid){
//                             cout << "Masukkan lokasi berkas state: ";
//                             cin >> dir;
//                         // }
//                         // checkvalidasi muat?
//                         // muat state
//                     }
//                     else if (ans =="n"){
//                         cout << "Muat state dibatalkan." << endl;
//                         stop1 = true;
//                     }
//                     else{
//                         cout << "Masukan tidak valid." << endl;
//                     }
//                 }

//             }
//             else if (method == 2){     //nonload
//                 stop = true;
//                 Petani* newPetani1 = new Petani("Petani1");
//                 listPemain.add_Pemain(newPetani1);
//                 Peternak* newPeternak1 = new Peternak("Peternak1");
//                 listPemain.add_Pemain(newPeternak1);
//                 Walikota* newWalikota1 = Walikota::getInstance("Walikota"); //bener kah
//                 listPemain.add_Pemain(newWalikota1);
//             }
//             else{
//                 cout << "Masukan tidak valid. Masukan pilihan metode insialisasi 1 (config) atau 2 (nonconfig)." << endl;
//             }
//         }
//         Game game = Game(listPemain);
//         game.start_game();
//     }
//     catch (const exception& e){
//         cerr << "Exception caught: " << e.what() << endl;
//     }
    
// }


// int main(){
//     ListPemain listPemain;
//     Petani* newPetani1 = new Petani("Petani1");
//     listPemain.add_Pemain(newPetani1);
//     Peternak* newPeternak1 = new Peternak("Peternak1");
//     listPemain.add_Pemain(newPeternak1);
//     Walikota* newWalikota1 = Walikota::getInstance("Walikota"); //bener kah
//     listPemain.add_Pemain(newWalikota1);
// }
// g++ -o main src/command/addPemain.cpp src/cpp/Main.cpp src/cpp/Game/Game.cpp src/cpp/Grid/Inventory.cpp src/cpp/Grid/Ladang.cpp src/cpp/Grid/Peternakan.cpp src/cpp/Item/Item.cpp src/cpp/ListPemain/ListPemain.cpp src/cpp/Pemain/Pekerja.cpp src/cpp/Pemain/Pemain.cpp src/cpp/Pemain/Petani.cpp src/cpp/Pemain/Walikota.cpp src/cpp/Produk/Produk.cpp src/cpp/Save/Save.cpp src/cpp/Tanaman/Tanaman.cpp src/cpp/Toko/Toko.cpp