/*
program that does cmath and trig fucntions
alex carnes 6/6
*/

#include <iostream>
#include <string>

using namespace std;



void get_UC(char&,char&);

void print_CB (char [],string,char);

char symbol_C (int&,char,char);

void select_UI (string&,char[], char , char);



int main () {
    cout << "\tAlex Carnes\t\t" << "6/5\n" << "\ttic tac toe lab\twrite program to play tic tac toe with\n\n";
//game instructions
    cout << "tic tac toe \n when asked for a selection\n :type 'exit' to stop game.\n :type 'new' to restart game\n\n";
//    print tic tac toe board
//    get symbols for 2 users
//    get user input on selection
//    keep count to use differnt symbols
//    print updated boards
    bool c = 1,l = 1;
    int i =0;
    char a ='1',b ='1',player_C;
    string player_SI;

while (c) {
//gets player symbols
    get_UC(a, b);
    char array_B [9] = {'1','2','3','4','5','6','7','8','9'};

    while (l) {
//determine which player character to use for the turn, keeps count
        player_C = symbol_C(i,a,b);
//gets player spot selection, and checks if spot is already taken
        select_UI(player_SI, array_B,a,b);
//to terminate both loops
        if (player_SI == "terminate") {c = 0; break;}
//to restart game by exit this loop
        if (player_SI == "restart") break;
        //takes selection and marks the board
        print_CB(array_B,player_SI,player_C);
    }
}
    return 0;
}



void get_UC (char &a, char &b) {

    cout << "enter player one symbol:  ";
    cin >> a;
    cout << "enter player two symbol   ";
    cin >> b;
}

void print_CB (char array_B[], string player_SI,char player_C) {

    array_B[stoi(player_SI)-1] = player_C;
    string lines = "---+---+---";

    cout << " " << array_B[0] << " | " << array_B[1] << " | " << array_B[2] << endl;
    cout << lines << endl;
    cout << " " << array_B[3] << " | " << array_B[4] << " | " << array_B[5] << endl;
    cout << lines << endl;
    cout << " " << array_B[6] << " | " << array_B[7] << " | " << array_B[8] << endl;
}

char symbol_C (int &i, char a, char b) {

    i++;
    if (i%2 == 1) return a;
    else return b;
}

void select_UI (string &player_SI, char array_B[],char a, char b) {

    bool c = 1;
    cout << "enter a selection, or type 'exit' or 'new' \n";

    while (c) {

        cin >> player_SI;

//check to see if player entered special commands
        if (player_SI == "exit") {player_SI = "terminate"; break;}
        else
        if (player_SI == "new") {player_SI = "restart"; break;}
        else
//  check if entered number is in range

        if (stoi(player_SI) > 9) cout << "enter a number les than 9\n";
        else
        if (stoi(player_SI) < 1) cout << "enter a number grater than zero\n";
        else
//  check is selection is already taken
        if (array_B[stoi(player_SI)-1] == a || array_B[stoi(player_SI)-1] == b)
            {cout << "the space is taken\n";}
        else break;
    }
}