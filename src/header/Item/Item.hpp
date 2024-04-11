#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
    private:
        string itemType;
    public:
        Item(string type);
        string getItemType();
};

#endif