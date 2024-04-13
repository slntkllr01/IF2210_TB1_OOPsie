#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include <string>
using namespace std;

int Hewan::DEADAGE = 20;

Hewan::Hewan(int id, string code, string name, int price, int harvestweight, int actualweight, int age) : Item("Hewan", id, code, name, price), harvestweight(harvestweight), actualweight(actualweight), age(age) {}

Hewan::~Hewan(){
}

void Hewan::set_harvestweight(int harvestweight){
    this -> harvestweight = harvestweight;
}

int Hewan::get_harvestweight() const{
    return this -> harvestweight;
}

void Hewan::set_actualweight(int actualweight){
    this -> actualweight = actualweight;
}

int Hewan::get_actualweight() const{
    return this -> actualweight;
}

bool Hewan::siapPanen(){
    if (actualweight >=harvestweight){
        return true;
    }
    else{
        return false;
    }
}

bool Hewan::is_Dead(){
    if (age == DEADAGE){
        return true;
    }
    return false;
}