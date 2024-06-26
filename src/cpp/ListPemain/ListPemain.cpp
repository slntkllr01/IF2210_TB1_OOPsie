#include <iostream>
using namespace std;
#include "../../header/ListPemain/ListPemain.hpp"
#include "../../header/Exception/Exception.hpp"
#include <algorithm>
ListPemain::ListPemain(){}

ListPemain::~ListPemain(){}

bool ListPemain::compareNames(const Pemain* a, const Pemain* b) {
    return a->getUsername() < b->getUsername();
}

void ListPemain::add_Pemain(Pemain* pemain){
    ArrPemain.push_back(pemain);
    sort(ArrPemain.begin(), ArrPemain.end(), compareNames);
}

bool ListPemain::check_Dupe(string nama){
    int sz = ArrPemain.size();
    for (int i = 0; i<sz; i++){
        if (ArrPemain[i]->getUsername() == nama){
            return true;
        }
    }
    return false;
}

void ListPemain::print_AllPemain(){
    cout << "Daftar Pemain: " << endl;
    int sz = ArrPemain.size();
    for (int i = 0; i<sz; i++){
        cout << "Pemain ke-" << i+1 << ": " << ArrPemain[i]->getUsername() << endl;
    }
}

vector<Pemain*> ListPemain::get_ArrPemain(){
    return ArrPemain;
}