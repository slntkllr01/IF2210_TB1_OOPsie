#include "../../header/Grid/Ladang.hpp"
#include "../../header/Color/pcolor.h"
#include "../../header/Grid/GridMap.hpp"
#include <iostream>
using namespace std;

Ladang::Ladang(){
    ConfigLoader& loader = ConfigLoader::getInstance();
    this->baris = loader.ukuranLahan.first;
    this->kolom = loader.ukuranLahan.second;
    this->charBarisMaksimal = 48 + baris;
    this->charKolomMaksimal = 64 + kolom;
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

void Ladang::addTanaman(Tanaman* t, string lokasi){
    /*Asumsi:
    1. Ladang tidak penuh
    2. Lokasi valid (tidak out of range)
    3. Lokasi yang dipilih belum memiliki tanaman*/

    this->add(lokasi, t);
} //Menambahkan tanaman ke slot lahan

Tanaman* Ladang::delTanaman(string lokasi){
    /*Asumsi:
    1. Ladang tidak kosong
    2. Minimal ada satu tanaman yang siap panen
    3. Lokasi yang dipilih valid (tidak out of range)
    4. Lokasi yang dipilih ada tanamannya dan siap panen*/
    Tanaman* val = this->value(lokasi);
    this->del(lokasi);
    return val;
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
            if(isPresent(k)){
                cout<<" ";
                if(isSiapPanen(k)){
                    print_green(this->value(k)->getCode().at(0));
                    print_green(this->value(k)->getCode().at(1));
                    print_green(this->value(k)->getCode().at(2));
                }
                else{
                    print_red(this->value(k)->getCode().at(0));
                    print_red(this->value(k)->getCode().at(1));
                    print_red(this->value(k)->getCode().at(2));                
                }
                cout<<" |";                
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
    if(this->howMuchElement()==baris*kolom){
        return true;
    }
    else{
        return false;
    }

} //Mengecek apakah ladang sudah penuh atau belum

bool Ladang::isEmpty(){
    if(this->howMuchElement() == 0){
        return true;
    }
    else{
        return false;
    }

} //Mengecek apakah ladang kosong atau tidak

/*
Grid<Tanaman*> Ladang::getLadang const (){
    return this->getElMap();
}
*/

bool Ladang::isSiapPanen(string lokasi){

    return this->value(lokasi)->siapPanen();
} //Mengecek apakah tanaman siap dipanen

Grid<int> Ladang::getListofSiapPanen(){
    Grid<int> g;
    for (const auto &it : this->getElMap()){
        if(it.second->siapPanen()){ //Wah ada yang siap panen nih di ladang!
            string code = it.second->getCode();
            if(g.howMuchElement() == 0){
                g.add(code, 1);
            }
            else{
                if(g.isPresent(code)){ //Ternyata udah ditambahin ke listofSiapPanen
                    //Maka cukup naikin valuenya;
                    int temp = g.value(code);
                    g.del(code);
                    g.add(code, temp + 1);
                }
                else{
                    //Kalau belum ada samsek, tambahin key dan value baru
                    g.add(code, 1);
                }
            }
        }
    }
    return g;
    
}

Grid<string> Ladang::getListOfTanaman(){
    Grid<string> g;
    for (const auto &it : this->getElMap()){ 
        string code = it.second->getCode();
        string value = it.second->getName();
        if(g.howMuchElement() == 0){
            g.add(code, value);
        }
        else if(!g.isPresent(code)){ 
                g.add(code, value);
        }
    }
    return g;
}
