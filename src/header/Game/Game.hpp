#ifndef _GAME_HPP
#define _GAME_HPP
#include <iostream>
#include <vector>
#include "../ListPemain/ListPemain.hpp"
using namespace std;
class Game{
    protected:
        int currentturn;
        Pemain currentpemain;
        ListPemain ListPemain;
        static int totalTurn;
    public:
        Game(int currentturn);
        void set_currentturn(int currentturn);
        void set_currentpemain(Pemain p);                //check if player had met the requirements for winning
        int get_currentturn();
        string get_currentpemainname();
        int get_idxinalist(string x);
        void check_turn();

        void next_turn();
        void start_game();

};

#endif