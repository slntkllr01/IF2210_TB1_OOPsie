#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Produk {
    private:
        vector<map<int, int>> inventory;
    public:
};

class Barang {
    private:
        int id;
        string nama;
        double harga;
        string tipe;
    public:
        Barang(int id, string nama, double harga, string tipe);
};

#endif