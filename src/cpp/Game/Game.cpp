#include <iostream>
#include "../../header/Game/Game.hpp"

using namespace std;
Game::Game(int currentturn):{
    this -> currentturn = 0;
}

void Game::set_currentturn(int currentturn){
    this -> currentturn = currentturn;
}

void Game::set_currentpemainname(string currentpemainname){
    this -> currentpemainname = currentpemainname;
}

void Game::check_win(){
    // TODO
}



// int Game::get_idxinalist(string x, vector <Pemain> ArrPemain){
//     for (int i = 0; i<(ArrPemain.size()); i++){
//         if (ArrPemain[i].nama == x){
//             return i;
//         }
//     }
//     return -1;
// }

string Game::get_whoseturn(int idx){
    // return ArrPemain[idx].getname(); 
}

int Game::get_currentturn(){
    return currentturn;
}

void Game::next_turn(){
    // cek menang
    // nambah umur semuanya
    // cek mati
    
    // orderturn(ArrPemain);   // ngurutin dulu
    int x = get_idxinalist(currentpemainname,ArrPemain);    // tahu idx baru si pemain lama tadi sblm next turn
    cout << "Pemain " << ArrPemain[x].getUsername() << " mengakhiri giliran~" << endl;
    if x+1 > ArrPemain.size();
    cout << "Sekarang giliran " << ArrPemain[x+1].getUsername() << "!" << endl; // handle idx lebih << "!" << endl;
    set_currentpemainname(ArrPemain[x+1].getUsername());        // jangan lupa setter currentplayername ke next
}