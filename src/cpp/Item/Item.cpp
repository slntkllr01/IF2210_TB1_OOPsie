#include "../../header/Item/Item.hpp"

using namespace std;

Item::Item(string type) {
    this->itemType = type;
}

string Item::getItemType() {
    return this->itemType;
}