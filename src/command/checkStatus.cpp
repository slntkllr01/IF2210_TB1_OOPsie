#include "command.hpp"
#include "../header/Pemain/Pemain.hpp"

void checkStatus(Pemain* pemain){
    cout << "<<<<<<<<<< STATUS PEMAIN >>>>>>>>>>" << endl;
    cout << "🧑👧🏻🧓🏻👶🏻🧑🏻‍🦰👸🏻🤴🏻🫅🏻🧑🏻‍✈️🧑🏻‍🚒🧕🏻👨🏻‍🍳👩🏻‍🌾" << endl;
    cout << "Nama: " << pemain->getUsername() << endl;
    cout << "Peran: " << pemain->getPeran() << endl;
    cout << "Uang: " << pemain->getUang() << " Gulden" << endl;
    cout << "Berat Badan: " << pemain->getBeratBadan() << endl;
}