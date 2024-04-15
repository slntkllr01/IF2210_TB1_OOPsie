#include "../../header/Grid/Peternakan.hpp"
#include "../../header/Color/pcolor.h"
using namespace std;

// Constructor
Peternakan::Peternakan(){
    ConfigLoader& loader = ConfigLoader::getInstance();
    this->baris = loader.ukuranPeternakan.first;
    this->kolom = loader.ukuranPeternakan.second;
    this->charBarisMaksimal = 48 + baris;
    this->charKolomMaksimal = 64 + kolom;
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

void Peternakan::addHewan(Hewan* h, string lokasi){
    this->add(lokasi, h);
    /*
    if(Peternakan::isFull()){ //Lahan sudah penuh
        cout<<"Udah penuh :( kasian desak desakan sapinya"<<endl;
    }
    else{ //Masih ada slot
        if(isLokasiValid(lokasi)){ //Lokasi valid
            if(!this->isPresent(lokasi)){ //Kalau petaknya masih kosong, sabi
                this->add(lokasi, h);
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
    */
} //Menambahkan ternak ke slot lahan

Hewan* Peternakan::delHewan(string lokasi){
    Hewan* h = iteratorOf(lokasi)->second; 
    this->del(lokasi);
    cout<<"Hewan berhasil dipanen!"<<endl;
    return h;
    
    /*
    if(Peternakan::isEmpty()){ //Lahan kosong, gabisa dipanen
        cout<<"Wong ga ada hewannya, apa yang mau dipanen :)"<<endl;
    }
    else{//Masih bisa yang dipanen
        if(isLokasiValid(lokasi)){ //Lokasi valid
            if(this->isPresent(lokasi)){//Ada hewannya, sabi dipanen
                Hewan* h = iteratorOf(lokasi)->second; 
                this->del(lokasi);
                cout<<"Hewan berhasil dipanen!"<<endl;
                return h;

            }
            else{
                cout<<"Petak ini kosong, yuk pilih yang lain!"<<endl;
            }
        }
        else{
            cout<<"Lokasimu ga valid :("<<endl;
        }
    }
    */
    
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
        Peternakan::CetakPeternakanHelper();
        charRow++;
    }
}

bool Peternakan::isFull(){
    if(this->howMuchElement()==baris*kolom){
        return true;
    }
    else{
        return false;
    }
} //Mengecek apakah penyimpanan sudah penuh atau belum

bool Peternakan::isEmpty(){
    if(this->howMuchElement() == 0){
        return true;
    }
    else{
        return false;
    }
}

void Peternakan::BeriMakan(Produk* p, string lokasi){
    int add = p->getAddedWeight();
    int now = this->value(lokasi)->get_actualweight();
    this->value(lokasi)->set_actualweight(add + now);
}

bool Peternakan::isSiapPanen(string k){
    return this->value(k)->siapPanen();

} //Mengecek apakah suatu hewan siap panen atau tidak

Grid<int> Peternakan::getListOfSiapPanen(){
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

Grid<string> Peternakan::getListOfHewan(){
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
