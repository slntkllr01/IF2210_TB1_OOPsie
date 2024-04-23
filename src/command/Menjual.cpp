#include "command.hpp"
#include "../header/Toko/Toko.hpp"
#include "../header/Loader/ConfigLoader.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
#include "../header/Hewan/Hewan.hpp"
#include "../header/Tanaman/Tanaman.hpp"
#include <vector>
#include <limits> 

using namespace std;
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

void jual(Pemain* p, Toko& toko){
    if(!p->getInventory().isEmpty()) {
        while (true) {
            cout << "Berikut merupakan penyimpanan Anda" << endl;
            p->getInventory().CetakPenyimpanan();
            string input;
            cout << "Silahkan pilih petak yang ingin Anda Jual!" << endl;
            cout << "Petak : ";
            // Properly use cin.ignore() only if needed
            if(cin.peek() == '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
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
                    cout << barang->getName() << endl; // debug
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
        throw InventoryEmpty();
    }
    
}

