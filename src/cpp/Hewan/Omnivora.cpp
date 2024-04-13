#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Omnivora.hpp"
#include <string>
using namespace std;

Omnivora::Omnivora(string itemType, int id, string code, string name, int price, int harvestweight, int actualweight, int age) : Hewan(itemType, id, code, name, price, harvestweight, actualweight, age) {}

Omnivora::~Omnivora(){
    
}

bool Omnivora::CanEat(Produk* makanan){
    if (makanan->getType() == "PRODUCT_MATERIAL_PLANT"){
        return false;
    }
    else{
        return true;
    }
}

