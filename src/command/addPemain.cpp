#include <iostream>
#include <string>
#include "command.hpp"
#include "../header/Exception/Exception.hpp"
#include "../header/Pemain/Walikota.hpp"
using namespace std;
#include <cctype>    
#include <algorithm> 

// Check if every character in the string is a whitespace character/empty
bool isWhitespaceString(const string& str) {
    return all_of(str.begin(), str.end(), [](unsigned char c) { return std::isspace(c); });
}

void addPemain(ListPemain& listPemain, Pemain* p){
    if (p->getPeran() !="Walikota"){
        throw InvalidRole();
    }
    if (!p->isUangCukup(50)){
        throw NoMoney();
    }
    string username;
    string peran;
    while(true){
        cout << "Masukkan jenis pemain: ";
        cin >> peran;
        if (peran == "Walikota"){
            cout << "Hanya boleh ada 1 walikota, silakan pilih peran Petani/Peternak." << endl;
        } 
        else if (peran == "Petani" || peran == "Peternak"){
            break;
        }
        else{
            cout << "Masukan tidak valid, silakan pilih peran Petani/Peternak." << endl;
        }   
    }
    while (true)
    {
        cout << "Masukkan nama pemain: ";
        cin >> username;
        if (!isWhitespaceString(username)){
            if (!listPemain.check_Dupe(username)){
                break;
            } 
            else{
                cout << "Nama harus unik, silakan ulangi masukan." << endl;
            }
        }
        else{
            cout << "Nama tidak boleh kosong/whitespace saja, silakan ulangi masukan." << endl;
        }
    }
    cout << "Pemain baru ditambahkan!" << endl;
    cout << "Selamat datang \"" << username << "\" di kota ini!" << endl;
    Walikota* walikota = dynamic_cast<Walikota*>(p);
    walikota->tambahPemain(username,peran,listPemain);
    // delete walikota;
}