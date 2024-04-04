#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP

#include <vector>
#include <string>
using namespace std;

class Inventory {
public:
    // Constructor
    Inventory();

    // Destructor
    ~Inventory();

    // Methods
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    bool hasItem(const std::string& item) const;
    void displayItems() const;

private:
    vector<string> items;
};

#endif