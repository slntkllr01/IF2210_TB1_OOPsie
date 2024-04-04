#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
    private:
        string type;
    public:
        Item(string type);
        string getType();
        void setType(string type);
};

#endif