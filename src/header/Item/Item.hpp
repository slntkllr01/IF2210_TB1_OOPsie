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
        virtual ~Item();
        string getItemType() const;
        void setItemType(string itemType);
        string getCode() const;
        void setCode(string code);
        string getName() const;
        void setName(string name);
        int getPrice() const;
        void setPrice(int price);
        int getID() const;
        void setID(int id);
        bool operator<(const Item& other) const;
};

#endif