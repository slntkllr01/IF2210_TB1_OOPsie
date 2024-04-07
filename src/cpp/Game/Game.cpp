#include <iostream>
#include "../../header/Game/Game.hpp"
#include "../header/Exception/Exception.hpp"
#include "../../command/tanam.cpp"
#include <algorithm>
using namespace std;
int Game::totalTurn = 0;
Game::Game(int currentturn){
    this -> currentturn = 0;
}

void Game::set_currentturn(int currentturn){
    this -> currentturn = currentturn;
}

void Game::set_currentpemain(Pemain p){
    this -> currentpemain = p;
}

int Game::get_currentturn(){
    return currentturn;
}

string Game::get_currentpemainname(){
    vector<Pemain> pemain = ListPemain.get_ArrPemain();
    return pemain[currentturn].getUsername();
}

// mengembalikan indeks dimana nama pemain x berada di dalam list pemain
int Game::get_idxinalist(string x){
    vector<Pemain> pemain = ListPemain.get_ArrPemain();

    for (int i = 0; i<(pemain.size()); i++){
        if (pemain[i].getUsername() == x){
            return i;
        }
    }
    return -1;
}

void Game::check_turn(){
    cout << "Status giliran☆*.｡" << endl;
    cout << "Sekarang adalah giliran pemain " << get_currentpemainname() << "~" << endl;
    cout << "Game telah berjalan sebanyak: " << totalTurn << "turns." << endl;
}
// check_win di pemain

void Game::next_turn(){
    // nambah umur semuanya sambil cek mati
    int sz = ListPemain.get_ArrPemain().size();
    // for (int i = 0; i < sz ; i++){
    //     if (currentpemain.)
    // }
    
    // ngurutin dulu
    int x = get_idxinalist(currentpemain.getUsername());    // tahu idx baru si pemain lama tadi sblm next turn
    cout << "Pemain " << (ListPemain.get_ArrPemain())[x].getUsername() << " mengakhiri giliran~" << endl;
        
    cout << "Sekarang giliran " << (ListPemain.get_ArrPemain())[x+1].getUsername() << "!" << endl; // handle idx lebih << "!" << endl;
    // ini blm handle yang round robin queue apalah itu
    set_currentturn(currentturn+1);
    set_currentpemain((ListPemain.get_ArrPemain())[x+1]);
    totalTurn++;
}

void Game::start_game(){

    // game will loop continuously
    while (true){
        // loop asking for command until NEXT command
        while (true){
            string command;
            cout << "Masukkan command " << endl;
            cout << "> ";
            cin >> command;
            if (command == "NEXT"){
                next_turn();
                break;
            }
            else if (command == "CETAK_PENYIMPANAN"){

            }
            else if (command == "PUNGUT_PAJAK"){
                
            }
            else if (command == "CETAK_LADANG"){

            }
            else if (command == "CETAK_PETERNAKAN"){

            }
            else if (command == "TANAM"){
                tanam(currentpemain);
            }
            else if (command == "TERNAK"){

            }
            else if (command == "BANGUN"){

            }
            else if (command == "MAKAN"){

            }
            else if (command == "KASIH_MAKAN"){

            }
            else if (command == "BELI"){

            }
            else if (command == "JUAL"){

            }
            else if (command == "PANEN"){
                // dibedain jadi petani dan peternak
            }
            else if (command == "MUAT"){
                // HANYA DPT DILAKUKAN DI AWAL MAIN!
            }
            else if (command == "SIMPAN"){

            }
            else if (command == "TAMBAH PEMAIN"){

            }
            else {
                throw InvalidInput();
            }
            // checkwin di sini
            // if (checkwin){
                // cout << "Selamat!!! player " << get_currentpemainname() << " telah memenangkan permainan~" << endl;
                // break;
            // }
        }
        
    }
    
}