#include "command.hpp"
#include "../header/Toko/Toko.hpp"
#include "../header/Loader/ConfigLoader.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
#include "../header/Hewan/Hewan.hpp"
#include "../header/Tanaman/Tanaman.hpp"
#include <vector>

using namespace std;

void beli(Pemain* pemain, Toko& toko){
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda beli:" << endl;
    cout << "1. Bangunan dan Produk" << endl;
    cout << "2. Tanaman" << endl;
    cout << "3. Hewan" << endl;

    cout << "Uang Anda: " << pemain->getUang() << endl;
    cout << "Slot penyimpanan tersedia: " << pemain->getInventory().SlotTersisa() << endl;

    cout << "\nPilihan: ";
    int pilihanItem;
    cin >> pilihanItem;
    if (pilihanItem < 1 || pilihanItem > 3) {
        throw "Input tidak valid!";
    }
    else {
        if (pilihanItem == 1){
            cout << "Berikut merupakan bangunan dan produk yang dapat Anda beli:" << endl;
            toko.showInventory();
            cout << "Pilihan: ";
            int pilihanToko;
            cin >> pilihanToko;
            if (pilihanToko < 1 || pilihanToko > toko.InvLength()){
                throw "Input tidak valid!";
            }
            else {
                // get inventory pada index pilihanToko
                int i = 1;
                for (const auto &it : toko.getInventory()){
                    if (i == pilihanToko){
                        cout << it.first.getName() << " - " << it.first.getPrice() << " (Stok: " << it.second << ")" << endl; // debug
                        if (pemain->getPeran() == "Walikota" && it.first.getItemType() == "Bangunan"){
                            cout << "Kamu tidak bisa membeli bangunan. Beli yang lain!" << endl;
                            break;
                        }
                        cout << "Kuantitas: ";
                        int kuantitas;
                        cin >> kuantitas;
                        // jika kuantitas input melebihi stok
                        if (kuantitas > it.second){
                            cout << "Stok tidak mencukupi!" << endl;
                            break;
                        }
                        if ((pemain->getInventory().SlotTersisa() < kuantitas) || (pemain->getInventory().isFull())){
                            throw PenyimpananTidakCukup();
                        } else if (!pemain->isUangCukup(it.first.getPrice() * kuantitas)){
                            throw NoMoney();
                        } else {
                            toko.transaksiBeli(pemain, &it.first, kuantitas);
                            cout << "Selamat Anda berhasil membeli " << kuantitas << " " << it.first.getName() << ". Uang Anda tersisa " << pemain->getUang() << "." << endl;
                            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
                            pemain->getInventory().CetakPenyimpanan();
                            for (int i = 0; i < kuantitas; i++){
                                cout << "Pilihan Slot: ";
                                string pilihanSlot;
                                cin >> pilihanSlot;
                                if (!pemain->getInventory().isLokasiValid(pilihanSlot)){
                                    throw InputSlotInvalid();
                                } else if (pemain->getInventory().isPresent(pilihanSlot)){
                                    throw "Slot sudah terisi! Pilih slot lain!";
                                } else {
                                    Item* tempItem = new Item(it.first.getItemType(), it.first.getID(), it.first.getCode(), it.first.getName(), it.first.getPrice());
                                    pemain->simpanItem(tempItem, pilihanSlot);
                                }
                            }
                            cout << "Barang berhasil disimpan!" << endl;
                        }
                        break;
                    }
                    i++;
                }
            }
        }
        else if (pilihanItem == 2){
            cout << "Berikut merupakan tanaman yang dapat Anda beli:" << endl;
            cout << "ummmm" << endl; // debug
            int i = 0;
            for (const auto& tanaman : toko.getInvTanaman()){
                cout << "ummmm3" << endl; // debug
                cout << "[" << i + 1 << "] " << tanaman.getName() << " - " << tanaman.getPrice() << endl;
                i++;
            }
            cout << "Pilihan: ";
            int pilihanTanaman;
            cin >> pilihanTanaman;
            if (pilihanTanaman < 1 || pilihanTanaman > toko.getInvTanaman().size()){
                throw "Input tidak valid!";
            }
            else {
                cout << "Kuantitas: ";
                int kuantitas;
                cin >> kuantitas;
                if ((pemain->getInventory().SlotTersisa() < kuantitas) || (pemain->getInventory().isFull())){
                    throw PenyimpananTidakCukup();
                } else if (!pemain->isUangCukup(toko.getInvTanaman()[pilihanTanaman - 1].getPrice() * kuantitas)){
                    throw NoMoney();
                } else {
                    toko.transaksiBeli(pemain, &toko.getInvTanaman()[pilihanTanaman - 1], kuantitas);
                    cout << "Selamat Anda berhasil membeli " << kuantitas << " " << toko.getInvTanaman()[pilihanTanaman - 1].getName() << ". Uang Anda tersisa " << pemain->getUang() << "." << endl;
                    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
                    pemain->getInventory().CetakPenyimpanan();
                    for (int i = 0; i < kuantitas; i++){
                        cout << "Pilihan Slot: ";
                        string pilihanSlot;
                        cin >> pilihanSlot;
                        if (!pemain->getInventory().isLokasiValid(pilihanSlot)){
                            throw InputSlotInvalid();
                        } else if (pemain->getInventory().isPresent(pilihanSlot)){
                            throw "Slot sudah terisi! Pilih slot lain!";
                        } else {
                            pemain->simpanItem(&toko.getInvTanaman()[pilihanTanaman - 1], pilihanSlot);
                        }
                    }
                    cout << "Barang berhasil disimpan!" << endl;
                }
            }
        }
        else if (pilihanItem == 3){
            cout << "Berikut merupakan hewan yang dapat Anda beli:" << endl;
            int i = 0;
            for (const auto& hewan : toko.getInvHewan()){
                cout << "[" << i + 1 << "] " << hewan->getName() << " - " << hewan->getPrice() << endl;
                i++;
            }
            cout << "Pilihan: ";
            int pilihanHewan;
            cin >> pilihanHewan;
            if (pilihanHewan < 1 || pilihanHewan > toko.getInvHewan().size()){
                throw "Input tidak valid!";
            }
            else {
                cout << "Kuantitas: ";
                int kuantitas;
                cin >> kuantitas;
                if ((pemain->getInventory().SlotTersisa() < kuantitas) || (pemain->getInventory().isFull())){
                    throw PenyimpananTidakCukup();
                } else if (!pemain->isUangCukup(toko.getInvHewan()[pilihanHewan - 1]->getPrice() * kuantitas)){
                    throw NoMoney();
                } else {
                    toko.transaksiBeli(pemain, toko.getInvHewan()[pilihanHewan - 1], kuantitas);
                    cout << "Selamat Anda berhasil membeli " << kuantitas << " " << toko.getInvHewan()[pilihanHewan - 1]->getName() << ". Uang Anda tersisa " << pemain->getUang() << "." << endl;
                    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
                    pemain->getInventory().CetakPenyimpanan();
                    for (int i = 0; i < kuantitas; i++){
                        cout << "Pilihan Slot: ";
                        string pilihanSlot;
                        cin >> pilihanSlot;
                        if (!pemain->getInventory().isLokasiValid(pilihanSlot)){
                            throw InputSlotInvalid();
                        } else if (pemain->getInventory().isPresent(pilihanSlot)){
                            throw "Slot sudah terisi! Pilih slot lain!";
                        } else {
                            pemain->simpanItem(toko.getInvHewan()[pilihanHewan - 1], pilihanSlot);
                        }
                    }
                    cout << "Barang berhasil disimpan!" << endl;
                }
            }    
        }
    }
}