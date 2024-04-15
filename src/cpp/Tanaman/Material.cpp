#include <iostream>
#include "../../header/Tanaman/Tanaman.hpp"
#include "../../header/Tanaman/Material.hpp"
#include <string>
using namespace std;

Material::Material(int ID) : Tanaman(ID) {}
Material::Material(string name) : Tanaman(name) {}

Material::~Material(){
    
}
