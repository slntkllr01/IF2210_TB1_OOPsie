#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Herbivora.hpp"
#include <string>
using namespace std;

Herbivora::Herbivora(string itemType, int id, string code, string name, int price, int harvestweight, int actualweight, int age) : Hewan(itemType, id, code, name, price, harvestweight, actualweight, age) {}

Herbivora::~Herbivora(){
}

bool Herbivora::CanEat(Produk* makanan){
    if (makanan->getType() == "PRODUCT_FRUIT_PLANT"){
        return true;
    }
    else{
        return false;
    }
}