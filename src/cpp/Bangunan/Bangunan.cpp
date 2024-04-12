#include "../../header/Bangunan/Bangunan.hpp"

Bangunan::Bangunan(int ID, string kode, string nama, map<string, int> listofResep, int price) : Item("Bangunan", ID, kode, nama, price), listOfResep(listofResep) {}
