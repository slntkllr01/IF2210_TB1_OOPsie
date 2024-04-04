#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <string>
#include <vector>

using namespace std;

class Bangunan {
    private:
        int ID;
        string nama;
        vector<int> listOfResep;
        int price;
    public:
        Bangunan(int ID, string nama);
};

#endif