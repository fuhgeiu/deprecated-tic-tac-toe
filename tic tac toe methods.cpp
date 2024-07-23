/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <iostream>
#include "tic tac toe .h"
#include <random>

using namespace std;


void game::get_UC () {
//getting symbols for each player
    cout << "\nenter player one symbol: ";
    cin >> game::a;                                                       // for player 1
    cout << "enter player two symbol: ";
    cin >> game::b;                                                       // for player 2
}


void game::print_CB (char player_C) {
//turns an element of the array from a declared char to the player symbol

    cout << endl;
    game::array_B[stoi(game::player_SI)-1] = player_C;
    string lines = "---+---+---";
//prints board with updated spots
    cout << " " << game::array_B[0] << " | " << game::array_B[1] << " | " << game::array_B[2] << endl;
    cout << lines << endl;
    cout << " " << game::array_B[3] << " | " << game::array_B[4] << " | " << game::array_B[5] << endl;
    cout << lines << endl;
    cout << " " << game::array_B[6] << " | " << game::array_B[7] << " | " << game::array_B[8] << endl;
}


char game::symbol_C (int &i) {

    i++;                                                //keeps count to determine how many turns have been played
    if (i%2 == 1) return game::a;
    else return game::b;                                      //returns correct symbol for the turn
}


string game::comp () {

    int i;

    do {

        random_device rd;                                           // obtain a random number from hardware
        mt19937 gen(rd());                                      // seed the generator
        uniform_int_distribution<> distr(1, 9);             // define the range

        i = distr(gen);                                         // variable equals random number
    }

    while (game::array_B[i - 1] == a || game::array_B[i - 1] == b  );     // so computer choice will not be selected

    cout << "\ncomputer selects spot " << i << endl;                  // notify player of computer choice

    return to_string(i);
}


void game::select_UI (char player_C) {

    bool c = 1;

    if ( player_C == 'c' ) {game::player_SI = comp();}
    else {

        cout << "\nenter a selection, or type 'exit' or 'new' \n";

        while (c) {
//inputs player spot selection
            cin >> game::player_SI;
            if (game::player_SI == "c") { cout << endl;   game::player_SI = comp(); break;  }

//check to see if player entered special commands
            if (game::player_SI == "exit") {  game::player_SI = "terminate"; break;  }
            else if (game::player_SI == "new") { game::player_SI = "restart"; break; }

//  check if entered number is in range
            else if (stoi(game::player_SI) > 9) cout << "enter a number les than 9\n";
            else if (stoi(game::player_SI) < 1) cout << "enter a number grater than zero\n";

//  check is selection is already taken
            else if (game::array_B[stoi(game::player_SI)-1]==a || game::array_B[stoi(game::player_SI)-1]==b) {
                cout << "the space is taken\n";
            }
            else break;
        }
    }
}


void game::win_P (char player_C,int &l,int i) {

    int z = 0;

    if ((array_B[0] == player_C) && (array_B[1] == player_C) && (array_B[2] == player_C)) {z = 1; l = 0;}
    else if ((array_B[3] == player_C) && (array_B[4] == player_C) && (array_B[5] == player_C)) {z = 1; l = 0;}
    else if ((array_B[6] == player_C) && (array_B[7] == player_C) && (array_B[8] == player_C)) {z = 1; l = 0;}

//      for vertical

    if ((array_B[0] == player_C) && (array_B[3] == player_C) && (array_B[6] == player_C)) {z = 2; l = 0;}
    else if ((array_B[1] == player_C) && (array_B[4] == player_C) && (array_B[7] == player_C)) {z = 2; l = 0;}
    else if ((array_B[2] == player_C) && (array_B[5] == player_C) && (array_B[8] == player_C)) {z = 2; l = 0;}

//      for diagonal

    if ((array_B[0] == player_C) && (array_B[4] == player_C) && (array_B[8] == player_C)) {z = 3; l = 0;}
    else if ((array_B[2] == player_C) && (array_B[4] == player_C) && (array_B[6] == player_C)) {z = 3; l = 0;}

//       display how player won
    if (z == 1) cout << player_C << " won horizontally\n";
    if (z == 2) cout << player_C << " won vertically\n";
    if (z == 3) cout << player_C << " won diagonally\n";

//      for tie and resetting game
    if (i > 8 && l == 1) {

        char temp;
        cout << "\nthere has been a tie\n\n" << "if you want a new game type 'y' \n";
        cin >> temp;
        if (temp == 'y') l = 0;
    }

}

std::string game::getplayer_SI() { return game::player_SI;}

void game::setarray(char* aptr) {

    for (int i = 0; i < 10; i++) {

        game::array_B[i] = *aptr;
        aptr++;
    }
}
