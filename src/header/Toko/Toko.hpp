#ifndef TOKO_HPP
#define TOKO_HPP

#include <iostream>
#include <vector>
#include "header/Pemain/Pemain.hpp"
#include "src/header/Loader/Loader.hpp"

using namespace std;

class Toko {
    private:
        vector<Barang> inventory;
    public:
        vector<Barang> getInventory() const;
        int InvLength() const;
        void terbeli(string namaBarang);
        void dijual();
        void showInventory(Loader config);
        Toko& operator+=(const Barang& barang);
        Toko& operator-=(const string& namaBarang);
};

class Barang {
    private:
        int id;
        string nama;
        double harga;
        string tipe;
        int stok;
    public:
        Barang(int id, string nama, double harga, string tipe, int stok);
        int getStok() const;
        void tambahStok(int num);
        void kurangiStok(int num);
        double getHarga() const;
        string getNama() const;
        ~Barang();
};

#endif