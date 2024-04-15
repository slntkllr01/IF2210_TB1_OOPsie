#include <iostream>
#include "../../header/Game/Game.hpp"
#include "../../header/Exception/Exception.hpp"
#include "../../command/tanam.cpp"
#include "../../command/ternak.cpp"
#include "../../command/Toko.cpp"
#include "../../command/addPemain.cpp"
#include "../../command/makan.cpp"
#include "../../command/pungutPajak.cpp"
#include "../../command/bangunBangunan.cpp"
#include "../../command/panen.cpp"
// #include "../../command/simpan.cpp"
#include "../../command/kasihMakan.cpp"
#include "../../header/Toko/Toko.hpp"
#include "../../header/Pemain/Petani.hpp"
#include "../../header/Pemain/Peternak.hpp"
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

void Game::print_listofcommands(){
    cout << "Pilihan command~" << endl;
    cout << "1. NEXT: mengakhiri giliran" << endl;
    cout << "2. CETAK_PENYIMPANAN: print isi inventory" << endl;
    cout << "3. PUNGUT_PAJAK: melakukan pemungutan pajak (Walikota)" << endl;
    cout << "4. CETAK_LADANG: print isi ladang (petani)" << endl;
    cout << "5. CETAK_PETERNAKAN: print isi peternakan (peternak)" << endl;
    cout << "6. TANAM: menanam tanaman dari inventory ke ladang (petani)" << endl;
    cout << "7. TERNAK: memindahkan ternak dari inventory ke ladang (peternak)" << endl;
    cout << "8. BANGUN: membangun bangunan sesuai resep (walikota)" << endl;
    cout << "9. MAKAN: makan makanan di inventory" << endl;
    cout << "10. KASIH_MAKAN: memberi makan ternak (peternak)" << endl;
    cout << "11. BELI: beli item di toko" << endl;
    cout << "12. JUAL: jual item di toko biar dapet cuan" << endl;
    cout << "13. PANEN: panen hewan atau tanaman (petani & peternak)" << endl;
    cout << "14. SIMPAN: simpan state game ke berkas" << endl;
    cout << "15. TAMBAH PEMAIN: tambah pemain (walikota)" << endl;
}

void Game::print_winreqs(){
    ConfigLoader& config = ConfigLoader::getInstance();
    cout << "Goal dari permainan kali ini~" << endl;
    cout << "Uang: " << config.uangMenang << endl;
    cout << "Beratbadan: " << config.beratMenang << endl;
    cout << "Pemain yang mencapai kedua syarat di atas akan memenangkan permainan ini ( •̀ ω •́ )✧!!" << endl;
}

void Game::start_game(){
    Toko toko;
    bool finish = false;
    print_winreqs();
    // game will loop continuously
    while (!finish){
        // loop asking for command until NEXT command
        while (true){
            string command;
            print_listofcommands();
            cout << "Masukkan command " << endl;
            cout << "> ";
            cin >> command;
            try {
                if (command == "NEXT") {
                    next_turn();
                    break;
                }
                else if (command == "CETAK_PENYIMPANAN") {
                    printPenyimpanan(currentpemain);
                }
                else if (command == "PUNGUT_PAJAK") {
                    pungutPajak(currentpemain,listPemain);
                }
                else if (command == "CETAK_LADANG") {
                    printLadang(currentpemain);
                }
                else if (command == "CETAK_PETERNAKAN") {
                    printPeternakan(currentpemain);
                }
                else if (command == "TANAM") {
                    tanam(currentpemain);
                }
                else if (command == "TERNAK") {
                    ternak(currentpemain);
                }
                else if (command == "BANGUN") {
                    bangunBangunan(currentpemain);
                }
                else if (command == "MAKAN") {
                    makan(currentpemain);
                }
                else if (command == "KASIH_MAKAN") {
                    kasihMakan(currentpemain);
                }
                else if (command == "BELI") {
                    beli(currentpemain, toko);
                }
                else if (command == "JUAL") {
                    jual(currentpemain, toko);
                }
                else if (command == "PANEN") {
                    if (currentpemain->getPeran() == "Petani") {
                        panen_petani(currentpemain);
                    }
                    else if (currentpemain->getPeran() == "Peternak") {
                        panen_peternak(currentpemain);
                    }
                }
                else if (command == "SIMPAN") {
                    // Handle SIMPAN command
                }
                else if (command == "TAMBAH PEMAIN") {
                    addPemain(listPemain, currentpemain);
                }
                else {
                    cout << "Masukan tidak valid, silakan ulangi lagi." << endl;
                }

                // Check win condition
                if (currentpemain->isMenang()) {
                    finish = true;
                    break;
                }
            }
            catch (Exception& e) {
                cout << e.what() << endl;
            }
        }
        
    }
    cout << "Selamat!!! player \"" << get_currentpemainname() << "\" telah memenangkan permainan~" << endl;
    
}