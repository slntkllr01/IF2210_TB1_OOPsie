#include "../../header/Produk/Produk.hpp"

Produk::Produk(int id) : Item("Produk", id, "", "", 0) {
    ConfigLoader& loader = ConfigLoader::getInstance();
    auto it = loader.produkConfigs.find(id);
    if (it != loader.produkConfigs.end()) {
        const ProdukConfig& config = it->second;
        setID(id);
        setCode(config.code);
        setName(config.name);
        setPrice(config.price);
        setType(config.type);
        setOrigin(config.origin);
        setAddedWeight(config.added_weight);
    } else {
        throw runtime_error("Invalid Produk ID");
    }
}

int Produk::getAddedWeight() const {
    return this->addedWeight;
}

string Produk::getType() const {
    return this->tipe;
}

produkHewan::produkHewan(int id) : Produk(id) {}

produkTumbuhan::produkTumbuhan(int id) : Produk(id) {}

bool produkHewan::isEdibleBy() { // ini untuk manusia kan?
    return true; // keknya semua manusia bisa makanan dari produk hewan kn ya?
}

bool produkTumbuhan::isEdibleBy() { // ini untuk manusia kan?
    return this->getType() != "PRODUCT_MATERIAL_PLANT";
}

void Produk::setType(string type) {
    this->tipe = type;
}
void Produk::setOrigin(string origin) {
    this->origin = origin;
}

void Produk::setAddedWeight(int weight) {
    this->addedWeight = weight;
}