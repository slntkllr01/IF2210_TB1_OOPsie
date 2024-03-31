#include <iostream>
#include "src/header/Game/Game.hpp"

using namespace std;
Game::Game(int currentturn):NUM_OF_PLAYER(0){
    this -> currentturn = 0;
}

void Game::set_currentturn(int currentturn){
    this -> currentturn = currentturn;
}

void Game::orderturn(){
    // TODO
}

void Game::check_win(){
    // TODO
}

void Game::get_whoseturn(){
    // return 
}

int Game::get_currentturn(){
    return currentturn;
}

int Game::get_numofplayer(){
    return NUM_OF_PLAYER;
}
