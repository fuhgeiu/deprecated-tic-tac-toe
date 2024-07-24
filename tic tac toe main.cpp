/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <iostream>
#include "tic tac toe methods.cpp"
#include <fstream>

using namespace std;
//using namespace game;

game current;               // object decleration(using defaults)


int main () {

    cout << "\tAlex Carnes\t\t" << "6/5\n" << "\ttic tac toe lab\twrite program to play tic tac toe with\n\n";
    cout << "tic tac toe game\n\nwhen asked for a selection\n :type 'exit' to stop game\n :type 'new' to restart game\n";
    cout << " :type 'c' for a random selection by computer\n\n";
    cout << "type 'c' if u want the player to be a computer player\n";

    bool c = 1;

    while (c) {

        fstream game_log;                                                 // object for file streaming
        game_log.open("game log.txt",ios::out);                  // open file in input mode

        current.get_UC(game_log);                                                     //gets player symbols

        char array_B [9] = {'1','2','3','4','5','6','7','8','9'};

        char* aptr = & array_B[0];                                            // set pointer to array [0]

        current.setarray(aptr);                                               // reset array with pointer

        current.seti(0);                                                      // set counter to zero (reset)

        int l = 1;

        while (l==1) {
            //determine which player character to use for the turn, keeps count
            current.setplayer_C(current.game::symbol_C());                         // set player_C to current player

            cout << "\ncurrent player is: " << current.getplayer_C() << endl;         // show current player symbol

            current.select_UI();                //gets player spot selection, and checks if spot is already taken

            if (current.getplayer_SI() == "terminate") {c = false; break;}  //to terminate both loops
            if (current.getplayer_SI() == "restart") break;                 // to restart game by exit this loop

            current.print_CB();                                             // takes selection and marks the board

            if (current.geti() > 3) current.game::win_P(l);                    // determines winner
        }

    }


}


/*
 winning system (brainstorming without using simple method)

    activate after the 4th turn as before that impossible of a win

    select_Ui would give most recent valid entry, use that to search around it and find a match
      function that looks + i and -i spots until index at i == player_c
      returns value of the index

    character finder to be a function to be repeated multiple times for both characters
    when the computer sees 3 characters all in correct row or diagnol than it declares that character the winner

      check if the possible locations that will be a win

 other system

    will iterate through nad find all locations of same charcter
    is those character indexes indicate they are in a winning pattern than dispaly the winner
      the pattern will be -3 and + 3 for vertical
      +1 and -1 for horizontal
      +4 and + 8 for diagonal or +2 and +4
*/


// changes to program pushed recently

// player can select a computer to make a choice for them that is available on the board    func [ comp(); ]
// changed spacing of game to be easier to read
// player can select a player to be replaced by a computer
// program tells player there is a tie
// prompts to reset game and, resets when player indicates so
// protection so players dont have same symbol as it will break game
// added showing which method the player won
// used class(not effecticly yet)
// used pointer for resetting array
// once a player won, than ask if another game wants to be played, if no, than auto reset after amount of time

// in progress




// to do

// program to write game results and or gameplay to file
// when winning show or tell in what row or colum is occured

