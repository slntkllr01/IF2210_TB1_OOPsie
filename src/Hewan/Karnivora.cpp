#include <iostream>
#include "Hewan.hpp"
#include "Karnivora.hpp"
#include <string>
using namespace std;

Karnivora::Karnivora(int ID, string code, string name, string type, int harvestweight, int price):Hewan(ID,code,name,type,harvestweight,price){
}

Karnivora::~Karnivora(){
    
}

void Karnivora::KasihMakan(Produk makanan){
    // if (makanan.type = "ANIMAL_PRODUCT"){
    //     throw NoAnimalFood();
    // }
}