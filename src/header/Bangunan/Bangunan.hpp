#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <string>
#include <map>
#include "../Item/Item.hpp"
#include "../Loader/ConfigLoader.hpp"

using namespace std;

class Bangunan : public Item {
    private:
        map<string, int> listOfResep;
    public:
        Bangunan(int ID);
        Bangunan(string name);
        void setResep(map<string, int> resep);
};

#endif