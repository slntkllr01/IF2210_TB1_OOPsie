#include <iostream>
#include "src/header/Hewan/Hewan.hpp"
#include "src/header/Hewan/Karnivora.hpp"
#include <string>
using namespace std;

Karnivora::Karnivora(int ID, string code, string name, int harvestweight, int price):Hewan(ID,code,name,"CARNIVORE",harvestweight,price){
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