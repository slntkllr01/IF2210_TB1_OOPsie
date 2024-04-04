#include "header/Item/Item.hpp"

using namespace std;

Item::Item(string type) {
    this->type = type;
}

string Item::getType() {
    return this->type;
}

void Item::setType(string type) {
    this->type = type;
}