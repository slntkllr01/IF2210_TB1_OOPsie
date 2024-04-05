#include <iostream>
using namespace std;
#include "ListPemain.hpp"
#include "Exception.hpp"
#include <algorithm>
ListPemain::ListPemain(){}

ListPemain::~ListPemain(){}


// !!!add Pemain tidak include exception gulden kurang untuk walikota
void ListPemain::add_Pemain(){
    while(true){
        cout << "Masukkan jenis pemain: ";
        string newjob; getline(cin, newjob);
        try{
            if (newjob=="Walikota"){
                throw OneWalikota();
            }
            else if (newjob!="Petani" || newjob!="Peternak"){
                throw InvalidInput();
            }
        }
        catch(OneWalikota e){
            cout << e.what() << endl;
        }
        catch(InvalidInput e){
            cout << e.what() << endl;
        }
        cout << "Masukkan nama pemain baru: ";
        string newname; getline(cin, newname);
        try{
            check_Dupe(newname);
            if (newname > ArrPemain.front().getUsername()){
                ArrPemain.push_back(Pemain(newname, newjob));
            }
            else{
                ArrPemain.insert(ArrPemain.begin(),Pemain(newname,newjob));
            }
            cout << "Pemain baru ditambahkan!" << endl;
            cout << "Selamat datang \"" << newname << "\" di kota ini!" << endl;
            break;
        }
        catch(DupeName e){
            cout << e.what() << endl;
        }
        catch(EmptyName e){
            cout << e.what() << endl;
        }
    }
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