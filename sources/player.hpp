#pragma once

#include "card.hpp"
#include <string>
#include <vector>

using namespace std;

namespace ariel
{

class Player {                    // The class

private:                          //private Access specifier
    string playerName;            // Attribute
    vector<Card> cardsOwn;        //cards player have from begin of the game updated during the game
    vector<Card> cardsWon;        //cards players won from other player

public:                           // Access specifier
    Player(string pName);         // Constructor with parameters
    
    int stacksize();              // Cards amount left
    int cardesTaken();            // Cards player have won

    void setplayerName(string n); // Setter Name
    string getplayerName();       // Getter Name

    void addCard(Card c);               // add card to the player

};

}