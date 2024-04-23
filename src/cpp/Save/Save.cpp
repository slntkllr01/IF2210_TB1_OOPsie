#include "../../header/Save/Save.hpp"

void Save::saveState(ListPemain listPemain, Toko toko, string fileName) {
    ofstream tempFile(fileName + ".tmp"); // bikin file temp supaya ga conflict

    if (!tempFile) {
        throw std::runtime_error("Tidak dapat membuka file sementara untuk penulisan.");
    }
    
    vector<Pemain*> arrPemain = listPemain.get_ArrPemain();

    tempFile << arrPemain.size() << endl;

    for (int i = 0; i < arrPemain.size(); i++) {
        tempFile << arrPemain[i]->getUsername() << " " << arrPemain[i]->getPeran() << " " << arrPemain[i]->getBeratBadan() << " " << arrPemain[i]->getUang() << endl;
        tempFile << arrPemain[i]->getInventory().howMuchElement() << endl;
        for (const auto& itr : arrPemain[i]->getInventory().getElMap()) {
            tempFile << itr.second->getName() << endl;
        }
        if (arrPemain[i]->getPeran() == "Petani") {
            Petani* petani = dynamic_cast<Petani*>(arrPemain[i]);
            tempFile << petani->getLadang().getElMap().size() << endl;
            if (!petani->getLadang().getElMap().empty()) {
                for (const auto& itr : petani->getLadang().getElMap()) {
                    tempFile << itr.first << " " << itr.second->getName() << " " << itr.second->get_umur() << endl;
                }
            }
        } else if (arrPemain[i]->getPeran() == "Peternak") {
            Peternak* peternak = dynamic_cast<Peternak*>(arrPemain[i]);
            tempFile << peternak->getPeternakan().getElMap().size() << endl;
            if (!peternak->getPeternakan().getElMap().empty()) {
                for (const auto& itr : peternak->getPeternakan().getElMap()) {
                    tempFile << itr.first << " " << itr.second->getName() << " " << itr.second->get_actualweight() << endl;
                }
            }
        }
    }

    tempFile << toko.InvLength() << endl;
    
    for (auto const& itr : toko.getInventory()) {
        tempFile << itr.first->getName() << " " << itr.second << endl;
    }

    tempFile.close();

    if (!tempFile.good()) {
        throw runtime_error("Error! Terjadi kesalahan saat penulisan file. Silakan coba lagi.");
    }

    remove(fileName.c_str()); // hapus file eslong
    rename((fileName + ".tmp").c_str(), fileName.c_str()); // ganti nama file temp jadi file eslong

}