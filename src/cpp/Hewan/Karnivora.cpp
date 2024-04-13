#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Karnivora.hpp"
#include <string>
using namespace std;

Karnivora::Karnivora(int ID):Hewan(ID){
}

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