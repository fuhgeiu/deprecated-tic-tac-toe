/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <string>
#include <iostream>

class game {

    // atributes
    char a,b;                                             // character symbols
    std::string player_SI;                                // spot to be chosen to fill in with character
    char array_B [9];
    int i,l;

    public:

        // constructer
        game (char a0,char b0,char c,std::string s) {

            a = a0; b = b0;
            player_SI = s;

        }
        // default constructer
        game (){

            a = 'a'; b = 'b';
            player_SI = "none";
            i = 0; l = 0;
        }

    // methods
    void get_UC ();                                             // get player symbols
    void print_CB (char);                                 // print current board
    char symbol_C (int &);                                      // determine current player
    std::string comp ();                                   // get computer choice(includes checks)
    void select_UI (char);                                // get and check spot selection
    void win_P (char,int &l,int);                         // determine and display winner/tie

    std::string getplayer_SI();                                 // getter for player_SI, for loop control in main
    void setarray(char*);                                // sets array for each round

};







