/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <iostream>
#include <string>
#include <random>

using namespace std;


void get_UC(char&,char&);

void print_CB (char [],string,char);

char symbol_C (int&,char,char);

string comp (char [],char,char);

void select_UI (string&,char[], char , char, char);

void win_P (string,char,char [],int&,int);



int main () {
    cout << "\tAlex Carnes\t\t" << "6/5\n" << "\ttic tac toe lab\twrite program to play tic tac toe with\n\n";
//game instructions
    cout << "tic tac toe \n when asked for a selection\n :type 'exit' to stop game.\n :type 'new' to restart game\n";
    cout << " :type 'c' for a random selection by computer\n";
    cout << "type 'c' if u want the player to be a computer player\n";

    bool c = 1;
    char a,b,player_C;
    string player_SI;

while (c) {
//gets player symbols
    get_UC(a, b);
    char array_B [9] = {'1','2','3','4','5','6','7','8','9'};
    int i =0;
    int l = 1;

    while (l==1) {
//determine which player character to use for the turn, keeps count
        player_C = symbol_C(i,a,b);
        cout << "\ncurrent player is: " << player_C << endl;                     // show current player symbol
        select_UI(player_SI, array_B,a,b,player_C); //gets player spot selection, and checks if spot is already taken
//to terminate both loops
        if (player_SI == "terminate") {c = false; break;}

        if (player_SI == "restart") break;                              // to restart game by exit this loop

        print_CB(array_B,player_SI,player_C);                           // takes selection and marks the board

        if (i > 3) win_P(player_SI,player_C,array_B,l,i);            // determines winner
    }
}
    return 0;
}



void get_UC (char &a, char &b) {
//getting symbols for each player
    cout << "\nenter player one symbol:  ";
    cin >> a;                                                       // for player 1

    do {
    cout << "enter player two symbol:   ";
    cin >> b;                                                           // for player 2
    } while (a == b);

}


void print_CB (char array_B[], string player_SI,char player_C) {
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


char symbol_C (int &i, char a, char b) {

    i++;                                                //keeps count to determine how many turns have been played
    if (i%2 == 1) return a;
    else return b;                                      //returns correct symbol for the turn
}


string comp (char array_B[],char a, char b) {

    int i;

    do {

        random_device rd;                                           // obtain a random number from hardware
        mt19937 gen(rd());                                      // seed the generator
        uniform_int_distribution<> distr(1, 9);             // define the range

        i = distr(gen);                                         // variable equals random number
    }

    while (array_B[i - 1] == a || array_B[i - 1] == b );           // so computer choice will not be selected

    cout << "\ncomputer selects spot " << i << endl;                  // notify player of computer choice

    return to_string(i);
}


void select_UI (string &player_SI, char array_B[],char a, char b,char player_C) {

    bool c = 1;

    if ( player_C == 'c' ) {player_SI = comp(array_B,a,b);}
    else {

        cout << "\nenter a selection, or type 'exit' or 'new' \n";

        while (c) {
//inputs player spot selection
            cin >> player_SI;
            if (player_SI == "c") { cout << endl;   player_SI = comp(array_B, a, b); break;  }

//check to see if player entered special commands
            if (player_SI == "exit") {  player_SI = "terminate"; break;  }
            else if (player_SI == "new") { player_SI = "restart"; break; }

//  check if entered number is in range
            else if (stoi(player_SI) > 9) cout << "enter a number les than 9\n";
            else if (stoi(player_SI) < 1) cout << "enter a number grater than zero\n";

//  check is selection is already taken
            else if (array_B[stoi(player_SI) - 1] == a || array_B[stoi(player_SI) - 1] == b) {
                cout << "the space is taken\n";
            }
            else break;
        }
    }
}


void win_P (string player_SI,char player_C,char array_B[],int &l,int i) {

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


// winning system

//  activate after the 4th turn as before that impossible of a win

//  select_Ui would give most recent valid entry, use that to search around it and find a match
//      function that looks + i and -i spots until index at i == player_c
//      returns value of the index



//  character finder to be a function to be repeated multiple times for both characters
//  when the computer sees 3 characters all in correct row or diagnol than it declares that character the winner


//      check if the possible locations that will be a win


//other system

//  will iterate through nad find all locations of same charcter
//  is those character indexes indicate they are in a winning pattern than dispaly the winner
//      the pattern will be -3 and + 3 for vertical
//      +1 and -1 for horizontal
//      +4 and + 8 for diagonal or +2 and +4





// changes to program pushed

// player can select a computer to make a choice for them that is available on the board    func [ comp(); ]
// changed spacing of game to be easier to read
// player can select a player to be replaced by a computer
// program tells player there is a tie
// prompts to reset game and, resets when player indicates so
// protection so players dont have same symbol as it will break game


// to do

// fix, show how player won
// program to write game results and or gameplay to file
// use class for program



