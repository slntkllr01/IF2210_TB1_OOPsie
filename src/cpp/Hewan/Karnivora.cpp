#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Hewan/Karnivora.hpp"
#include <string>
using namespace std;

Karnivora::Karnivora(int ID, string code, string name, string type, int harvestweight, int price):Hewan(ID,code,name,type,harvestweight,price){
}

Karnivora::~Karnivora(){
    
}

bool Karnivora::CanEat(string tipe){
    if (tipe == "PRODUCT_ANIMAL"){
        return true;
    }
    else{
        return false;
    }
}