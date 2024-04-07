#include <iostream>
#include "src/header/Hewan/Hewan.hpp"
#include "src/header/Hewan/Omnivora.hpp"
#include <string>
using namespace std;

Omnivora::Omnivora(int ID, string code, string name, int harvestweight, int price):Hewan(ID,code,name,"OMNIVORE",harvestweight,price){
}

Omnivora::~Omnivora(){
    
}

bool Omnivora::CanEat(string tipe){
    if (tipe == "PRODUCT_MATERIAL_PLANT"){
        return false;
    }
    else{
        return true;
    }
}

