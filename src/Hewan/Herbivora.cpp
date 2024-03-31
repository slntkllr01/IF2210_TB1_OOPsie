#include <iostream>
#include "Hewan.hpp"
#include "Herbivora.hpp"
#include <string>
using namespace std;

Herbivora::Herbivora(int ID, string code, string name, string type, int harvestweight, int price):Hewan(ID,code,name,type,harvestweight,price){
}

Herbivora::~Herbivora(){
    
}

void Herbivora::KasihMakan(Produk makanan){
    // if (makanan.type = "ANIMAL_PRODUCT"){
    //     throw NoAnimalFood();
    // }
}