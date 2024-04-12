#include <iostream>
#include "../../header/Tanaman/Tanaman.hpp"
#include <string>
using namespace std;

Tanaman::Tanaman(int id, string kodeHuruf, string name, string type, int durationToHarvest, int price) : Item("Tanaman", id, kodeHuruf, name, price), type(type), durationToHarvest(durationToHarvest) {
}

Tanaman::~Tanaman() {}

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