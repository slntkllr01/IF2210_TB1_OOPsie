#include "../../header/Grid/Ladang.hpp"
#include <iostream>
using namespace std;

Ladang::Ladang(int b, int k){
    this->baris = b;
    this->kolom = k;
    this->charBarisMaksimal = 48 + b;
    this->charKolomMaksimal = 64 + k;
    //49 = 1
    //65 = A
}

Ladang::~Ladang(){
}

bool Ladang::isLokasiValid(string k){
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

void Ladang::Tanam(string lokasi, Tanaman t){
    if(isLokasiValid(lokasi)){
        kotak.add(lokasi, t);
        cout<<"Tanaman berhasil ditanam!"<<endl;
    }
    else{
        cout<<"Lokasimu ga valid :("<<endl;
    }
} //Menambahkan tanaman ke slot lahan

void Ladang::Panen(string lokasi){
    kotak.del(lokasi);
} //Memanen tanaman dengan kode yang sama dengan inputan

void Ladang::CetakLadangHelper(){
    cout<<"   +";
    for(int i=0; i<this->kolom; i++){
        cout<<"-----+";
    }
    cout<<endl;
}
void Ladang::CetakLadang(){
    cout<<"   ";
    for(int i = 0; i<this->kolom; i++){
        cout<<"   "<<char(65+i)<<"  ";
    }
    cout<<endl;

    Ladang::CetakLadangHelper();
    int charRow = 49; //Ascii dari 1
    int charColumn;
    string k, cr, cc;

    for (int i = 0; i < this->baris; i++) {
        cout<<"0"<<i+1<<" ";
        cr = char(charRow);
        charColumn = 65; //Ascii dari A
        cout << "|";
        for (int j = 0; j < this->kolom; j++) {
            cc = char(charColumn);
            k = cc + "0" + cr;
            if(kotak.isPresent(k)){
                cout<<" "<<(kotak.value(k)).get_kodeHuruf()<<" |";                
            }
            else{
                cout<<" "<<"   "<<" |";
            }
            charColumn++;
        }
        std::cout <<endl;
        Ladang::CetakLadangHelper();
        charRow++;
    }
}

bool Ladang::isFull(){
    if(kotak.howMuchElement()==baris*kolom){
        return true;
    }
    else{
        false;
    }

} //Mengecek apakah ladang sudah penuh atau belum

bool Ladang::isEmpty(){
    if(kotak.howMuchElement() == 0){
        return true;
    }
    else{
        return false;
    }

} //Mengecek apakah ladang kosong atau tidak

//bool Ladang::isSiapPanen(){} //Mengecek apakah tanaman siap dipanen

Grid<Tanaman> Ladang::getLadang() const {
    return this->kotak;
}