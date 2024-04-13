#include "../../header/Pemain/Walikota.hpp"
#include "../../header/ListPemain/ListPemain.hpp"


void Walikota::tambahPemain(string username, string peran, ListPemain listPemain){
    if (getUang() < 50){
        throw NoMoney();
    }
    Pemain* pemainPtr = new Pemain(username, peran);
    listPemain.add_Pemain(pemainPtr);
}




Walikota::Walikota(string username): Pemain(username,"Walikota"){}