#include <iostream>
#include "../../header/Hewan/Hewan.hpp"
#include <string>
using namespace std;

int Hewan::DEADAGE = 20;

Hewan::Hewan(int id) : Item("Hewan", id, "", "", 0) {
    ConfigLoader& loader = ConfigLoader::getInstance();
    auto it = loader.hewanConfigs.find(id);
    if (it != loader.hewanConfigs.end()) {
        const HewanConfig& config = it->second;
        setID(id);
        setCode(config.code);
        setName(config.name);
        setPrice(config.price);
        set_type(config.type);
        set_harvestweight(config.weight);

    } else {
        throw runtime_error("Invalid animal ID");
    }
}

Hewan::Hewan(string name) : Item("Hewan", 0, "", name, 0) {
    ConfigLoader& loader = ConfigLoader::getInstance();
    for (auto& it : loader.hewanConfigs) {
        const HewanConfig& config = it.second;
        if (config.name == name) {
            setID(it.first);
            setCode(config.code);
            setName(config.name);
            setPrice(config.price);
            set_type(config.type);
            set_harvestweight(config.weight);
            return;
        }
    }
    throw runtime_error("Invalid animal name");
}

Hewan::~Hewan(){
}

void Hewan::set_type(string type){
    this -> type = type;
}

string Hewan::get_type(){
    return type;
}

void Hewan::set_age(int age){
    this -> age = age;
}

int Hewan::get_age(){
    return age;
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