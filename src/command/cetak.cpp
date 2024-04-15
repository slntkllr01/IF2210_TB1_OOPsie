#include <iostream>
#include <string>
#include "command.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Grid/Peternakan.hpp"
#include "../header/Grid/Ladang.hpp"
#include "../header/Pemain/Peternak.hpp"
#include "../header/Pemain/Petani.hpp"
using namespace std;

void printPeternakan(Pemain* p){
    if (p->getPeran()=="Peternak"){
        Peternak* peternak = dynamic_cast<Peternak*>(p);
        peternak->getPeternakan().CetakPeternakan();
        // for (int i = 0; i < peternak->getPeternakan().getBaris(); i++){
        //     for (int j = 0; j < peternak->getPeternakan().getKolom(); j++) {
        //         // isi if present trus print hewan di peternakan
        //         // - A01: Cow 
        //         // - G01: Horse
 
        //     }
        // }
        delete peternak;
    }
    else{
        throw InvalidRole();
    }
}

void printLadang(Pemain* p){
    if (p->getPeran()=="Petani"){
        Petani* petani = dynamic_cast<Petani*>(p);
        petani->getLadang().CetakLadang();
        // for (int i = 0; i < petani->getLadang().getBaris(); i++){
        //     for (int j = 0; j < petani->getLadang().getKolom(); j++) {
        //         // isi if present trus print tnmn di peternakan

        //     }
        // }
        delete petani;
    }
    else{
        throw InvalidRole();
    }
}

void printPenyimpanan(Pemain* p){
    p->getInventory().CetakPenyimpanan();
}