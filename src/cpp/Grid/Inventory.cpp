#include "../../header/Grid/Inventory.hpp"

// Constructor
Inventory::Inventory(){
    ConfigLoader& loader = ConfigLoader::getInstance();
    baris = loader.ukuranInventory.first;
    kolom = loader.ukuranInventory.second;
}

Inventory::Inventory(int b, int k){

}

Inventory::~Inventory(){

}

void Inventory::SimpanBarang(){

} //Auto

void Inventory::SimpanBarang(Item*, string){

} //Input Manual

Item* Inventory::AmbilBarang(string){

} //Delete

void Inventory::Makan(string){

}

void Inventory::CetakPenyimpanan(){

}

int Inventory::SlotTersisa(){

} //Untuk diprint setelah cetak penyimpanan

bool Inventory::isFull(){

} //Mengecek apakah penyimpanan sudah penuh atau belum

bool Inventory::isEmpty(){

}

bool Inventory::isThereMakanan(){

} //Mengecek apakah ada makanan

bool Inventory::isThereTanaman(){
    
}

string Inventory::CekJenis(string){}