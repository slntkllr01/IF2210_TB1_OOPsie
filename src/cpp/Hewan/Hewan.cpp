#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include <string>
using namespace std;

int Hewan::DEADAGE = 20; 
Hewan::Hewan(int ID, string code, string name, string type, int harvestweight, int price){
    this -> ID = ID;
    this -> code = code;
    this -> name = name;
    this -> type = type;
    this -> harvestweight = harvestweight;
    this -> actualweight = 0;
    this -> price = price;
    this -> age = 0;
}

Hewan::~Hewan(){
}

void Hewan::set_actualweight(int actualweight){
    this -> actualweight = actualweight;
}

string Hewan::get_name() const{
    return this -> name;
}

int Hewan::get_price() const{
    return this -> price;
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

void Hewan::printInfo(){
    cout << "Status Hewan:" << endl;
    cout << "   ID: " << ID << endl;
    cout << "   Code: " << code << endl;
    cout << "   Name: " << name << endl;
    cout << "   Type: " << type << endl;
    cout << "   Harvestweight: " << harvestweight << endl;
    cout << "   Actualweight: " << actualweight << endl;
    cout << "   Price: " << price << endl;
}

bool Hewan::is_Dead(){
    if (age == DEADAGE){

    }
}