/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <iostream>
#include "tic tac toe .h"
#include <random>
#include <unistd.h>
#include <fstream>

using namespace std;
//using namespace game;


void game::get_UC (ostream& stream) {
//getting symbols for each player

    cout << "\nenter player one symbol: ";
    cin >> game::a; stream << a;                                        // for player 1
    cout << "enter player two symbol: ";
    cin >> game::b; stream << b;                                        // for player 2
}


void game::print_CB () {
//turns an element of the array from a declared char to the player symbol
    cout << endl;
    array_B[stoi(player_SI)-1] = player_C;
    string lines = "---+---+---";
//prints board with updated spots
    cout << " " << array_B[0] << " | " << array_B[1] << " | " << array_B[2] << endl;
    cout << lines << endl;
    cout << " " << array_B[3] << " | " << array_B[4] << " | " << array_B[5] << endl;
    cout << lines << endl;
    cout << " " << array_B[6] << " | " << array_B[7] << " | " << array_B[8] << endl;
}


char game::symbol_C () {

    i++;                                           //keeps count to determine how many turns have been played
    if (i%2 == 1) return a;
    else return b;                                 //returns correct symbol for the turn
}


string game::comp () {

    int i;

    do {

        random_device rd;                                          // obtain a random number from hardware
        mt19937 gen(rd());                                     // seed the generator
        uniform_int_distribution<> distr(1, 9);              // define the range and distribution
        i = distr(gen);
    }
    while (array_B[i - 1] == a || array_B[i - 1] == b  );          // so computer choice will not be selected

    cout << "\ncomputer selects spot " << i << endl;               // notify player of computer choice

    return to_string(i);
}


void game::select_UI () {

    bool c = 1;

    if ( game::player_C == 'c' ) {player_SI = comp();}
    else {

        cout << "\nenter a selection, or type 'exit' or 'new' \n";

        while (c) {
//      inputs player spot selection
            cin >> game::player_SI;
            if (player_SI == "c") { cout << endl;   player_SI = comp(); break;  }

//      check to see if player entered special commands
            if (player_SI == "exit") {  player_SI = "terminate"; break;  }
            else if (player_SI == "new") { player_SI = "restart"; break; }

//      check if entered number is in range
            else if (stoi(player_SI) > 9) cout << "enter a number les than 9\n";
            else if (stoi(player_SI) < 1) cout << "enter a number grater than zero\n";

//      check is selection is already taken
            else if (array_B[stoi(player_SI)-1]==a || array_B[stoi(player_SI)-1]==b) {
                cout << "the space is taken\n";
            }
            else break;
        }
    }
}


void game::win_P (int &l) {

    double z = 0.0;
//for horizontal
    if ((array_B[0] == player_C) && (array_B[1] == player_C) && (array_B[2] == player_C)) {z = 1.0; l = 0;}
    else if ((array_B[3] == player_C) && (array_B[4] == player_C) && (array_B[5] == player_C)) {z = 1.0; l = 0;}
    else if ((array_B[6] == player_C) && (array_B[7] == player_C) && (array_B[8] == player_C)) {z = 1.0; l = 0;}

//for vertical
    if ((array_B[0] == player_C) && (array_B[3] == player_C) && (array_B[6] == player_C)) {z = 2.0; l = 0;}
    else if ((array_B[1] == player_C) && (array_B[4] == player_C) && (array_B[7] == player_C)) {z = 2.0; l = 0;}
    else if ((array_B[2] == player_C) && (array_B[5] == player_C) && (array_B[8] == player_C)) {z = 2.0; l = 0;}

//for diagonal
    if ((array_B[0] == player_C) && (array_B[4] == player_C) && (array_B[8] == player_C)) {z = 3.0; l = 0;}
    else if ((array_B[2] == player_C) && (array_B[4] == player_C) && (array_B[6] == player_C)) {z = 3.0; l = 0;}

//display how player won
    if (z == 1.0) cout << endl << player_C << " won horizontally\n";
    if (z == 2.0) cout << endl << player_C << " won vertically\n";
    if (z == 3.0) cout << endl << player_C << " won diagonally\n";

//for tie and resetting game
    if (z > 0.0 || i > 8) {

        char temp;
        if (i > 8) cout << "\nthere has been a tie\n\n";
        cout << "\nif you want a new game type 'y' \n";
        cin >> temp;  if (temp == 'y') l = 0;  else sleep(1); l = 3;
    }

}

// to show how and which player won, print board with just the winning players symbols displayed in the winning spots
//      do not show losing player or, symbols that are not part of the winning 3 spots


// get the first spot of the 3 spots that won, than iterrate and display the winners symbols 3 times


std::string game::getplayer_SI() { return player_SI;}                       // get player seelction

char game::getplayer_C() {return player_C;}                                 // get current player

void game::setplayer_C(char c) { player_C = c;}                             // set current player

void game::seti(int i){game::i = i;}                                        // set counter for reset

int game::geti() {return i;}                                                // get counter

void game::setarray(char* aptr) {                                           // reset array for object

    for (int i = 0; i < 10; i++) {

        array_B[i] = *aptr;
        aptr++;
    }
}
