#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Herbivora.hpp"
#include <string>
using namespace std;

Herbivora::Herbivora(int id) : Hewan(id) {}
Herbivora::Herbivora(string name) : Hewan(name) {}

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