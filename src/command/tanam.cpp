#include <iostream>
#include <string>
#include "../header/Exception/Exception.hpp"
#include "../header/Tanaman/Tanaman.hpp"
#include "../header/Pemain/Petani.hpp"
using namespace std;
void tanam(Pemain* p){
    if (p->getPeran() !="PETANI"){
        throw InvalidRole();
    }
    string slotinv;
    string slotladang;
    cout << "Pilih tanaman dari penyimpanan." << endl;
    // display inventory
    cout << "Slot: ";
    cin >> slotinv;
    // cout << "Kamu memilih " << getter item << endl;
    cout << "Pilih petak yang akan ditanami" << endl;
    // printladang
    cout << "Petak tanah: ";
    cin >> slotladang;
    // tanam
    cout << "Cangkul-cangkul yang dalam~!" << endl;
    // cout << getter item << " berhasil ditanam!" << endl;
}