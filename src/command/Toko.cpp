#include "src/header/Toko/Toko.hpp"
#include "src/header/Loader/Loader.hpp"

using namespace std;

void beli(Loader config, Toko toko) {
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    cout << endl;
    cout << "-- LIMITED STOCK --" << endl;
    for (int i = 0; i < toko.InvLength(); i++) {
        cout << i + 1 <<  toko.getInventory()[i].getNama() << " - " << toko.getInventory()[i].getHarga() << " (" << toko.getInventory()[i].getStok() << ")" << endl;
    }
    cout << "-- UNLIMITED STOCK --" << endl;
    cout << endl;
    cout << "-- Hewan --" << endl;
    for (int i = 0; i < config.configHewan.size(); i++) {
        cout << i + 1 << config.configHewan[i]->get_name() << " - " << config.configHewan[i]->get_price() << endl;
    }
    cout << endl;
    cout << "-- Tumbuhan --" << endl;
    for (int i = 0; i < config.configTanaman.size(); i++) {
    cout << i + 1 << config.configTanaman[i].get_name() << " - " << config.configTanaman[i].get_price() << endl;
    }

    // Pusyenk 7 keliling
}

void jual() {
    // Butuh Inventory

    // Alur :
    // showInventory();
    cout << "Silahkan pilih petak yang ingin Anda Jual!" << endl;
    // cin >> ...
    
}

