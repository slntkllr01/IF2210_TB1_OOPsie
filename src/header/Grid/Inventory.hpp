#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP
#include "GridMap.hpp"
#include "../Produk/Produk.hpp"
#include "../Item/Item.hpp"
#include "../Loader/ConfigLoader.hpp"
#include <vector>
using namespace std;

class Inventory: public Grid<Item*>{
    private:
        int baris;
        int kolom;
        int charBarisMaksimal;
        int charKolomMaksimal;
        //49 = 1
        //65 = A

    public:
        // Constructor
        Inventory();

        ~Inventory();

        bool isLokasiValid(string);

        void SimpanBarang(Item*); //Auto

        void SimpanBarang(Item*, string); //Input Manual

        Item* AmbilBarang(string); //Delete

        bool IsMakanan(string); 

        void CetakPenyimpananHelper();
        void CetakPenyimpanan();

        int SlotTersisa(); //Untuk diprint setelah cetak penyimpanan

        bool isFull(); //Mengecek apakah penyimpanan sudah penuh atau belum

        bool isEmpty();

        bool isThereMakanan(); //Mengecek apakah ada makanan

        bool isThereTanaman();

        bool isThereMakanan(string);

        bool isThereHewan();

        string CekJenis(string); //Cek Type dari Item yang ada di parameter string petak

        static map<Item*, pair<int, vector<string>>> listBahanBangunan(map<string, Item*> isi);
};

#endif