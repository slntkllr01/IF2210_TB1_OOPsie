#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP
#include "GridMap.hpp"
#include "../Produk/Produk.hpp"
#include "../Item/Item.hpp"
#include "../Loader/ConfigLoader.hpp"

class Inventory: public Grid<Item>{
    private:
        int baris;
        int kolom;
    public:
        // Constructor
        Inventory();

        Inventory(int, int);

        ~Inventory();

        void SimpanBarang(); //Auto

        void SimpanBarang(Item*, string); //Input Manual

        Item* AmbilBarang(string); //Delete

        void Makan(string); 

        void CetakPenyimpanan();

        int SlotTersisa(); //Untuk diprint setelah cetak penyimpanan

        bool isFull(); //Mengecek apakah penyimpanan sudah penuh atau belum

        bool isEmpty();

        bool isThereMakanan(); //Mengecek apakah ada makanan

        bool isThereTanaman();

        string CekJenis(string); //Cek Type dari Item yang ada di parameter string petak
};

#endif