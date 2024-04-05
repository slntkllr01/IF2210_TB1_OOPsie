#include <iostream>
#include "Hewan.hpp"
#include "Herbivora.hpp"
#include <string>
using namespace std;

Herbivora::Herbivora(int ID, string code, string name, string type, int harvestweight, int price):Hewan(ID,code,name,type,harvestweight,price){
}

Herbivora::~Herbivora(){
}

bool Herbivora::CanEat(string tipe){
    if (tipe == "PRODUCT_FRUIT_PLANT"){
        return true;
    }
    else{
        return false;
    }
}