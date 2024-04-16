#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include "../header/Save/Save.hpp"
#include "../header/Exception/Exception.hpp"
#include <sys/stat.h>
using namespace std;
namespace fs = experimental::filesystem;

void save(ListPemain list, Toko toko) {
    std::string filePath;
    std::cout << "Masukkan lokasi berkas state: ";
    std::cin >> filePath;

    fs::path p = filePath;

    if (!fs::exists(p.parent_path())) {
        throw InvalidPath();
    }

    try {
        Save::saveState(list, toko, filePath);
        cout << "State berhasil disimpan" << endl;
    } catch (const std::exception& e) {
        cerr << "Gagal menyimpan state: " << e.what() << endl;
    }
}
