/*
program that does cmath and trig fucntions
alex carnes 6/6
*/

#include <iostream>

using namespace std;

//

void get_UC (char &a, char &b) {

    cout << "enter player one symbol:  ";
    cin >> a;
    cout << "enter player two symbol   ";
    cin >> b;
}

void print_CB (char array_B[]) {

    cout << array_B[0] << "|" << array_B[1] << "|" << array_B[2] << endl;

    cout << array_B[3] << "|" << array_B[4] << "|" << array_B[5] << endl;

    cout << array_B[6] << "|" << array_B[7] << "|" << array_B[8] << endl;

}




int main () {
    cout << "\tAlex Carnes\t\t" << "6/5\n" << "\ttic tac toe lab\twrite program to play tic tac toe with\n\n";

//    print tic tac toe board
//    get symbols for 2 users
//    get user input on selection
//    keep count to use differnt symbols
//    print updated boards

    char a,b;
    char array_B [9] = {1,2,3,4,5,6,7,8,9};
    string lines = "- - -";

    get_UC (a,b);
//    cout << a << b;





    return 0;
}