#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Omnivora.hpp"
#include <string>
using namespace std;

Omnivora::Omnivora(int id) : Hewan(id) {}
Omnivora::Omnivora(string name) : Hewan(name) {}

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

