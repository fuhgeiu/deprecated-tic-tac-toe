/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <string>
#include <iostream>

namespace game
{

class game {

    // atributes
    char player_C, a, b;                                 // character symbols
    std::string player_SI;                               // spot to be chosen to fill in with character
    char array_B[9];                                     // container for board
    int i;                                               // for counter

public:

    // constructer
    game(char a0, char b0, char c, std::string s) {

        a = a0;
        b = b0;
        player_SI = s;
    }

    // default constructer
    game() {

        a = 'a';
        b = 'b';
        player_SI = "none";
        i = 0;
    }

    // methods
    void get_UC();                                        // get player symbols
    void print_CB();                                      // print current board
    char symbol_C();                                      // determine current player
    std::string comp();                                   // get computer choice(includes checks)
    void select_UI();                                     // get and check spot selection
    void win_P(int &l);                                   // determine and display winner/tie

    std::string getplayer_SI();                          // getter for player_SI, for loop control in main
    void setplayer_C(char);                              // set player_C from main
    char getplayer_C();                                  // get current player symbol
    void setarray(char *);                               // sets array for each round
    void seti (int);
    int geti();

};

}





