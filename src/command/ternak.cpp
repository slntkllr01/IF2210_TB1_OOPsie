#include <iostream>
#include <string>
#include "../header/Grid/Peternakan.hpp"
#include "../header/Grid/Inventory.hpp"

using namespace std;

void ternak(Pemain* p){
    string slot_inventory, slot_ladang;

    cout << "Pilih hewan dari penyimpanan" << endl;
    // display inventory

    cout << "Slot: ";
    cin >> slot_inventory;

    cout << "Pilih petak tanah yang akan ditinggali" << endl;
    // display peternakan

    cout << "Petak tanah: ";
    cin >> slot_ladang;

    // proses ternak
    string name_hewan;

    cout << "Dengan hati-hati, kamu meletakkan seekor " << name_hewan << " di kandang." << endl;
    cout << name_hewan << " telah menjadi peliharaanmu sekarang!" << endl;
}
