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

    Petani* petani = dynamic_cast<Petani*>(p);
    // Ladang Full
    if (petani->getLadang().isFull()){
        throw LadangFull();
    }

    // no food
    if (!(p->getInventory().isThereTanaman())){
        throw noTanamaninInv();
    }
    string slotinv;
    string slotladang;
    string namatanaman;
    Item* item;
    cout << "Pilih tanaman dari penyimpanan" << endl;
    p->getInventory().CetakPenyimpanan();
    while (true){
        cout << "Slot: ";
        cin >> slotinv;
        cout << endl;
        // perlu cek islokasivalid???
        // make sure if the slot contains a plant and not empty
        if(p->getInventory().isPresent(slotinv) && p->getInventory().CekJenis(slotinv) == "Tanaman"){          
            item = p->ambilItem(slotinv);
            namatanaman = item->getName();
            cout << "Kamu memilih " << namatanaman << endl;
            break;
        }
        else{
            cout << "Isi petak tidak valid/kosong, silakan ulangi masukan." << endl;
        }
    }
    cout << "Pilih petak yang akan ditanami" << endl;
    petani->getLadang().CetakLadang();
    Tanaman* tanaman = dynamic_cast<Tanaman*>(item);
    while (true){
        cout << "Petak tanah: ";
        cin >> slotladang;
        cout << endl;
        // harus cek petak ladang kosong
        if(petani->getLadang().isLokasiValid(slotladang) && !(petani->getLadang().isPresent(slotladang))){
            petani->tanam(tanaman,slotladang);
            break;
        }
        else{
            cout << "Slot ladang tidak valid/ada tanaman lain, silakan ulangi masukan." << endl;
        }
    }
    
    cout << "Cangkul-cangkul yang dalam~!" << endl;
    cout << namatanaman << " berhasil ditanam!" << endl;
    delete petani;
    delete tanaman;
}