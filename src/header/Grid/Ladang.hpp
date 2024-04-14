#ifndef _LADANG_HPP
#define _LADANG_HPP
#include "GridMap.hpp"
#include "../../header/Produk/Produk.hpp"
#include "../../header/Tanaman/Tanaman.hpp"
#include <iostream>
class Ladang: public Grid<Tanaman*>{
    private:
        int baris;
        int kolom;
        int charBarisMaksimal;
        int charKolomMaksimal;
        //49 = 1
        //65 = A
        
    public:
        // Constructor
        Ladang(); // ukuran dari config

        ~Ladang();

        bool isLokasiValid(string);

        void addTanaman(Tanaman*, string); // Ganti jadi ini

        Tanaman* delTanaman(string); // Ganti jadi ini
        
        void CetakLadangHelper();
        void CetakLadang();

        bool isFull(); //Mengecek apakah ladang sudah penuh atau belum

        bool isEmpty(); //Mengecek apakah ladang kosong atau tidak

        Grid<Tanaman*> getLadang() const;
        
        // getter
        Grid<Tanaman*> getKotak() const;
        
        //bool isSiapPanen(Tanaman); //Mengecek apakah tanaman siap dipanen

};

#endif