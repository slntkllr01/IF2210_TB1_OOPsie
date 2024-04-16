#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
#include "../header/Pemain/Pemain.hpp"
#include "../header/Loader/ConfigLoader.hpp"
#include "../header/Bangunan/Bangunan.hpp"
#include "../header/Produk/Produk.hpp"
#include <vector>

void bangunBangunan(Pemain* pemain){
    // Cek peran hanya walikota yang dapat mengakses command
    if (pemain->getPeran() != "Walikota"){
        throw InvalidRole();
    }

    // else {
    //     Walikota* walikota = dynamic_cast<Walikota*>(pemain);
    //     if (walikota) {
    //         Produk* dummy1 = new produkTumbuhan(1);
    //         Produk* dummy2 = new produkTumbuhan(2);
    //         walikota->simpanItem(dummy1, "A01");
    //         walikota->simpanItem(dummy2, "A02");
            
    //     }
    // }

    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    ConfigLoader& configLoader = ConfigLoader::getInstance();
    for (const auto& entry : configLoader.bangunanConfigs) {
        cout << "    " << entry.first << ". ";
        const auto& config = entry.second;
        cout << config.name << " (";
        if (!config.resep.empty()) {
            auto it = config.resep.begin();
            cout << it->first << " " << it->second;

            for (++it; it != config.resep.end(); ++it) {
                cout << ", " << it->first << " " << it->second;
            }
        }
        cout << ")" << endl;
    }


    string bangunan;
    while (true) {
        cout << "Bangunan yang ingin dibangun: ";
        cin >> bangunan;
        int chosenBangunanID;
        const BangunanConfig* chosenConfig = nullptr;
        for (const auto& listbangunan : configLoader.bangunanConfigs) {
            if (bangunan == listbangunan.second.name) {
                chosenConfig = &listbangunan.second;
                chosenBangunanID = listbangunan.first;
                break;
            }
        }
        if (chosenConfig == nullptr) {
            cout << "Kamu tidak punya resep bangunan tersebut!" << endl;
            continue;
        }

        map<Item*, pair<int, vector<string>>> infoBangunanPemain = Inventory::listBahanBangunan(pemain->getInventory().getElMap());
        bool canBuild = true;
        string missingMaterials;

        for (const auto& resep : chosenConfig->resep) {
            string materialName = resep.first;
            int requiredAmount = resep.second;
            bool materialFound = false;
            for (const auto& materialEntry : infoBangunanPemain) {
                if (materialEntry.first->getName() == materialName && materialEntry.second.first >= requiredAmount) {
                    materialFound = true;
                    break;
                }
            }
            if (!materialFound) {
                missingMaterials += std::to_string(requiredAmount) + " " + materialName + ", ";
                canBuild = false;
            }
        }

        if (!canBuild) {
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
            bool first = true;
            for (const auto& resep : chosenConfig->resep) {
                string materialName = resep.first;
                int requiredAmount = resep.second;
                int haveAmount = 0;
                
                for (const auto& materialEntry : infoBangunanPemain) {
                    if (materialEntry.first->getName() == materialName) {
                        haveAmount = materialEntry.second.first;
                        break;
                    }
                }
                
                int neededAmount = requiredAmount - haveAmount;
                if (neededAmount > 0) {
                    if (!first) {
                        cout << ", ";
                    }
                    cout << neededAmount << " " << materialName;
                    first = false;
                }
            }
            cout << "!" << endl;
            continue;
        }

        cout << chosenConfig->name << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
        
        Bangunan newBangunan(chosenBangunanID);

        Walikota* walikota = dynamic_cast<Walikota*>(pemain);

        walikota->bangunBangunan(newBangunan);
                
        break;       
    }
}
