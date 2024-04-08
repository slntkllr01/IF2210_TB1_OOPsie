#include "../../header/Grid/Peternakan.hpp"
// Constructor
Peternakan::Peternakan(int b, int k){
    this->baris = b;
    this->kolom = k;
    this->charBarisMaksimal = 48 + b;
    this->charKolomMaksimal = 64 + k;
    //49 = 1
    //65 = A
}

Peternakan::~Peternakan(){
    
}

bool Peternakan::isLokasiValid(string k){
    if(k.size()!=3){ //Kalau string lokasi panjangnya bukan 3, pasti salah;
        return false;
    }
    else{ //Panjangnya udah tiga nih, tapi bisa aja diluar range baris dan kolom
        char charColInput = k.at(0);
        char charRowInput = k.at(2);
        int asciiColInput = (int) charColInput;
        int asciiRowInput = (int) charRowInput;
        if(asciiColInput<=charKolomMaksimal && asciiColInput>=65 && asciiRowInput<=charBarisMaksimal && asciiRowInput>=49){
            return true;
        }
        else{
            return false;
        }

    }
}

void Peternakan::Ternak(string lokasi, Hewan* h){
    if(isLokasiValid(lokasi)){
            kotak.add(lokasi, h);
            cout<<"Tanaman berhasil ditanam!"<<endl;
        }
        else{
            cout<<"Lokasimu ga valid :("<<endl;
        }
} //Menambahkan ternak ke slot lahan

void Peternakan::Panen(string){

} //Memanen hewan dengan kode yang sama dengan inputan

void Peternakan::CetakPeternakan(){

}

bool Peternakan::isFull(){

} //Mengecek apakah penyimpanan sudah penuh atau belum

bool Peternakan::isEmpty(){

}

void Peternakan::BeriMakan(Produk* p){

}

bool Peternakan::isSiapPanen(Hewan* h){

} //Mengecek apakah suatu hewan siap panen atau tidak

