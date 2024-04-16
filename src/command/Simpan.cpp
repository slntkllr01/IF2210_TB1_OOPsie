#include <iostream>
#include <fstream>
#include "command.hpp"
#include "../header/Save/Save.hpp"
#include "../header/Exception/Exception.hpp"
using namespace std;

void save(ListPemain list, Toko toko) {
    string filename;
    cout << "Masukkan lokasi berkas state: ";
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        throw InvalidPath();
    }

    try {
        Save::saveState(list, toko, filename);
        cout << "State berhasil disimpan" << endl;
    } catch (const std::exception& e) {
        cerr << "Gagal menyimpan state: " << e.what() << endl;
    }
}
