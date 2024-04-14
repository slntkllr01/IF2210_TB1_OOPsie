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
    if(Ladang::isFull()){ //Lahan sudah penuh
        cout<<"Udah penuh :( kasian desak desakan tanamannya :("<<endl;
    }
    else{ //Masih ada slot
        if(isLokasiValid(lokasi)){ //Lokasi valid
            if(!kotak.isPresent(lokasi)){ //Kalau petaknya masih kosong, sabi
                kotak.add(lokasi, t);
                cout<<"Tanaman berhasil ditanam di "<<lokasi<<" !"<<endl;
            }
            else{ //Kotak udah ada isinya
                cout<<"Petak ini sudah ada tanamannya, yuk pilih yang lain!"<<endl;
            }
        }
        else{//Lokasi gak valid, di luar indeks
            cout<<"Lokasimu ga valid :("<<endl;
        }

    }
} //Menambahkan tanaman ke slot lahan

void Ladang::Panen(string lokasi){
    if(Ladang::isEmpty()){ //Lahan kosong, gabisa dipanen
        cout<<"Wong ga ada tanamannya, apa yang mau dipanen :)"<<endl;
    }
    else{//Masih bisa yang dipanen
        if(isLokasiValid(lokasi)){ //Lokasi valid
            if(kotak.isPresent(lokasi)){//Ada hewannya, sabi dipanen
                kotak.del(lokasi);
                cout<<"Tanaman berhasil dipanen!"<<endl;
            }
            else{
                cout<<"Petak ini kosong, yuk pilih yang lain!"<<endl;
            }
        }
        else{
            cout<<"Lokasimu ga valid :("<<endl;
        }
    }
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
                cout<<" "<<(kotak.value(k)).getCode()<<" |";                
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
        return false;
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

