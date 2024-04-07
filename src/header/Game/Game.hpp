#ifndef _GAME_HPP
#define _GAME_HPP
#include <iostream>
#include <vector>
#include "../ListPemain/ListPemain.hpp"
using namespace std;
class Game{
    protected:
        int currentturn;
        string currentpemainname;
        ListPemain ListPemain;
    public:
        Game(int currentturn);
        void set_currentturn(int currentturn);
        void set_currentpemainname(string currentpemainname);
        void check_win();                   //check if player had met the requirements for winning
        int get_idxinalist(string x, vector<Pemain> ArrPemain);
        string get_whoseturn(int idx);               //get whose turn is it (name)
        int get_currentturn();
        void next_turn();


};

#endif