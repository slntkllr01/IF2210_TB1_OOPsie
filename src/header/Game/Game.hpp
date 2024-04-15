#ifndef _GAME_HPP
#define _GAME_HPP
#include <iostream>
#include <vector>
#include "../ListPemain/ListPemain.hpp"
using namespace std;
class Game{
    protected:
        int currentturn;        //indeks currentpemain berada di ListPemain
        Pemain* currentpemain;
        ListPemain listPemain;
        static int totalTurn;
    public:
        Game(ListPemain ListPemain);
        void set_currentturn(int currentturn);
        void set_currentpemain(Pemain* p);                //check if player had met the requirements for winning
        int get_currentturn();
        string get_currentpemainname();
        int get_idxinalist(Pemain* x);
        void check_turn();
        void next_turn();
        void print_listofcommands();
        void print_winreqs();
        void start_game();

};

#endif