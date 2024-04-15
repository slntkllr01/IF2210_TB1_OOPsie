#include "../header/Exception/Exception.hpp"
// #include "../header/Pemain/Walikota.hpp"
#include "../header/Pemain/Pemain.hpp"
#include "../header/Loader/ConfigLoader.hpp"
#include "../header/Bangunan/Bangunan.hpp"
#include <vector>
#include <climits>

/* HELPER FUNCTIONS */

/* Mendapatkan harga dari bangunan termurah */
int lowest_price(const map<int, BangunanConfig>& bangunanConfigs){
    int min_price = INT_MAX;
    for (const auto& entry : bangunanConfigs){
        min_price = min(min_price, entry.second.price);
    }
    return min_price;
}

/* Mendapatkan list id bangunan yang dapat dibangun dengan uang saat ini */
vector<int> getAffordableBuildings(const map<int, BangunanConfig>& bangunanConfigs, const int uang){
    vector<int> affordable;
    for (const auto& entry : bangunanConfigs){
        if (uang >= entry.second.price){
            affordable.push_back(entry.first);
        }
    }
    return affordable;
}

/* Mendapatkan semua bahan di inventory */


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
    // Cek uang cukup
    if (!pemain->isUangCukup(lowest_price(configLoader.bangunanConfigs))){
        cout << "Kamu tidak bisa membangun bangunan. ";
        throw NoMoney();
    }
    // List id bangunan memungkinkan dibeli
    vector<int> affordable = getAffordableBuildings(configLoader.bangunanConfigs, pemain->getUang());

}
