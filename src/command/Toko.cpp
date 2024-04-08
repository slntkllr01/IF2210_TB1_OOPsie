#include "src/header/Toko/Toko.hpp"
#include "src/header/Loader/Loader.hpp"

using namespace std;

void beli(Loader config, Toko toko) {
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    cout << endl;
    toko.showInventory(config);
    cout << endl;
    // Pusyenk 7 keliling
}

void jual(Pemain* p) {
    // Butuh Inventory

    // Alur :
    // showInventory();
    cout << "Silahkan pilih petak yang ingin Anda Jual!" << endl;
    // cin >> ...
    
}

