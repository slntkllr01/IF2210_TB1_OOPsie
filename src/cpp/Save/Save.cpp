#include "../../header/Save/Save.hpp"

void Save::saveState(ListPemain listPemain, Toko toko, string fileName) {
    ofstream tempFile(fileName + ".tmp"); // bikin file temp supaya ga conflict

    vector<Pemain*> arrPemain = listPemain.get_ArrPemain();

    for (int i = 0; i < arrPemain.size(); i++) {
        tempFile << arrPemain[i]->getUsername() << " " << arrPemain[i]->getPeran() << " " << arrPemain[i]->getBeratBadan() << " " << arrPemain[i]->getUang() << endl;
        tempFile << arrPemain[i]->getInventory().howMuchElement() << endl;
        for (auto itr = arrPemain[i]->getInventory().firstptr(); itr != arrPemain[i]->getInventory().endptr(); itr++) {
            tempFile << itr->second->getName() << endl;
        }
        if (arrPemain[i]->getPeran() == "Petani") {
            Petani* petani = dynamic_cast<Petani*>(arrPemain[i]);
            tempFile << petani->getLadang().getLadang().getElMap().size() << endl;
            if (!petani->getLadang().getLadang().getElMap().empty()) {
                for (auto itr = petani->getLadang().getLadang().getElMap().begin(); itr != petani->getLadang().getLadang().getElMap().end(); itr++) {
                    tempFile << itr->first << " " << itr->second->getName() << " " << itr->second->get_umur() << endl;
                }
            }
        } else if (arrPemain[i]->getPeran() == "Peternak") {
            Peternak* peternak = dynamic_cast<Peternak*>(arrPemain[i]);
            tempFile << peternak->getPeternakan().getKotak().getElMap().size() << endl;
            if (!peternak->getPeternakan().getKotak().getElMap().empty()) {
                for (auto itr = peternak->getPeternakan().getKotak().getElMap().begin(); itr != peternak->getPeternakan().getKotak().getElMap().end(); itr++) {
                    tempFile << itr->first << " " << itr->second->getName() << " " << itr->second->get_actualweight() << endl;
                }
            }
        }
    }

    tempFile << toko.InvLength() << endl;
    
    for (auto itr = toko.getInventory().begin(); itr != toko.getInventory().end(); itr++) {
        tempFile << itr->first.getName() << " " << itr->second << endl;
    }

    tempFile.close();


    remove(fileName.c_str()); // hapus file eslong
    rename((fileName + ".tmp").c_str(), fileName.c_str()); // ganti nama file temp jadi file eslong

}