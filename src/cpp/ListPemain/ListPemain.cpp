#include <iostream>
using namespace std;
#include "ListPemain.hpp"
#include "Exception.hpp"
#include <algorithm>
ListPemain::ListPemain(){}

ListPemain::~ListPemain(){}


// !!!add Pemain tidak include exception gulden kurang untuk walikota
void ListPemain::add_Pemain(Pemain pemain){
    check_Dupe(pemain.getUsername());
    if (pemain.getUsername() > ArrPemain.front().getUsername()){
        ArrPemain.push_back(pemain);
    }
    else{
        ArrPemain.insert(ArrPemain.begin(),pemain);
    }
    cout << "Pemain baru ditambahkan!" << endl;
    cout << "Selamat datang \"" << pemain.getUsername() << "\" di kota ini!" << endl;

}

void ListPemain::check_Dupe(string nama){
    if (nama == ""){
		throw EmptyName();
    }
	else{
        int sz = ArrPemain.size();
        for (int i = 0; i<sz; i++){
            if (ArrPemain[i].getUsername() == nama){
                throw DupeName();
            }
        }
    }
}

void ListPemain::print_AllPemain(){
    cout << "Daftar Pemain: " << endl;
    int sz = ArrPemain.size();
    for (int i = 0; i<sz; i++){
        cout << "Pemain ke-" << i+1 << ": " << ArrPemain[i].getUsername() << endl;
    }
}