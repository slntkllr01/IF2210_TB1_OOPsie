#ifndef _PETERNAKAN_HPP
#define _PETERNAKAN_HPP
#include "GridMap.hpp"
#include "../../header/Produk/Produk.hpp"
#include "../../header/Hewan/Hewan.hpp"
#include "../Loader/ConfigLoader.hpp"
#include <map>

class Peternakan : public Grid<Hewan*>{
    private:
        int baris;
        int kolom;
        int charBarisMaksimal;
        int charKolomMaksimal;
        //49 = 1
        //65 = A
        
    public:
        // Constructor
        Peternakan();

        ~Peternakan();

        bool isLokasiValid(string);
        
        void addHewan(Hewan*, string); // Ganti jadi ini

        Hewan* delHewan(string); // Ganti jadi ini
        
        void CetakPeternakanHelper();
        void CetakPeternakan();

        bool isFull(); //Mengecek apakah penyimpanan sudah penuh atau belum

        bool isEmpty();

        void BeriMakan(Produk*, string);

        //Grid<Hewan*> getKotak() const;

        bool isSiapPanen(string); //Mengecek apakah suatu hewan siap panen atau tidak

        //map<string, int> getListofSiapPanen() const;
};

#endif