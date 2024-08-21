/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <iostream>
#include "tic tac toe methods.cpp"
#include <fstream>
#include <chrono>

using namespace std;
//using namespace game;


void gameloop(game);
void print();
void clear();

int main () {

    cout << "\tAlex Carnes\t\t" << "6/5\n" << "\ttic tac toe lab\twrite program to play tic tac toe with\n\n";
    cout << "tic tac toe game\n\nwhen asked for a selection\n :type 'exit' to stop game\n :type 'new' to restart game\n";
    cout << " :type 'c' for a random selection by computer\n\n";
    cout << "type 'c' if u want the player to be a computer player\n";

    char t;

    cout << "\ndelete log file? (y),(n)\n"; cin >> t;
    if (t == 'y') clear();                                            // option to clear log file

    game player1;                                           // object decleration(using defaults)
    game player2;                                           // object decleration(using defaults)

    cout << "dual game mode ? (y),(n)\n"; cin >> t;               // option for dual game

    cout << "game_1\n";

    std::chrono::time_point<std::chrono::system_clock> start, end;          // use system clock
    start = std::chrono::system_clock::now();                               // start time

    gameloop(player1);                                         // run game 1

    if (t != 'y')   end = std::chrono::system_clock::now();

    if (t == 'y') {
        cout << "game_2\n";
        gameloop(player2);                                     // run game 2

        end = std::chrono::system_clock::now();
    }

    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "\nelapsed time is " << elapsed_seconds.count() << " seconds\n\n";

    cout << "display game log file? (y) \n"; cin >> t;
    if (t == 'y')  print();                                           // open and read log file
        else {};
}


void gameloop(game n) {

    fstream game_log;                                                 // object for file streaming
    game_log.open("game log.txt",ios::app);                  // open file in input mode
    if (!game_log) {cerr << "Error opening File "; exit(EXIT_FAILURE);}

    bool c = 1;

    while (c) {

        n.get_UC(game_log);                                                     //gets player symbols

        char array_B [9] = {'1','2','3','4','5','6','7','8','9'};
        char* aptr = & array_B[0];                                            // set pointer to array [0]
        n.setarray(aptr);                                               // reset array with pointer

        n.seti(0);                                                      // set counter to zero (reset)

        int l = 1;

        while (l==1) {
            //determine which player character to use for the turn, keeps count
            n.setplayer_C(n.symbol_C());                         // set player_C to current player

            cout << "\ncurrent player is: " << n.getplayer_C() << endl;         // show current player symbol

            n.select_UI();                //gets player spot selection, and checks if spot is already taken

            if (n.getplayer_SI() == "terminate") {c = false; break;}  //to terminate both loops
            if (n.getplayer_SI() == "restart") break;                 // to restart game by exit this loop

            n.print_CB(game_log);                                     // takes selection and marks the board

            if (n.geti() > 3) n.win_P(l,game_log);                 // determines winner
        }
        if (l == 3) break;
    }
    game_log.close();                                       // close file

}


void print(){

    fstream game_log2;
    game_log2.open("game log.txt",ios::in);                          // open file in output mode
    if (!game_log2) {cerr << "Error opening File ";  exit(EXIT_FAILURE);}     // for error opening file

    std::string sline;                                         // create variable to store data streamed from file
    while (getline(game_log2, sline)) {                  // streams line by line

        cout << sline << endl;
    }

    game_log2.close();                                                    // close file
}


void clear() {

    fstream game_log3;                                                        // new object
    game_log3.open("game log.txt",ios::out|ios::trunc);              // open in truncate mode
    if (!game_log3) {cerr << "Error opening File ";  exit(EXIT_FAILURE);}     // for error opening file
    cout << "\nfile cleared\n\n";

    game_log3.close();                                                         // close file
}




/*
 winning system (brainstorming without using simple method)

    actiafter the 4th turn as before that impossible of a win

    select_Ui would give most recent valid entry, use that to search around it and find a match
      function that looks + i and -i spots until index at i == player_c
      returns value of the index

    character finder to be a function to be repeated multiple times for both characters
    when the computer sees 3 characters all in correct row or diagnol than it declares that character the winner

      check if the possible locations that will be a win
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
// once a player won, than ask if another game wants to be played, if no than move 2 second player
// program to write game results and turns took to file
// improve format

// in progress




// to do

// have a better system for detecting a winner

// improve code by the use of pointers where applicable

// have a main home page where all game isntances are diaplayed and can eb accessed from
//      player can choose to create new instance or delete instances, also they can clear the log file
//




