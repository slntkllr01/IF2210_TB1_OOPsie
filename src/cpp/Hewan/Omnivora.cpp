#include <iostream>
#include "src/header/Hewan/Hewan.hpp"
#include "src/header/Hewan/Omnivora.hpp"
#include <string>
using namespace std;

Omnivora::Omnivora(int ID, string code, string name, string type, int harvestweight, int price):Hewan(ID,code,name,type,harvestweight,price){
}

Omnivora::~Omnivora(){
    
}