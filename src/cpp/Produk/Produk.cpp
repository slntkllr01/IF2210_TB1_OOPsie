#include "src/header/Produk/Produk.hpp"

Produk::Produk(int id, string kodeHuruf, string nama, string tipe, string origin, int addedWeight, int price) : id(id), kodeHuruf(kodeHuruf), nama(nama), tipe(tipe), origin(origin), addedWeight(addedWeight), price(price) {}

int Produk::getAddedWeight() const {
    return this->addedWeight;
}

string Produk::getType() const {
    return this->tipe;
}

produkHewan::produkHewan(int id, string kodeHuruf, string nama, string tipe, string origin, int addedWeight, int price) : Produk(id, kodeHuruf, nama, "PRODUCT_ANIMAL", origin, addedWeight, price) {}

produkTumbuhan::produkTumbuhan(int id, string kodeHuruf, string nama, string tipe, string origin, int addedWeight, int price) : Produk(id, kodeHuruf, nama, "PRODUCT_ANIMAL", origin, addedWeight, price) {}

bool produkHewan::isEdibleBy(string animalType) {
    return animalType == "KARNIVORA" || animalType == "OMNIVORA";
}

bool produkTumbuhan::isEdibleBy(string animalType) {
    return animalType != "KARNIVORA" || this->getType() != "MATERIAL_PLANT";
}