#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
#include "../header/Pemain/Pemain.hpp"
#include "../header/Loader/ConfigLoader.hpp"
#include "../header/Bangunan/Bangunan.hpp"
#include <vector>

void bangunBangunan(Pemain* pemain){
    // Cek peran hanya walikota yang dapat mengakses command
    if (pemain->getPeran() != "Walikota"){
        throw InvalidRole();
    }
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    ConfigLoader& configLoader = ConfigLoader::getInstance();
    for (const auto& entry : configLoader.bangunanConfigs){
        cout << "    " << entry.first << ". ";
        const auto& config = entry.second;
        cout << config.name << " (" << config.price << " gulden";
        for (const auto& resep : config.resep){
            cout << ", " << resep.first << " " << resep.second;
        }
        cout << ")" << endl;
    }

    string bangunan;
    while (true) {
        cout << "Bangunan yang ingin dibangun: " << endl;
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
            cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan " << missingMaterials.substr(0, missingMaterials.length() - 2) << "!" << endl;
            continue;
        }

        cout << chosenConfig->name << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
        
        Bangunan newBangunan(chosenBangunanID);

        Walikota* walikota = dynamic_cast<Walikota*>(pemain);

        walikota->bangunBangunan(newBangunan);
                
        break;       
    }
}
