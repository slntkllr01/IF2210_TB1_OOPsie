#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
    private:
        // Hewan, Tanaman, Produk, Bangunan
        string itemType;
        int id;
        string code;
        string name;
        int price;
    public:
        Item(string type);
        string getItemType();
        string getCode();
};

#endif