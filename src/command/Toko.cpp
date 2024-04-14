#include "../header/Toko/Toko.hpp"
#include "../header/Loader/ConfigLoader.hpp"
#include "../header/Exception/Exception.hpp"
#include <vector>

using namespace std;

void beli(Pemain* pemain, ConfigLoader config, Toko toko) {
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    toko.showInventory(config);
    cout << endl;
    cout << "Uang Anda : " << pemain->getUang() << endl;
    cout << "Slot penyimpanan tersedia: " << pemain->getInventory().howMuchElement() << endl;
    cout << endl;
    int pilihanA = 0;
    int pilihanB = 0;
    int kuantitas = 0;
    while (true) {
        cout << "--- Silakan pilih menu yang anda inginkan ---" << endl;
        cout << " [1] " << "UnLimited Stock (Hewan dan Tanaman)" << endl;
        cout << " [2] " << "Limited Stock (Other Stuff)" << endl;
        cout << endl << "Pilihan : " << endl;
        cin >> pilihanA;
        cout << endl;
        if (pilihanA != 1 || pilihanA != 2) {
            cout << "Masukkan input pilihan yang benar!" << endl;
            continue;
        } else {
            int pilihanB;
            cout << "Apa barang yang ingin Anda Beli ?" << endl;
            if (pilihanA == 1) {
                cout << " [1] " << "Hewan" << endl;
                cout << " [2] " << "Tanaman" << endl;
                cout << "Pilihan : ";
                cin >> pilihanB;
                cout << endl;
                if (pilihanB != 1 || pilihanB != 2) {
                    cout << "Masukkan input pilihan yang benar!" << endl;
                    continue;   
                } else {
                    if (pilihanB == 1) {
                        // Apapun itu anj 
                    } else if (pilihanB == 2) {
                        // Apapun itu lh anj
                    }
                }
                
            } else if (pilihanA == 2) {
                // Apapun itu lh anj
            }
    }
}
    
}

void jual(Pemain* p, Toko toko) {
    if(!p->getInventory().isEmpty()) {
        while (true) {
            cout << "Berikut merupakan penyimpanan Anda" << endl;
            p->getInventory().CetakPenyimpanan();
            string input;
            cout << "Silahkan pilih petak yang ingin Anda Jual!" << endl;
            cout << "Petak : ";
            getline(cin, input);
            cout << endl;
            vector<string> temp = getInput(input);

            bool allPresent = true;

            for (const auto& item : temp) {
                if (!p->getInventory().isPresent(item)) {
                    cout << "Item " << item << " tidak ditemukan di inventori." << endl;
                    allPresent = false;
                    break;
                } else if (!p->bisaJual(p->getInventory().AmbilBarang(item))) {
                    cout << "Item " << item << " tidak dapat dijual oleh " << p->getPeran() << "!" << endl;
                    allPresent = false;
                    break;
                }
            }

            int totalHargaJual = 0;

            if (allPresent) {
                for (const auto& item : temp) {
                    Item* barang = p->ambilItem(item);
                    toko.transaksiJual(p, barang, 1);
                    totalHargaJual += barang->getPrice();
                }
                cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << totalHargaJual << "!" << endl;
                cout << endl;
                break;
            } else {
                cout << "Silahkan coba lagi dengan petak yang valid."  << endl;
                cout << endl;
            }
        }
        
    } else {
        throw NoInventorySpace();
    }
    
}

// fungsi bantuan untuk meng-handle input koma
vector<string> getInput(string input) {
    vector<string> items;
    size_t pos = 0;
    string token;
    const char delimiter = ',';

    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        token.erase(0, token.find_first_not_of(" \t\n\r\f\v"));
        token.erase(token.find_last_not_of(" \t\n\r\f\v") + 1);
        items.push_back(token);
        input.erase(0, pos + 1);
    }

    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
    items.push_back(input);

    return items;
}
