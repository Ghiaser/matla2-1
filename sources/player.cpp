#include "player.hpp"

using namespace std;
namespace ariel
{
    //constructor
    Player::Player(string pName):playerName(pName){}
    int Player::stacksize(){ return 0;}
    int Player::cardesTaken(){ return 0;}
    void Player::setplayerName(string n) {playerName = n;}
    string Player::getplayerName() {return playerName;}
    void Player::addCard(Card c){cardsOwn.push_back(c);}

}
