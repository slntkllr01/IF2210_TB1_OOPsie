#include <iostream>
#include "header/Game/Game.hpp"
#include "header/Exception/Exception.hpp"

using namespace std;

int main(){
    int method;
    cout << "Selamat datang di Harvest Moon~" << endl;
    cout << "Pilih metode untuk inisialisasi:" << endl;
    cout << "1. File Konfigurasi" << endl;
    cout << "2. Nonkonfigurasi" << endl;
    cout << "> ";
    cin >> method;
    if (method == 1){   //baca config

    }
    else if (method == 2){     //nonconfig
        
    }
    else{
        throw InvalidInput();
    }
}