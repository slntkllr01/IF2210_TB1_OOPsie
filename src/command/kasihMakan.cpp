#include <iostream>
#include <string>
#include "cetak.cpp"
#include "../header/Pemain/Peternak.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Grid/Peternakan.hpp"
using namespace std;

void kasihMakan(Pemain* p){
    if (p->getPeran() !="Peternak"){
        throw InvalidRole();
    }
    Peternak* peternak = dynamic_cast<Peternak*>(p);
    if (peternak->getPeternakan().isEmpty()){
        throw PeternakanEmpty();
    }
    cout << "Pilih hewan yang ingin diberi makan" << endl;
    peternak->getPeternakan().CetakPeternakan();
    string slot_kandang;
    while (true){
        cout << "Petak kandang: " << endl;
        cin >> slot_kandang;
        // cek slot kandang ada isi ga
        if(peternak->getPeternakan().isPresent(slot_kandang) && peternak->getPeternakan().isLokasiValid(slot_kandang)){
            cout << endl;
            cout << "Kamu memilih " << peternak->getPeternakan().value(slot_kandang)->getName() << " untuk diberi makan."<< endl;
            break;
        }
        else{
            cout << "Isi petak tidak valid/kosong, silakan ulangi masukan." << endl;
        }
    cout << "Pilih pangan yang akan diberikan: " << endl;
    printPenyimpanan(p);
    //implement sini
    //validasi petak, bisa dimakan sm hewan itu ga CanEat(Produk*)
    //lakukan kasih makan set berat badan hewan
    cout << peternak->getPeternakan().value(slot_kandang)->getName() << " sudah diberi makan dan beratnya menjadi " << /*berat hewan*/  endl;
}