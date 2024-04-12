#include "../../header/Item/Item.hpp"

using namespace std;

Item::Item(string type) {
    this->itemType = type;
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