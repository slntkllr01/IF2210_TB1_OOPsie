#include "command.hpp"
#include "../header/Toko/Toko.hpp"
#include "../header/Loader/ConfigLoader.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
#include "../header/Hewan/Hewan.hpp"
#include "../header/Tanaman/Tanaman.hpp"
#include <vector>

using namespace std;
// fungsi bantuan untuk meng-handle input koma

void beli(Pemain* pemain, Toko toko){
    ConfigLoader& loader = ConfigLoader::getInstance();
    cout << "Selamat datang di toko!!" << endl;

    cout << endl;
    cout << "\nUang Anda : " << pemain->getUang() << endl;
    cout << "Slot penyimpanan tersedia: " << pemain->getInventory().howMuchElement() << endl;
    cout << endl;
    int pilihanA, pilihanB, pilihanC, kuantitas = 0;
    while (true) {
        cout << "--- Barang yang dapat dibeli ---" << endl;
        cout << " [1] " << "BANGUNAN DAN PRODUK" << endl;
        cout << " [2] " << "TANAMAN" << endl;
        cout << " [3] " << "HEWAN" << endl;
        cout << endl << "Pilihan item yang diinginkan : " << endl;
        cin >> pilihanA;
        cout << endl;
        if (pilihanA != 1 || pilihanA != 2 || pilihanA != 3){
            cout << "Masukkan input pilihan yang benar!" << endl;
            continue;
        } else {
            cout << "Apa barang yang ingin Anda Beli ?" << endl;
            if (pilihanA == 1){
                toko.showInventory();
                cout << "Pilihan : ";
                cin >> pilihanB;
                cout << endl;
                if (pilihanB < 1 || pilihanB > toko.InvLength()){
                    cout << "Masukkan input pilihan yang benar!" << endl;
                    continue;
                } else {
                    // get inventory pada index pilihanB
                    auto it = toko.getInventory().begin();
                    advance(it, pilihanB);
                    if (pemain->getPeran() == "Walikota" && it->first.getItemType() == "Bangunan"){
                        cout << "Kamu tidak bisa membeli bangunan. Beli yang lain!" << endl;
                        continue;
                    }
                    cout << "Kuantitas : ";
                    cin >> kuantitas;
                    // jika kuantitas input melebihi stok
                    if (kuantitas > it->second) {
                        cout << "Stok tidak mencukupi!" << endl;
                        continue;
                    }
                    if (((pemain->getInventory().howMuchElement() - kuantitas) < 0) || (pemain->getInventory().isFull())){
                        throw PenyimpananTidakCukup();
                    } else if (!pemain->isUangCukup(it->first.getPrice() * kuantitas)){
                        throw NoMoney();
                    } else {
                        toko.transaksiBeli(pemain, &it->first, kuantitas);
                        cout << "Selamat Anda berhasil membeli " << kuantitas << " " << it->first.getName() << ". Uang Anda tersisa " << pemain->getUang() << "." << endl;
                    }
                } 
            } else if (pilihanA == 2) {
                cout << "Berikut adalah tanaman yang tersedia : " << endl;
                for (const auto& tanaman : loader.tanamanConfigs){
                    cout << tanaman.first << ". " << tanaman.second.name << " - " << tanaman.second.price << endl;
                }
                cout << "Pilihan : ";
                cin >> pilihanC;
                if (pilihanC < 1 || pilihanC > loader.tanamanConfigs.size()){
                    cout << "Masukkan input pilihan yang benar!" << endl;
                    continue;
                } else {
                    auto itr = loader.tanamanConfigs.find(pilihanC);
                    cout << "Kuantitas : ";
                    cin >> kuantitas;
                    if (((pemain->getInventory().howMuchElement() - kuantitas) < 0) || (pemain->getInventory().isFull())){
                        throw PenyimpananTidakCukup();
                    } else if (!pemain->isUangCukup(itr->second.price * kuantitas)){
                        throw NoMoney();
                    } else {
                        pemain->setUang(pemain->getUang() - itr->second.price * kuantitas);
                        cout << "Selamat Anda berhasil membeli " << kuantitas << " " << itr->second.name << ". Uang Anda tersisa " << pemain->getUang() << "." << endl;
                    }
                }
                auto itr = loader.tanamanConfigs.find(pilihanC);

                //         cout << "Masukkan kode hewan yang ingin anda beli! ";
                //         cin >> pilihanC;
                //         auto itr = loader.hewanConfigs.find(pilihanC);
                //         if (itr != loader.hewanConfigs.end()) {
                //             cout << "Kuantitas : ";
                //             cin >> kuantitas;
                //             if (((pemain->getInventory().howMuchElement() - kuantitas) < 0) || (pemain->getInventory().isFull())) {
                //                 throw PenyimpananTidakCukup();
                //             } else if (!pemain->isUangCukup(itr->second.price * kuantitas)) {
                //                 throw NoMoney();
                //             } else {
                //                 toko.transaksiJual(pemain, , kuantitas);
                //                 cout << "Selamat Anda berhasil membeli " << kuantitas << " " << itr->second.name << ". Uang Anda tersisa " << pemain->getUang() << "." << endl;
                //             }
                //         } else {
                //             cout << "Masukkan input pilihan yang benar!" << endl;
                //             continue;
                //         }

                //     } else if (pilihanB == 2) {
                //         cout << "Masukkan kode tanaman yang ingin anda beli! ";
                //         cin >> pilihanC;
                //         auto itr = loader.tanamanConfigs.find(pilihanC);
                //         if (itr != loader.tanamanConfigs.end()) {
                //             cout << "Kuantitas : ";
                //             cin >> kuantitas;
                //             if (((pemain->getInventory().howMuchElement() - kuantitas) < 0) || (pemain->getInventory().isFull())) {
                //                 throw PenyimpananTidakCukup();
                //             } else if (!pemain->isUangCukup(itr->second.price * kuantitas)) {
                //                 throw NoMoney();
                //             } else {
                //                 cout << "Selamat Anda berhasil membeli " << kuantitas << " " << itr->second.name << ". Uang Anda tersisa " << pemain->getUang() << "." << endl;
                //             }
                //         } else {
                //             cout << "Masukkan input pilihan yang benar!" << endl;
                //             continue;
                //         }
                //     }
                // } 
            // } else if (pilihanA == 2) {
            //     cout << "Masukkan kode barang yang ingin anda beli! ";
            //     cin >> pilihanC;

            // }
        }
    }
}