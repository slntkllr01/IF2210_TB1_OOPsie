#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include <string>
#include <map>

using namespace std;

class Bangunan {
    private:
        int ID;
        string kode;
        string nama;
        map<string, int> listOfResep; // ganti jadi map > kuantitas!
        int price;
    public:
        Bangunan(int ID, string kode, string nama, int price);
};

#endif