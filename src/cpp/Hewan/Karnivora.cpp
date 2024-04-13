#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Karnivora.hpp"
#include <string>
using namespace std;

Karnivora::Karnivora(int id, string code, string name, int price, int harvestweight, int actualweight, int age) : Hewan(id, code, name, price, harvestweight, actualweight, age) {}

Karnivora::~Karnivora(){
    
}

bool Karnivora::CanEat(Produk* makanan){
    if (makanan->getType() == "PRODUCT_ANIMAL"){
        return true;
    }
    else{
        return false;
    }
}