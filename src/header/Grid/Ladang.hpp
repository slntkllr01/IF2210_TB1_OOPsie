#ifndef _LADANG_HPP
#define _LADANG_HPP
#include "GridMap.hpp"
#include "../../header/Produk/Produk.hpp"
#include "../../header/Tanaman/Tanaman.hpp"
class Ladang: public Grid<Tanaman>{
    private:
        int baris;
        int kolom;
        
    public:
        // Constructor
        Ladang(int, int);

        ~Ladang();

        void Tanam(string); //Menambahkan tanaman ke slot lahan

        void Panen(string); //Memanen tanaman dengan kode yang sama dengan inputan
        void CetakLadang();

        bool isFull(); //Mengecek apakah ladang sudah penuh atau belum

        bool isEmpty(); //Mengecek apakah ladang kosong atau tidak

        bool isSiapPanen(Tanaman); //Mengecek apakah tanaman siap dipanen

};

#endif