
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

#include "doctest.h"

    TEST_CASE("Cards Test")
    {
        Card c1("Queen of Hearts",12);
        Card c2("5 of Spades",5);
        Card c3("King of Diamonds",13);
        Card c4("ace of Clubs",1);

        CHECK(c1.isEqual(c2) == 1);                        // Queen of Hearts Bigger than 5 of Spades

        CHECK(c2.isEqual(c3) == -1);                       // 5 of Spades Smaller than 5 of Spades

        CHECK(c1.isEqual(c3) == -1);                       // Queen of Hearts smaller than King of Diamonds

        Card aceOfHearts("ace of Hearts",1);

        CHECK(aceOfHearts.isEqual(c4) == 0);               // ace of Hearts is Equal to ace of Clubs it should return 0
    }

    TEST_CASE("Game Test")
    {
        CHECK_THROWS(new Player(""));                      // Nameless player
        
        Player p1("Alice");
        Player p2("Bob");

        CHECK_THROWS(new Game(p1,p1));                     // Single player match / same player match

        CHECK_NOTHROW(new Game(p1,p2));                    // legal initializing game 
        Game game(p1,p2);

        CHECK_EQ(p1.getplayerName(),"Alice");              // "player 1" named Alice
        p2.setplayerName("Sam");
        CHECK_EQ(p2.getplayerName(),"Sam");                // after change name player two check if succesfully changed

        CHECK_EQ(p1.stacksize(),p2.stacksize());           // after initialize the game two players should have same amount of cards
        CHECK(p1.stacksize() == 26);                       // amount should be equal to 26
        CHECK_EQ(p1.cardesTaken(),p2.cardesTaken());       // Won cards for the two players should be equal in the beginning
        CHECK(p1.cardesTaken() == 0);                      // should be equal to 0


        /* launch the game three times and check functions in different cases */
        int d = game.getDrawsCount();                       
        for (int i=0;i<3;i++) {
            game.playTurn();
            if(game.getDrawsCount() > d){
                CHECK(p1.stacksize() == 26-(2+2*d));
            }
            d = game.getDrawsCount();
            CHECK(p1.stacksize() == 26-(i+1));
        }

        game.playAll();
        CHECK_EQ(p2.stacksize(), 0);                       // Both players should have 0 cards left
        CHECK_EQ(p1.stacksize(), 0);

        CHECK_NE(game.getwinName(),"");                    // should we have a winner at the end

        CHECK_EQ(p1.cardesTaken()+p2.cardesTaken() , 52);  // at end of the game the two players should have won in common 52 cards

    }

    TEST_CASE("All together")
    {
        Player p1("Alice");
        Player p2("Bob");

        Card c1("Queen of Hearts",12);
        Card c2("5 of Spades",5);
        Card c3("King of Diamonds",13);
        Card c4("ace of Clubs",1);

        Game game(p1,p2);

        /* this add card method just for the test maybe another algorithm i should use in part B */
        p1.addCard(c1);
        p1.addCard(c3);
        p2.addCard(c2);
        p2.addCard(c4);

        game.playTurn();

        CHECK_EQ(p1.cardesTaken(), 1);                       // player 1 got higher cards than player 2

        CHECK(game.getlastTurnLog() == "Alice played Queen of Hearts Bob King of Diamonds. Alice wins." );

        game.playTurn();

        CHECK_EQ(p1.cardesTaken(), 2);                       // player 1 win another turn
        CHECK( game.getlastTurnLog() == "Alice played 5 of Spades Bob ace of Clubs. Alice wins." );

        CHECK_EQ(p2.cardesTaken(), 0);                       // have no cards Taken or win

        CHECK(p1.stacksize() == 0);                          // both played there all cards
        CHECK(p2.stacksize() == 0);

        CHECK_EQ(game.getDrawsCount(),0);                     // no Draw was played

        CHECK_EQ(game.getwinName(),p1.getplayerName());      // Alice Win the Game




    }