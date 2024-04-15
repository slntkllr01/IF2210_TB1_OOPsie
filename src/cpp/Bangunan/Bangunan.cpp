#include "../../header/Bangunan/Bangunan.hpp"

Bangunan::Bangunan(int ID) : Item("Bangunan", id, "", "", 0) {
    ConfigLoader& loader = ConfigLoader::getInstance();
    auto it = loader.bangunanConfigs.find(id);

    if (it != loader.bangunanConfigs.end()) {
        const BangunanConfig& config = it->second;
        setID(id);
        setCode(config.code);
        setName(config.name);
        setPrice(config.price);
        setResep(config.resep);
    } else {
        throw runtime_error("Invalid Bangunan ID");
    }
}

Bangunan::Bangunan(string name) : Item("Bangunan", 0, "", name, 0) {
    ConfigLoader& loader = ConfigLoader::getInstance();
    for (auto& it : loader.bangunanConfigs) {
        const BangunanConfig& config = it.second;
        if (config.name == name) {
            setID(it.first);
            setCode(config.code);
            setName(config.name);
            setPrice(config.price);
            setResep(config.resep);
            return;
        }
    }
    throw runtime_error("Invalid Bangunan name");
}

void Bangunan::setResep(map<string, int> resep) {
    this->listOfResep = resep;
}