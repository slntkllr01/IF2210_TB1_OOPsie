#include <iostream>
using namespace std;
#include "../../header/ListPemain/ListPemain.hpp"
#include "../../header/Exception/Exception.hpp"
#include <algorithm>
ListPemain::ListPemain(){}

ListPemain::~ListPemain(){}

bool ListPemain::compareNames(const Pemain& a, const Pemain& b) {
    return a.getUsername() < b.getUsername();
}

// !!!add Pemain tidak include exception gulden kurang untuk walikota
void ListPemain::add_Pemain(Pemain pemain){
    check_Dupe(pemain.getUsername());
    ArrPemain.push_back(pemain);
    sort(ArrPemain.begin(), ArrPemain.end(), compareNames);
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