#include "../header/ListPemain/ListPemain.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
#include "../header/Pemain/Pekerja.hpp"

#include <algorithm>

bool comparePajak(const pair<Pekerja*, int>& a, const pair<Pekerja*, int>& b){
    if (a.second != b.second){
        return a.second > b.second;
    }
    return a.first->getUsername() < b.first->getUsername();
}

void pungutPajak(Pemain* pemain, ListPemain& list_pemain){
    // Cek peran hanya walikota yang dapat mengakses command
    if (pemain->getPeran() != "Walikota"){
        throw InvalidRole();
    }
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl;
    cout << "\nBerikut adalah detil dari pemungutan pajak:" << endl;
    vector<Pemain*> pemains = list_pemain.get_ArrPemain();
    vector<pair<Pekerja*, int>> pajak;
    int nomor = 1;
    int total_pajak = 0;
    for (Pemain* pemain : pemains){
        // Jika dynamic_cast ke Walikota* mengembalikan nullptr, berarti pemain bukan Walikota
        if (dynamic_cast<Walikota*>(pemain) == nullptr){
            Pekerja* pekerja = dynamic_cast<Pekerja*>(pemain);
            pajak.push_back(std::make_pair(pekerja, pekerja->hitungPajak()));
            total_pajak += pekerja->hitungPajak();
        }
    }
    // Urutkan berdasarkan besar pajak terbesar
    sort(pajak.begin(), pajak.end(), comparePajak);
    for (const auto& p : pajak){
        cout << "    " << nomor++ << ". " << p.first->getUsername() << " - " << p.first->getPeran() << ": " << p.second << " gulden." << endl;
    }
    Walikota* walikota = dynamic_cast<Walikota*>(pemain);
    walikota->tagihPajak(list_pemain);
    cout << "\nNegara mendapatkan pemasukan sebesar " << total_pajak << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl;
}