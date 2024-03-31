#include <iostream>
#include "Hewan.hpp"
#include <string>
using namespace std;

int Hewan::totalHewan = 0;

Hewan::Hewan(int ID, string code, string name, string type, int harvestweight, int price){
    this -> ID = ID;
    this -> code = code;
    this -> type = type;
    this -> harvestweight = harvestweight;
    this -> actualweight = 0;
    this -> price = price;
}

Hewan::~Hewan(){
}

void Hewan::set_actualweight(int actualweight){
    this -> actualweight = actualweight;
}

int Hewan::get_price() const{
    return this -> price;
}

int Hewan::get_actualweight() const{
    return this -> actualweight;
}

void Hewan::KasihMakan(){

}