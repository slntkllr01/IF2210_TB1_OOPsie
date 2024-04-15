#include <iostream>
#include <string>
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

    peternak->getInventory().CetakPenyimpanan();
    if (peternak->getInventory().isEmpty()){
        throw InventoryEmpty();
    }

    if (!peternak->getInventory().isThereMakanan(peternak->getPeternakan().value(slot_kandang)->get_type())){
        throw ThereIsntMakananHewan();
    }

    string slot_inventory;
    while (true){
        cout << "Stok: ";
        cin >> slot_inventory;
        // cek slot kandang ada isi ga
        if(peternak->getInventory().isPresent(slot_inventory) && peternak->getInventory().isLokasiValid(slot_inventory)){
            //Sekarang validasi apakah yang dipilih itu produk
            if(peternak->getInventory().value(slot_inventory)->getItemType() == "Produk"){
                Produk* pr = dynamic_cast<Produk*>(peternak->getInventory().value(slot_inventory));
                //Validasi apakah produk yang dipilih bisa dimakan
                if(peternak->getPeternakan().value(slot_kandang)->CanEat(pr)){
                    cout << endl;
                    break;
                }
                else{
                    cout<<"Isi petak tidak bisa dimakan oleh hewan anda. " << endl;
                }
            }
            else{
                cout<< "Isi petak bukan merupakan produk hewan/tumbuhan." << endl;
            }
        }
        else{
            cout << "Isi petak tidak valid/kosong, silakan ulangi masukan." << endl;
        }
    }

    Produk* p = dynamic_cast<Produk*>(peternak->getInventory().value(slot_inventory));
    peternak->beriMakanHewan(peternak->getPeternakan().value(slot_kandang), p);
    
    cout << peternak->getPeternakan().value(slot_kandang)->getName() << " sudah diberi makan dan beratnya menjadi " <<peternak->getPeternakan().value(slot_kandang)->get_actualweight()<<endl;}
}
