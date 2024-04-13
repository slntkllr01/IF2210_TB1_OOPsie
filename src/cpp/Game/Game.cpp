#include <iostream>
#include "../../header/Game/Game.hpp"
#include "../../header/Exception/Exception.hpp"
#include "../../command/tanam.cpp"
#include "../../command/ternak.cpp"
// #include "../../command/Toko.cpp" //bro wtf ini knp eror trs??!?
using namespace std;
int Game::totalTurn = 0;
Game::Game(ListPemain ListPemain){
    this -> currentturn = 0;
    this -> listPemain = ListPemain;
    this -> currentpemain = (listPemain.get_ArrPemain().front());
}

void Game::set_currentturn(int currentturn){
    this -> currentturn = currentturn;
}

void Game::set_currentpemain(Pemain* p){
    this -> currentpemain = p;
}

int Game::get_currentturn(){
    return currentturn;
}

string Game::get_currentpemainname(){
    return (listPemain.get_ArrPemain())[currentturn]->getUsername();
}

// mengembalikan indeks dimana nama pemain x berada di dalam list pemain
int Game::get_idxinalist(Pemain* x){
    vector<Pemain*> pemain = listPemain.get_ArrPemain();

    for (int i = 0; i<(pemain.size()); i++){
        if (*pemain[i] == x){
            return i;
        }
    }
    return -1;  //tidak ketemu
}

void Game::check_turn(){
    cout << "Status giliran☆*.｡" << endl;
    cout << "Sekarang adalah giliran pemain " << get_currentpemainname() << "~" << endl;
    cout << "Game telah berjalan sebanyak: " << totalTurn << "turns." << endl;
}
// check_win di pemain

void Game::next_turn(){
    // nambah umur semuanya sambil cek mati
    int sz = listPemain.get_ArrPemain().size();
    for (int i = 0; i < sz ; i++){
        if ((listPemain.get_ArrPemain())[i]->getPeran()=="Petani"){
            Petani* petani = dynamic_cast<Petani*>((listPemain.get_ArrPemain())[i]);
            // add age here
            petani->getLadang();
            delete petani;
        }
    }
    
    // ngurutin dulu
    cout << "Pemain " << get_currentpemainname() << " mengakhiri giliran~" << endl;
    
    set_currentturn((get_idxinalist(currentpemain)+1) % listPemain.get_ArrPemain().size());
    cout << "Sekarang giliran " << (listPemain.get_ArrPemain())[currentturn]->getUsername() << "!" << endl; // handle idx lebih << "!" << endl;
    // ini blm handle yang round robin queue apalah itu
    set_currentpemain((listPemain.get_ArrPemain())[currentturn]);
    totalTurn++;
}

void Game::start_game(){
    
    bool finish = false;
    // game will loop continuously
    while (!finish){
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
                currentpemain->getInventory().CetakPenyimpanan();
            }
            else if (command == "PUNGUT_PAJAK"){
                
            }
            else if (command == "CETAK_LADANG"){
                if (currentpemain->getPeran()=="Petani"){
                    Petani* petani = dynamic_cast<Petani*>(currentpemain);
                    // add age here
                    petani->getLadang().CetakLadang();
                    delete petani;
                }
                else{
                    throw InvalidRole();
                }
            }
            else if (command == "CETAK_PETERNAKAN"){
                if (currentpemain->getPeran()=="Peternak"){
                    Peternak* peternak = dynamic_cast<Peternak*>(currentpemain);
                    // add age here
                    peternak->getPeternakan().CetakPeternakan();
                    delete peternak;
                }
                else{
                    throw InvalidRole();
                }
            }
            else if (command == "TANAM"){
                try{
                    tanam(currentpemain);
                }
                catch(InvalidRole e){
                    cout << e.what() << endl;
                }
                catch(LadangFull e){
                    cout << e.what() << endl;
                }
                catch(noTanamaninInv e){
                    cout << e.what() << endl;
                }
                
            }
            else if (command == "TERNAK"){
                // ternak(currentpemain);
            }
            else if (command == "BANGUN"){

            }
            else if (command == "MAKAN"){

            }
            else if (command == "KASIH_MAKAN"){

            }
            else if (command == "BELI"){
                // beli(currentpemain);
            }
            else if (command == "JUAL"){
                // jual(currentpemain);
            }
            else if (command == "PANEN"){
                // dibedain jadi petani dan peternak
            }
            // else if (command == "MUAT"){
            //     // HANYA DPT DILAKUKAN DI AWAL MAIN!
            // }
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
                // finish = true;
                // break;
            // }
        }
        
    }
    
}