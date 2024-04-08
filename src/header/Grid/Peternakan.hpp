#ifndef _PETERNAKAN_HPP
#define _PETERNAKAN_HPP
#include "GridMap.hpp"
#include "../../header/Produk/Produk.hpp"
#include "../../header/Hewan/Hewan.hpp"
class Peternakan{
    private:
        int baris;
        int kolom;
        Grid<Hewan> kotak;
        int charBarisMaksimal;
        int charKolomMaksimal;
        
    public:
        // Constructor
        Peternakan(int, int);

        ~Peternakan();

        bool isLokasiValid(string);
        void Ternak(string, Hewan*); //Menambahkan ternak ke slot lahan

        void Panen(string); //Memanen hewan dengan kode yang sama dengan inputan
        void CetakPeternakan();

        bool isFull(); //Mengecek apakah penyimpanan sudah penuh atau belum

        bool isEmpty();

        void BeriMakan(Produk*);

        bool isSiapPanen(Hewan*); //Mengecek apakah suatu hewan siap panen atau tidak
};

#endif