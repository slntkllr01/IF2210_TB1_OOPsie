#include <iostream>
#include "../../header/Tanaman/Tanaman.hpp"
#include "../../header/Tanaman/Fruit.hpp"
#include <string>
using namespace std;

Fruit::Fruit(int ID) : Tanaman(ID) {}
Fruit::Fruit(string name) : Tanaman(name) {}

Fruit::~Fruit(){
    
}