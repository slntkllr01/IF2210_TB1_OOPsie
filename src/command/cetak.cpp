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
    if (p->getPeran() == "Peternak"){
        Peternak* peternak = dynamic_cast<Peternak*>(p);
        peternak->getPeternakan().CetakPeternakan();
        peternak->getPeternakan().printAllHewan();
        cout << endl;
    }
    else{
        throw InvalidRole();
    }
}
void printLadang(Pemain* p){
    if (p->getPeran()=="Petani"){
        Petani* petani = dynamic_cast<Petani*>(p);
        petani->getLadang().CetakLadang();
        petani->getLadang().printAllTanaman();
        cout << endl;
    }
    else{
        throw InvalidRole();
    }
}

void printPenyimpanan(Pemain* p){
    p->getInventory().CetakPenyimpanan();
    cout << endl;
}