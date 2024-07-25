#include<iostream>


using namespace std;

//void game::chr() {
//
//    if (a == 'c') mx = a;
//    if (b == 'c') mx = b;
//}
//
//int game::evaluate()
//{
//
//
//    // testing all winning combinations for 'a' (AI)
//    if ((array_B[0] == mx && array_B[1] == mx && array_B[2] == mx) ||
//        (array_B[3] == mx && array_B[4] == mx && array_B[5] == mx) ||
//        (array_B[6] == mx && array_B[7] == mx && array_B[8] == mx) ||
//        (array_B[0] == mx && array_B[3] == mx && array_B[6] == mx) ||
//        (array_B[1] == mx && array_B[4] == mx && array_B[7] == mx) ||
//        (array_B[2] == mx && array_B[5] == mx && array_B[8] == mx) ||
//        (array_B[0] == mx && array_B[4] == mx && array_B[8] == mx) ||
//        (array_B[2] == mx && array_B[4] == mx && array_B[6] == mx))
//        return 10;                                                                 // add points to maximize
//
//        // test all winning combinations for 'b' (Player)
//    if ((array_B[0] == mn && array_B[1] == mn && array_B[2] == mn) ||
//        (array_B[3] == mn && array_B[4] == mn && array_B[5] == mn) ||
//        (array_B[6] == mn && array_B[7] == mn && array_B[8] == mn) ||
//        (array_B[0] == mn && array_B[3] == mn && array_B[6] == mn) ||
//        (array_B[1] == mn && array_B[4] == mn && array_B[7] == mn) ||
//        (array_B[2] == mn && array_B[5] == mn && array_B[8] == mn) ||
//        (array_B[0] == mn && array_B[4] == mn && array_B[8] == mn) ||
//        (array_B[2] == mn && array_B[4] == mn && array_B[6] == mn))
//        return -10;                                                                // subtract points to minimize
//
//
//    return 0;
//}
//
//
//int game::minimax(int depth, bool toMax) {
//
//
//    int score = evaluate();                                              // gets score of board
//
//    if (score == 10)
//        return score;
//
//    if (score == -10)
//        return score;
//
//    bool movesLeft = false;                                             // helper to check if moves left on baord
//    for (int i = 0; i < 9; i++) {
//        if (array_B[i] != mx && array_B[i] != mn) {
//            movesLeft = true;
//            break;
//        }
//    }
//
//    if (!movesLeft)                                                     // tie than return 0, for no choice by ai
//        return 0;
//
//    if (toMax)                                                          //
//    {
//        int best = -1000;
//
//
//        for (int i =0; i <9; i++){
//
//            if (array_B[i] != mx && array_B[i] != mn) {
//
//                char temp = array_B[i];
//                array_B[i] = mx;
//
//                best = max( best, minimax(depth+1, !toMax) );
//
//                array_B[i] = temp;
//            }
//        }
//
//        return best;
//    }
//
//    else
//    {
//        int best = 1000;
//
//        for (int i =0; i <9; i++){
//
//            if (array_B[i] != mx && array_B[i] != mn) {
//
//                char temp = array_B[i];
//                array_B[i] = mn;
//
//                best = min( best, minimax(depth+1, !toMax) );
//
//                array_B[i] = temp;
//            }
//        }
//
//        return best;
//    }
//}
//
//// This will return the best possible move for the player
//int game::findBestMove() {
//
//    int bestVal = -1000;
//    int bestMove;
//
//    for (int i = 0; i < 9; i++) {
//
//        if (array_B[i] != mx && array_B[i] != mn) {
//
//            char temp = array_B[i];
//            // Make the move
//            array_B[i] = mx;
//
//            // compute evaluation function for this
//            // move.
//            int moveVal = minimax(0, false);
//
//            // Undo the move
//            array_B[i] = temp;
//
//            // If the value of the current move is
//            // more than the best value, then update
//            // best/
//            if (moveVal > bestVal)
//            {
//                bestMove = i;
//                bestVal = moveVal;
//            }
//        }
//
//    }
//
//    return bestMove;
//}



int game::evaluate() {
    // Winning combinations for 'a' (AI)
    if ((array_B[0] == a && array_B[1] == a && array_B[2] == a) ||
        (array_B[3] == a && array_B[4] == a && array_B[5] == a) ||
        (array_B[6] == a && array_B[7] == a && array_B[8] == a) ||
        (array_B[0] == a && array_B[3] == a && array_B[6] == a) ||
        (array_B[1] == a && array_B[4] == a && array_B[7] == a) ||
        (array_B[2] == a && array_B[5] == a && array_B[8] == a) ||
        (array_B[0] == a && array_B[4] == a && array_B[8] == a) ||
        (array_B[2] == a && array_B[4] == a && array_B[6] == a))
        return 10;

    // Winning combinations for 'b' (Player)
    if ((array_B[0] == b && array_B[1] == b && array_B[2] == b) ||
        (array_B[3] == b && array_B[4] == b && array_B[5] == b) ||
        (array_B[6] == b && array_B[7] == b && array_B[8] == b) ||
        (array_B[0] == b && array_B[3] == b && array_B[6] == b) ||
        (array_B[1] == b && array_B[4] == b && array_B[7] == b) ||
        (array_B[2] == b && array_B[5] == b && array_B[8] == b) ||
        (array_B[0] == b && array_B[4] == b && array_B[8] == b) ||
        (array_B[2] == b && array_B[4] == b && array_B[6] == b))
        return -10;

    return 0;
}

bool game::isMovesLeft() {
    for (int i = 0; i < 9; i++)
        if (array_B[i] != a && array_B[i] != b)
            return true;
    return false;
}

int game::minimax(int depth, bool toMax) {
    int score = evaluate();

    if (score == 10 || score == -10)
        return score;

    if (!isMovesLeft())
        return 0;

    if (toMax) {
        int best = -1000;
        for (int i = 0; i < 9; i++) {
            if (array_B[i] != a && array_B[i] != b) {
                char temp = array_B[i];
                array_B[i] = a;
                best = max(best, minimax(depth + 1, !toMax));
                array_B[i] = temp;
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 9; i++) {
            if (array_B[i] != a && array_B[i] != b) {
                char temp = array_B[i];
                array_B[i] = b;
                best = min(best, minimax(depth + 1, !toMax));
                array_B[i] = temp;
            }
        }
        return best;
    }
}

int game::findBestMove() {
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (array_B[i] != a && array_B[i] != b) {
            char temp = array_B[i];
            array_B[i] = a;
            int moveVal = minimax(0, false);
            array_B[i] = temp;

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

