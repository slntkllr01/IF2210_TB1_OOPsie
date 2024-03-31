#include <iostream>
#include "Hewan.hpp"
#include "Omnivora.hpp"
#include <string>
using namespace std;

Omnivora::Omnivora(int ID, string code, string name, string type, int harvestweight, int price):Hewan(ID,code,name,type,harvestweight,price){
}

Omnivora::~Omnivora(){
    
}