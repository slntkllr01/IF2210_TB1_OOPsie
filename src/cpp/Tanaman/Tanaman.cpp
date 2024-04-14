#include <iostream>
#include "../../header/Tanaman/Tanaman.hpp"
#include "../../header/Loader/ConfigLoader.hpp"
#include <string>
using namespace std;

Tanaman::Tanaman(int ID): Item("Tanaman", ID, "", "", 0) {
    ConfigLoader& loader = ConfigLoader::getInstance();
    auto it = loader.tanamanConfigs.find(ID);
    if (it != loader.tanamanConfigs.end()) {
        const TanamanConfig& config = it->second;
        
        this->itemType = "Tanaman";
        this->id = ID;
        this->code = config.code;
        this->name = config.name;
        this->price = config.price;
        this->type = config.type;
        this->durationToHarvest = config.duration;
        this->umur = 0;
    } else {
        throw std::runtime_error("Invalid animal ID");
    }
}

Tanaman::~Tanaman() {}

void Tanaman::set_durationToHarvest(int durationToHarvest){
    this -> durationToHarvest = durationToHarvest;
}

void Tanaman::set_umur(int umur){
    this -> umur = umur;
}

string Tanaman::get_type() {
    return this->type;
}

int Tanaman::get_durationToHarvest() {
    return this->durationToHarvest;
}

int Tanaman::get_umur() {
    return this->umur;
}

void Tanaman::add_umur() {
    this->umur += 1;
}

bool Tanaman::siapPanen() {
    if (umur >= durationToHarvest){
        return true;
    } else {
        return false;
    }
}