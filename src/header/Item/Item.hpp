#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
    protected:
        string itemType;
        int id;
        string code;
        string name;
        int price;
    public:
        Item(string itemType, int id, string code, string name, int price);
        ~Item();
        string getItemType() const;
        string getCode() const;
        string getName() const;
        int getprice() const;
        bool operator<(const Item& rhs) const;
};

#endif