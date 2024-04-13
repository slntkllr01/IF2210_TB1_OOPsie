#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Omnivora.hpp"
#include <string>
using namespace std;

Omnivora::Omnivora(int ID):Hewan(ID){
}

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

