#include <iostream>
#include <string>
#include <map>
#include "../header/Grid/Peternakan.hpp"
#include "../header/Grid/Ladang.hpp" 
#include "../header/Grid/Inventory.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Tanaman/Tanaman.hpp"
#include "../header/Hewan/Hewan.hpp"
#include "../header/Pemain/Petani.hpp"
#include "../header/Pemain/Peternak.hpp"

// void cetak_ladang()
// void cetak_peternakan()

using namespace std;

void panen_petani(Pemain* p) {
    // cetak_ladang()

    std::map<string, int>::iterator it;
    Petani* petani = dynamic_cast<Petani*>(p);

    map<string, int> ListSiapPanen;
    ListSiapPanen = petani->getLadang().getListofSiapPanen();

    if (ListSiapPanen.empty()){
        throw TidakAdaPanen();
    }

    cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
    int i = 1;
    vector<string> vector_kode_tanaman;
    // menampilkan pilihan tanaman dapat dipanen dengan iterasi
    for (it = ListSiapPanen.begin(); it != ListSiapPanen.end(); ++it) {
        cout << i << ". ";
        cout << it->first << "(" << it->second << " petak siap panen)" << endl;
        vector_kode_tanaman.push_back(it->first);
        i++;
    }

    int nomor_tanaman, jumlah_petak, maks_jumlah_panen;
    string kode_tanaman, nomor_petak;

    // pilih nomor tanaman yang akan dipanen beserta validasinya
    cout << "Nomor tanaman yang ingin dipanen: ";
    cin >> nomor_tanaman >> endl;
    if (nomor_tanaman < 1 || nomor_tanaman >= i ){
        throw InvalidNomorPanen();
    }

    // simpan kode dan jumlah tanaman yang dapat dipanen dalam variabel
    kode_tanaman = vector_kode_tanaman(nomor_tanaman-1);
    maks_jumlah_panen = ListSiapPanen.at(kode_tanaman);

    cout << "Berapa petak yang ingin dipanen: ";
    cin >> jumlah_petak >> endl;
    // Cek jumlah_petak valid dalam jumlah tanaman yang dapat dipanen
    if (jumlah_petak < 1 || jumlah_petak > maks_jumlah_panen){
        throw InvalidJumlahPanen();
    }
    // Cek jumlah_petak valid cukup disimpan di inventory
    if (jumlah_petak > p->getInventory().SlotTersisa()){
        throw PenyimpananTidakCukup();
    }

    vector<string> lokasi_dipanen;
    cout << "Pilih petak yang ingin dipanen:" << endl;
    for (int i = 1; i <= jumlah_petak; i++){
        while(true){
            cout << "Petak ke-" << i << ": ";
            cin >> nomor_petak;
            if (petani->getLadang().isLokasiValid(nomor_petak) && !petani->getLadang().isEmpty() && petani->getLadang().value(nomor_petak).getCode() == kode_tanaman){
                petani->panenTanaman(nomor_petak);
                lokasi_dipanen.push_back(nomor_petak);
                break;
            } else {
                cout << "Lokasi petak tidak valid. Masukkan lokasi kembali dengan benar!" << endl;
            }
        }
    }

    cout << jumlah_petak << " petak tanaman " << kode_tanaman;
    cout << " pada petak ";
    for(int i = 0; i < jumlah_petak-1; i++){
        cout << lokasi_dipanen(i) << ", ";
    }
    cout << lokasi_dipanen(jumlah_petak-1) << " telah dipanen!" << endl;
}

void panen_peternak(Pemain* p) {
    //cetak_peternakan()

    std::map<string, int>::iterator it;
    Peternak* peternak = dynamic_cast<Peternak*>(p);

    map<string, int> ListSiapPanen;
    ListSiapPanen = peternak->getPeternakan().getListofSiapPanen();

    if (ListSiapPanen.empty()){
        throw TidakAdaPanen();
    }

    cout << "Pilih hewan siap panen yang kamu miliki" << endl;
    int i = 1;
    vector<string> vector_kode_hewan;
    // menampilkan pilihan hewan dapat dipanen dengan iterasi
    for (it = ListSiapPanen.begin(); it != ListSiapPanen.end(); ++it) {
        cout << i << ". ";
        cout << it->first << "(" << it->second << " petak siap panen)" << endl;
        vector_kode_hewan.push_back(it->first);
        i++;
    }

    int nomor_hewan, jumlah_petak, maks_jumlah_panen;
    string kode_hewan, nomor_petak;

    // pilih nomor hewan yang akan dipanen beserta validasinya
    cout << "Nomor hewan yang ingin dipanen: ";
    cin >> nomor_hewan >> endl;
    if (nomor_hewan < 1 || nomor_hewan >= i ){
        throw InvalidNomorPanen();
    }

    // simpan kode dan jumlah hewan yang dapat dipanen dalam variabel
    kode_hewan = vector_kode_hewan(nomor_hewan-1);
    maks_jumlah_panen = ListSiapPanen.at(kode_hewan);

    cout << "Berapa petak yang ingin dipanen: ";
    cin >> jumlah_petak >> endl;
    // Cek jumlah_petak valid dalam jumlah hewan yang dapat dipanen
    if (jumlah_petak < 1 || jumlah_petak > maks_jumlah_panen){
        throw InvalidJumlahPanen();
    }
    // Cek jumlah_petak valid cukup disimpan di inventory
    if (jumlah_petak > p->getInventory().SlotTersisa()){
        throw PenyimpananTidakCukup();
    }

    vector<string> lokasi_dipanen;
    cout << "Pilih petak yang ingin dipanen:" << endl;
    for (int i = 1; i <= jumlah_petak; i++){
        while(true){
            cout << "Petak ke-" << i << ": ";
            cin >> nomor_petak;
            if (petani->getLadang().isLokasiValid(nomor_petak) && !petani->getLadang().isEmpty() && petani->getLadang().value(nomor_petak).getCode() == kode_tanaman){
                petani->panenTanaman(nomor_petak);
                lokasi_dipanen.push_back(nomor_petak);
                break;
            } else {
                cout << "Lokasi petak tidak valid. Masukkan lokasi kembali dengan benar!" << endl;
            }
        }
    }

    cout << jumlah_petak << " petak hewan " << kode_tanaman;
    cout << " pada petak ";
    for(int i = 0; i < jumlah_petak-1; i++){
        cout << lokasi_dipanen(i) << ", ";
    }
    cout << lokasi_dipanen(jumlah_petak-1) << " telah dipanen!" << endl;
}