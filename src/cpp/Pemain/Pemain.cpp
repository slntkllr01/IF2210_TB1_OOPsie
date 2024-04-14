#include "../../header/Pemain/Pemain.hpp"
#include "../../header/Loader/ConfigLoader.hpp"

/* Default Constructor */
Pemain::Pemain() : username(""), peran(""), inventory(Inventory()), uang(50), beratBadan(40) {}

/* User-Defined Constructor */
Pemain::Pemain(string username, string peran) : username(username), peran(peran), inventory(Inventory()), uang(50), beratBadan(40) {}
Pemain::Pemain(string username, string peran, int uang, int beratBadan) : username(username), peran(peran), inventory(Inventory()), uang(uang), beratBadan(beratBadan) {}

/* Destructor */
Pemain::~Pemain() {}

/* Getter */
string Pemain::getUsername() const {
    return username;
}

string Pemain::getPeran() const {
    return peran;
}

Inventory Pemain::getInventory() const {
    return inventory;
}

int Pemain::getUang() const {
    return uang;
}

int Pemain::getBeratBadan() const {
    return beratBadan;
}

/* Setter */
void Pemain::setUsername(string username){
    this->username = username;
}

void Pemain::setPeran(string peran){
    this->peran = peran;
}

void Pemain::setInventory(Inventory inventory){
    this->inventory = inventory;
}

void Pemain::setUang(int uang){
    this->uang = uang;
}

void Pemain::setBeratBadan(int beratBadan){
    this->beratBadan = beratBadan;
}

/* Menyimpan item ke inventory */
void Pemain::simpanItem(Item* item, string lokasi){
    inventory.SimpanBarang(item, lokasi);
}

/* Mengambil item dari inventory */
Item* Pemain::ambilItem(string lokasi){
    inventory.AmbilBarang(lokasi);
}

/* Makan */
void Pemain::makan(Produk* produk){
    beratBadan += produk->getAddedWeight();
}

/* Mengecek apakah uang cukup */
bool Pemain::isUangCukup(int uang){
    return this->uang >= uang;
}

/* Mengecek apakah pemain bisa membeli barang */
bool Pemain::bisaBeli(Item* item){
    return true;
}

/* Mengecek apakah pemain bisa menjual barang */
bool Pemain::bisaJual(Item* item){
    return true;
}

/* Membeli barang */
void Pemain::beli(Item* item, int kuantitas){
    uang -= item->getPrice() * kuantitas;
}

/* Menjual barang */
void Pemain::jual(Item* item, int kuantitas){
    uang += item->getPrice() * kuantitas;
}

/* Mengecek apakah pemain memenuhi kondisi menang */
bool Pemain::isMenang(){
    ConfigLoader& config = ConfigLoader::getInstance();
    int uangMenang = config.uangMenang;
    int beratBadanMenang = config.beratMenang;
    return uang >= uangMenang && beratBadan >= beratBadanMenang;
}

/* Operator == untuk membandingkan pointer pemain */
bool Pemain::operator==(const Pemain* other) const {
    return this->username == other->username;
}