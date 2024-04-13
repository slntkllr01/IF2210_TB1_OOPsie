#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include <string>
using namespace std;

int Hewan::DEADAGE = 20; 
Hewan::Hewan(int ID){
    this -> ID = ID;
    this -> actualweight = 0;
    this -> age = 0;
}

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