#include <iostream>
#include <string>
#include "cetak.cpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Hewan/Hewan.hpp"
#include "../header/Grid/Peternakan.hpp"
#include "../header/Grid/Inventory.hpp"
#include "../header/Pemain/Peternak.hpp"

using namespace std;

void ternak(Pemain* p){
    // Pemain harus peternak
    if (p->getPeran() !="Peternak"){
        throw InvalidRole();
    }

    // Peternakan dipastikan tidak penuh
    Peternak* peternak = dynamic_cast<Peternak*>(p);
    if (peternak->getPeternakan().isFull()){
        throw PeternakanFull();
    }

    // Pastikan ada hewan di inventory
    if (!(p->getInventory().isThereHewan())){
        throw noHewanInv();
    }

    string slot_inventory, slot_peternakan, nama_hewan;
    Item* item;
    // Cetak inventory
    cout << "Pilih hewan dari penyimpanan" << endl;
    printPenyimpanan(p);

    while (true) {
        cout << "Slot: ";
        cin >> slot_inventory;
        if(p->getInventory().isPresent(slot_inventory) && p->getInventory().CekJenis(slot_inventory) == "Hewan"){          
            item = p->ambilItem(slot_inventory);
            nama_hewan = item->getName();
            cout << "Kamu memilih " << nama_hewan << endl;
            break;
        } else {
            cout << "Isi petak tidak valid/kosong, silakan ulangi masukan." << endl;
        }
    }

    // Cetak peternakan
    cout << "Pilih petak tanah yang akan ditinggali" << endl;
    peternak->getPeternakan().CetakPeternakan();
    Hewan* hewan = dynamic_cast<Hewan*>(item);

    while (true) {
        cout << "Petak tanah: ";
        cin >> slot_peternakan;
        if(peternak->getPeternakan().isLokasiValid(slot_peternakan) && !(peternak->getPeternakan().isPresent(slot_peternakan))){
            peternak->ternak(hewan, slot_peternakan);          
            break;
        } else {
            cout << "Isi petak tidak valid atau sudah terisi, silakan ulangi masukan." << endl;
        }
    }

    cout << "Dengan hati-hati, kamu meletakkan seekor " << nama_hewan << " di kandang." << endl;
    cout << nama_hewan << " telah menjadi peliharaanmu sekarang!" << endl;
}
