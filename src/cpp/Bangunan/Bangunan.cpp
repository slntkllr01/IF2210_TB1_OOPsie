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

void Bangunan::setResep(map<string, int> resep) {
    this->listOfResep = resep;
}