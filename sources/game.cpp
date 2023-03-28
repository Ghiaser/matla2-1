#include "game.hpp"

namespace ariel
{
    Game::Game(Player p1,Player p2):playerNum_1(p1),playerNum_2(p2){}
    void Game::playTurn(){}
    void Game::printLastTurn(){}
    void Game::playAll(){}
    void Game::printWiner(){}
    void Game::printLog(){}
    void Game::printStats(){}
    void Game::draw(){draws++;}
    int Game::getDrawsCount(){return draws;}
    void Game::setwinName(string wn){winnerName=wn;}
    string Game::getwinName(){return winnerName;}
    string Game::getgameLog(){return gameLog;}
    string Game::getlastTurnLog(){return lastTurnLog;}

}
