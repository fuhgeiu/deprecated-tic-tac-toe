/*
program that does cmath and trig fucntions
alex carnes 6/6
*/

#include <iostream>

using namespace std;


void get_UC (char &a, char &b) {

    cout << "enter player one symbol:  ";
    cin >> a;
    cout << "enter player two symbol   ";
    cin >> b;
}

void print_CB (char array_B[], string lines) {

    cout << " " << array_B[0] << " | " << array_B[1] << " | " << array_B[2] << endl;
    cout << lines << endl;
    cout << " " << array_B[3] << " | " << array_B[4] << " | " << array_B[5] << endl;
    cout << lines << endl;
    cout << " " << array_B[6] << " | " << array_B[7] << " | " << array_B[8] << endl;
}

char symbol_C (int &i, char a, char b) {

    char current_C;
    i++;
    if (i%2 == 1) return a;
    else   { if (i%2 == 0) return b;}
}



int main () {
    cout << "\tAlex Carnes\t\t" << "6/5\n" << "\ttic tac toe lab\twrite program to play tic tac toe with\n\n";

//    print tic tac toe board
//    get symbols for 2 users
//    get user input on selection
//    keep count to use differnt symbols
//    print updated boards
    bool c = 1;
    int i =0;
    char a,b;
    char array_B [9] = {'1','2','3','4','5','6','7','8','9'};
    string lines = "---+---+---";
//gets player symbols
    get_UC (a,b);
//    cout << a << b;
//Ddetermines character to use when printing for turns
//temporary varibale
   int T;
//temporary code to test function
   while (c) { cin >> T; cout << symbol_C (i,a,b);}







    return 0;
}