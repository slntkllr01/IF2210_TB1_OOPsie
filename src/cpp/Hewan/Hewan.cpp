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

        itemType = "Hewan";
        this->id = id;
        code = config.code;
        name = config.name;
        price = config.price;
        setType(config.type);
        set_harvestweight(config.weight);

    } else {
        throw std::runtime_error("Invalid animal ID");
    }
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