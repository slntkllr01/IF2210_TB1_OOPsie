#include "../../header/Grid/Inventory.hpp"
#include <string>

using namespace std;

// Constructor
Inventory::Inventory(){
    ConfigLoader& loader = ConfigLoader::getInstance();
    this->baris = loader.ukuranInventory.first;
    this->kolom = loader.ukuranInventory.second;
    this->charBarisMaksimal = 48 + baris;
    this->charKolomMaksimal = 64 + kolom;
    //49 = 1
    //65 = A
}

Inventory::~Inventory(){}

bool Inventory::isLokasiValid(string k){
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

void Inventory::SimpanBarang(Item* t){
    if(Inventory::isFull()){
        cout<<"Penyimpananmu sudah penuh nih!"<<endl;
    }
    else{ //Masih ada slot
        //Akan dilakukan pencarian slot pertama yang kosong iteratif
        int charRow = 49;
        int charColumn;
        string k, cr, cc;
        bool find = false;
        int i, j;
        i = 0;
        while(i<this->baris && !find){
            cr = char(charRow);
            charColumn = 65;
            while(j<this->kolom && !find){
                cc = char(charColumn);
                k = cc + "0" + cr;
                if(this->isPresent(k)){
                    find = true;
                }
                charColumn++;
                j++;
            }
            charRow++;
            i++;
        }

        this->add(k, t);
    }
} //Auto

void Inventory::SimpanBarang(Item* t, string lokasi){
    this->add(lokasi, t);
} //Input Manual

Item* Inventory::AmbilBarang(string lokasi){
    /*Asumsi:
    1.Lokasi Valid (Tidak out of range)
    2.Inventory tidak kosong*/

    Item *t = this->value(lokasi);
    this->del(lokasi);
    return t;
} //Delete

bool Inventory::IsMakanan(string lokasi){
    /*Asumsi:
    1. Lokasi valid (Tidak out of range)
    2. Inventory tidak kosong*/
    Item *t = this->value(lokasi);
    string cek1, cek2, tipeItem;
    cek1 = "PRODUK";
    cek2 = "MATERIAL";
    bool is = false;
    if(t->getItemType() == "Produk"){
        Produk* p = dynamic_cast<Produk*>(t);
        string tipeItem = p->getType();
        if(tipeItem.find(cek2) == string::npos && tipeItem.find(cek1) != string::npos){
            is = true;
        }
    }
    return is;
}

void Inventory::CetakPenyimpananHelper(){
    cout<<"   +";
    for(int i=0; i<this->kolom; i++){
        cout<<"-----+";
    }
    cout<<endl;
}

void Inventory::CetakPenyimpanan(){
    cout<<"   ";
    for(int i = 0; i<this->kolom; i++){
        cout<<"   "<<char(65+i)<<"  ";
    }
    cout<<endl;

    Inventory::CetakPenyimpananHelper();
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
                cout<<" "<<this->value(k)->getCode()<<" |";                
            }
            else{
                cout<<" "<<"   "<<" |";
            }
            charColumn++;
        }
        cout <<endl;
        Inventory::CetakPenyimpananHelper();
        charRow++;
    }
}

int Inventory::SlotTersisa(){
    return baris*kolom - this->howMuchElement();
} //Untuk diprint setelah cetak penyimpanan

bool Inventory::isFull(){
    return baris*kolom == this->howMuchElement();
} //Mengecek apakah penyimpanan sudah penuh atau belum

bool Inventory::isEmpty(){
    return this->howMuchElement() == 0;
}

bool Inventory::isThereMakanan(){
    bool thereAre = false;
    if(!this->isEmpty()){
        for(auto it = this->getElMap().begin(); it != this->getElMap().end(); ++it){
            if(it->second->getItemType() == "Produk"){
                Produk* p = dynamic_cast<Produk*>(it->second);
                if(p->isEdibleBy()){
                    thereAre = true;
                }

            }
                
        }
    }

    return thereAre;
        
    
} //Mengecek apakah ada makanan

bool Inventory::isThereTanaman(){
    bool thereAre = false;
    if(!this->isEmpty()){
        for(auto it = this->getElMap().begin(); it != this->getElMap().end(); ++it){
            if(it->second->getItemType() == "Tanaman"){
                    thereAre = true;
                }

            }
                
    }
    return thereAre;
}

bool Inventory::isThereHewan(){
    bool thereAre = false;
    if(!this->isEmpty()){
        for(auto it = this->getElMap().begin(); it != this->getElMap().end(); ++it){
            if(it->second->getItemType() == "Hewan"){
                    thereAre = true;
                }

            }
                
    }
    return thereAre;
}


