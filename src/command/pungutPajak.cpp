#include "../header/ListPemain/ListPemain.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
#include "../header/Pemain/Pekerja.hpp"

void pungutPajak(Pemain* pemain, ListPemain& list_pemain){
    if (pemain->getPeran() != "Walikota"){
        throw InvalidRole();
    }
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << "\nBerikut adalah detil dari pemungutan pajak:" << endl;
    vector<Pemain*> pemains = list_pemain.get_ArrPemain();
    int nomor = 1;
    for (Pemain* pemain : pemains){
        // Jika dynamic_cast ke Walikota* mengembalikan nullptr, berarti pemain bukan Walikota
        if (dynamic_cast<Walikota*>(pemain) == nullptr){
            Pekerja* pekerja = dynamic_cast<Pekerja*>(pemain);
            cout << "    " << nomor << ". " << pekerja->getUsername() << " - " << pekerja->getPeran() << ": " << pekerja->hitungPajak() << " gulden" << endl;
        }
    }
    Walikota* walikota = dynamic_cast<Walikota*>(pemain);
    walikota->tagihPajak(list_pemain);
}