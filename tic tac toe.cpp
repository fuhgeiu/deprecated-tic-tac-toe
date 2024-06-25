/*
program that operates tic tac toe
alex carnes 6/16
*/

#include <iostream>
#include <string>

using namespace std;


//int close_V(string player_SI,char array_B[],char player_C) {
//
//    for (int i = stoi(player_SI); i >= 9; i++)
//
//        if (array_B[i] == player_C)
//
//    for (int i = stoi(player_SI); i <= 0; i--)
//
//    return 0;
//}
//
//
//
//void find_C(string player_SI,char array_B[],char player_C,int &i) {
//
//    for (int i; i <= 9; i++) {
//
//        if (array_B[i] == player_C) break;
//    }
//
//    cout << i + 1;
//
//}

//int test_C1(char array_B[],char player_C,int i) {
//    int T;
//    for (i; i < 3; i++) {
//        if (array_B[i] == player_C) {T =+ i;}
//    }
//    return T;
//}
//
//void test_C(char array_B[],char player_C) {
//    int T;
//    for (int i = 0; i < 6; i+3) {
//        test_C1(array_B,player_C,i);
//
//        if (T == 3) {cout << player_C << "wins\n";}
//        else if (T == 12) {cout << player_C << "wins\n";}
//        else if (T == 21) {cout << player_C << "wins\n";}
//
//    }
//}
//
//
//void win_PS(string player_SI,char player_C, char array_B[]){
//
////  horizontal win
//
//    test_C(array_B,player_C);
//
////  vertical win
//
////  diagonal win
//
//
//}


void get_UC(char&,char&);

void print_CB (char [],string,char);

char symbol_C (int&,char,char);

void select_UI (string&,char[], char , char);

void win_P (string,char,char [],int&);


int main () {
    cout << "\tAlex Carnes\t\t" << "6/5\n" << "\ttic tac toe lab\twrite program to play tic tac toe with\n\n";
//game instructions
    cout << "tic tac toe \n when asked for a selection\n :type 'exit' to stop game.\n :type 'new' to restart game\n\n";

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
//gets player spot selection, and checks if spot is already taken
        select_UI(player_SI, array_B,a,b);
//to terminate both loops
        if (player_SI == "terminate") {c = false; break;}
//to restart game by exit this loop
        if (player_SI == "restart") break;
        //takes selection and marks the board
        print_CB(array_B,player_SI,player_C);
//determines winner
        if (i > 3) win_P(player_SI,player_C,array_B,l);
    }
}
    return 0;
}



void get_UC (char &a, char &b) {
//getting symbols for each player
    cout << "enter player one symbol:  ";
    cin >> a;
    cout << "enter player two symbol   ";
    cin >> b;
}

void print_CB (char array_B[], string player_SI,char player_C) {
//turns an element of the array from a declared char to the player symbol
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
//keeps count to determine how many turns have been played
    i++;
//returns correct symbol for the turn
    if (i%2 == 1) return a;
    else return b;
}

void select_UI (string &player_SI, char array_B[],char a, char b) {

    bool c = 1;
    cout << "enter a selection, or type 'exit' or 'new' \n";

    while (c) {
//inputs player spot selection
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


void win_P (string player_SI,char player_C,char array_B[],int &l) {
//
//    int i = (stoi(player_SI)-1);
//    int L = (i-9);
//    int L1 = (9-i);
//    int T = 0;
//    int T2 = i;
//
//
//        for (int i; i < L; i++) if (array_B[i] == player_C) T1 =+ i;
//
//        for (int i; i < L1; i--) if (array_B[i] == player_C) T2 =+ i;
//
//        if (T1 == 4 || T2 == 2 ) cout << player_C << "wins\n";
//
//        for (int i = 1; i < 9; i++) if (array_B[i-1] == player_C) T=+i;
//
//        if (T == stoi(player_SI)) cout << player_C << "wins" << endl;

//simple

//      for horizontal

    if ((array_B[0] == player_C) && (array_B[1] == player_C) && (array_B[2] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}

    else if ((array_B[3] == player_C) && (array_B[4] == player_C) && (array_B[5] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}

    else if ((array_B[6] == player_C) && (array_B[7] == player_C) && (array_B[8] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}


//      for vertical

    if ((array_B[0] == player_C) && (array_B[3] == player_C) && (array_B[6] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}

    else if ((array_B[1] == player_C) && (array_B[4] == player_C) && (array_B[7] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}

    else if ((array_B[2] == player_C) && (array_B[5] == player_C) && (array_B[8] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}


//      for diagonal

    if ((array_B[0] == player_C) && (array_B[4] == player_C) && (array_B[8] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}

    else if ((array_B[2] == player_C) && (array_B[4] == player_C) && (array_B[6] == player_C))
    {cout << player_C << " wins\n\n"; l = 0;}


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






