#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP
#include "GridMap.hpp"
#include "../Produk/Produk.hpp"
#include "../Loader/Loader.hpp"
class Inventory: public Grid<Produk>{
    private:
        int baris;
        int kolom;
    public:
        // Constructor
        Inventory();

        Inventory(int, int);

        ~Inventory();

        void SimpanBarang(); //Auto

        void SimpanBarang(string); //Input Manual

        Produk AmbilBarang(string); //Delete

        void Makan(string); 

        void CetakPenyimpanan();

        int SlotTersisa(); //Untuk diprint setelah cetak penyimpanan

        bool isFull(); //Mengecek apakah penyimpanan sudah penuh atau belum

        bool isEmpty();

        bool isThereMakanan(); //Mengecek apakah ada makanan

};

#endif