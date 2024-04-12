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

int Item::getprice() const {
    return this->price;
}

bool Item::operator<(const Item& rhs) const {
    return name < rhs.name;
}