#include "header/Save/Save.hpp"

void Save::saveState(ListPemain listPemain, Toko toko, string fileName) {
    ofstream tempFile(fileName + ".tmp"); // bikin file temp supaya ga conflict

    vector<Pemain*> arrPemain = listPemain.get_ArrPemain();

    for (int i = 0; i < arrPemain.size(); i++) {
        tempFile << arrPemain[i]->getUsername() << " " << arrPemain[i]->getPeran() << " " << arrPemain[i]->getBeratBadan() << " " << arrPemain[i]->getUang() << endl;
        tempFile << arrPemain[i]->getInventory().howMuchElement() << endl;
        for (auto itr = arrPemain[i]->getInventory().firstptr(); itr != arrPemain[i]->getInventory().endptr(); itr++) {
            tempFile << itr->second.getName() << endl;
        }
        tempFile << "ini gue butuh fungsi untuk jumlah tanaman di ladang" << endl;
        if (arrPemain[i]->getPeran() == "Petani") {
            // ini gue mo konfirm ke dhidit dl (butuh getCol getRow)
        } else if (arrPemain[i]->getPeran() == "Peternak") {
            // ini gue mo konfirm ke dhidit dl (butuh getCol getRow)
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