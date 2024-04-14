#include "../../header/Item/Item.hpp"

using namespace std;

Item::Item(string itemType, int id, string code, string name, int price) : itemType(itemType), id(id), code(code), name(name), price(price) {
}

Item::~Item() {
}

string Item::getItemType() const {
    return this->itemType;
}

string Item::getCode() const {
    return this->code;
}

string Item::getName() const {
    return this->name;
}

int Item::getPrice() const {
    return this->price;
}

int Item::getID() const{
    return this->id;
}

bool Item::operator<(const Item& other) const {
    return id < other.id;
}

void Item::setItemType(string itemType) {
    this->itemType = itemType;
}

void Item::setCode(string code) {
    this->code = code;
}

void Item::setName(string name) {
    this->name = name;
}

void Item::setPrice(int price){
    this->price = price;
}

void Item::setID(int id) {
    this->id = id;
}