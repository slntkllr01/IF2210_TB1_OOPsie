#include <iostream>
#include <string>
#include "../header/Exception/Exception.hpp"
#include "../header/Tanaman/Tanaman.hpp"
#include "../header/Pemain/Petani.hpp"
#include "../header/Grid/Inventory.hpp"
using namespace std;
void tanam(Pemain* p){
    if (p->getPeran() !="Petani"){
        throw InvalidRole();
    }
    if (p->getInventory().isFull()){
        throw LadangFull();
    }

    // no food
    if (!(p->getInventory().isThereTanaman())){
        throw noTanamaninInv();
    }
    // try catch
    string slotinv;
    string slotladang;
    cout << "Pilih tanaman dari penyimpanan." << endl;
    p->getInventory().CetakPenyimpanan();

    cout << "Slot: ";
    cin >> slotinv;
    // cout << "Kamu memilih " << getter item << endl;

    Petani* petani = dynamic_cast<Petani*>(p);
    cout << "Pilih petak yang akan ditanami" << endl;
    // printladang
    cout << "Petak tanah: ";
    cin >> slotladang;
    // tanam
    cout << "Cangkul-cangkul yang dalam~!" << endl;
    // cout << getter item << " berhasil ditanam!" << endl;
}