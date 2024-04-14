#ifndef _PETERNAKAN_HPP
#define _PETERNAKAN_HPP
#include "GridMap.hpp"
#include "../../header/Produk/Produk.hpp"
#include "../../header/Hewan/Hewan.hpp"
class Peternakan{
    private:
        int baris;
        int kolom;
        Grid<Hewan*> kotak;
        int charBarisMaksimal;
        int charKolomMaksimal;
        //49 = 1
        //65 = A
        
    public:
        // Constructor
        Peternakan(); // ukuran ambil dari config

        Peternakan(int, int);

        ~Peternakan();

        bool isLokasiValid(string);
        
        void Ternak(string, Hewan*); //Menambahkan ternak ke slot lahan
        void addHewan(Hewan*, string); // Ganti jadi ini

        void Panen(string); //Memanen hewan dengan kode yang sama dengan inputan
        Hewan* delHewan(string); // Ganti jadi ini
        
        void CetakPeternakanHelper();
        void CetakPeternakan();

        bool isFull(); //Mengecek apakah penyimpanan sudah penuh atau belum

        bool isEmpty();

        void BeriMakan(Produk*);

        Grid<Hewan*> getKotak() const;

        bool isSiapPanen(Hewan*); //Mengecek apakah suatu hewan siap panen atau tidak
};

#endif