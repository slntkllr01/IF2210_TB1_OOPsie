#ifndef _GAME_HPP
#define _GAME_HPP
#include <iostream>
#include <vector>
#include "Pemain.hpp"
using namespace std;
class Game{
    protected:
        int currentturn;
        string currentpemainname;

        vector<Pemain> ArrPemain; 
        const int NUM_OF_PLAYER;
    public:
        Game(int currentturn);
        void set_currentturn(int currentturn);
        void orderturn();                   //rearrange player turn by ordering ArrPemain order.
        void check_win();                   //check if player had met the requirements for winning
        
        void get_whoseturn();               //get whose turn is it (name)
        int get_currentturn();
        int get_numofplayer();


};

#endif