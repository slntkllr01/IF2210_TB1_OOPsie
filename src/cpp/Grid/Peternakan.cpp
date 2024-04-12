#include "../../header/Grid/Peternakan.hpp"
using namespace std;

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
    if(Peternakan::isFull()){ //Lahan sudah penuh
        cout<<"Udah penuh :( kasian desak desakan sapinya"<<endl;
    }
    else{ //Masih ada slot
        if(isLokasiValid(lokasi)){ //Lokasi valid
            if(!kotak.isPresent(lokasi)){ //Kalau petaknya masih kosong, sabi
                kotak.add(lokasi, h);
                cout<<"Hewan berhasil diternak di "<<lokasi<<" !"<<endl;
            }
            else{ //Kotak udah ada isinya
                cout<<"Petak ini sudah ada hewannya, yuk pilih yang lain!"<<endl;
            }
        }
        else{//Lokasi gak valid, di luar indeks
            cout<<"Lokasimu ga valid :("<<endl;
        }

    }
} //Menambahkan ternak ke slot lahan

void Peternakan::Panen(string lokasi){
    if(Peternakan::isEmpty()){ //Lahan kosong, gabisa dipanen
        cout<<"Wong ga ada hewannya, apa yang mau dipanen :)"<<endl;
    }
    else{//Masih bisa yang dipanen
        if(isLokasiValid(lokasi)){ //Lokasi valid
            if(kotak.isPresent(lokasi)){//Ada hewannya, sabi dipanen
                kotak.del(lokasi);
                cout<<"Hewan berhasil dipanen!"<<endl;
            }
            else{
                cout<<"Petak ini kosong, yuk pilih yang lain!"<<endl;
            }
        }
        else{
            cout<<"Lokasimu ga valid :("<<endl;
        }
    }
} //Memanen hewan dengan kode yang sama dengan inputan

void Peternakan::CetakPeternakanHelper(){
    cout<<"   +";
    for(int i=0; i<this->kolom; i++){
        cout<<"-----+";
    }
    cout<<endl;
}

void Peternakan::CetakPeternakan(){
    cout<<"   ";
    for(int i = 0; i<this->kolom; i++){
        cout<<"   "<<char(65+i)<<"  ";
    }
    cout<<endl;

    Peternakan::CetakPeternakanHelper();
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
                cout<<" "<<(kotak.value(k))->get_code()<<" |";                
            }
            else{
                cout<<" "<<"   "<<" |";
            }
            charColumn++;
        }
        std::cout <<endl;
        Peternakan::CetakPeternakanHelper();
        charRow++;
    }
}

bool Peternakan::isFull(){
    if(kotak.howMuchElement()==baris*kolom){
        return true;
    }
    else{
        return false;
    }
} //Mengecek apakah penyimpanan sudah penuh atau belum

bool Peternakan::isEmpty(){
    if(kotak.howMuchElement() == 0){
        return true;
    }
    else{
        return false;
    }
}

void Peternakan::BeriMakan(Produk* p){
    cout<<"Not implemented yet"<<endl;
}

bool Peternakan::isSiapPanen(Hewan* h){
    return true;

} //Mengecek apakah suatu hewan siap panen atau tidak

