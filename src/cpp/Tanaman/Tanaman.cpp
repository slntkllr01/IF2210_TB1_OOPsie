#include <iostream>
#include "src/header/Tanaman/Tanaman.hpp"
#include <string>
using namespace std;

Tanaman::Tanaman() : id(id), kodeHuruf(kodeHuruf), name(name), type(type), durationToHarvest(durationToHarvest), price(price) {}

Tanaman::~Tanaman() {}

int Tanaman::get_id() {
    return this->id;
}

string Tanaman::get_kodeHuruf() {
    return this->kodeHuruf;
}

string Tanaman::get_name() {
    return this->name;
}

string Tanaman::get_type() {
    return this->type;
}

int Tanaman::get_durationToHarvest() {
    return this->durationToHarvest;
}

int Tanaman::get_price() {
    return this->price;
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