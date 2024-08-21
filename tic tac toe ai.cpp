#include <iostream>


using namespace std;


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

bool game::isMovesLeft() {                                                      // to check if there are open spots
    for (int i = 0; i < 9; i++)
        if (array_B[i] != a && array_B[i] != b)
            return true;                                                        // return true, if spots availible
    return false;                                                               // return false if no spots
}

int game::minimax(int depth, bool toMax) {                                      // minmax function
    int score = evaluate();

    if (score == 10 || score == -10)                                            // if test run has a score retrun it
        return score;

    if (!isMovesLeft())                                                         // if no moves left return o
        return 0;

    if (toMax) {                                                                // run to maximize (get max score, ai)
        int best = -1000;
        for (int i = 0; i < 9; i++) {
            if (array_B[i] != a && array_B[i] != b) {                           // run for empty spots
                char temp = array_B[i];                                         // temp store actual value to undo test
                array_B[i] = a;                                                 // set empty spot to maximized player
                best = max(best, minimax(depth + 1, !toMax));             // run recursive func to find max score
                array_B[i] = temp;                                              // will undo tests
            }
        }
        return best;
    } else {                                                                    // run to minimize the maximizer
        int best = 1000;                                                        // rest runs just like maximizer but
        for (int i = 0; i < 9; i++) {                                           // use minimizer varibale
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

int game::findBestMove() {                                                      // evaluate to find best move
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (array_B[i] != a && array_B[i] != b) {                               // if spot empty
            char temp = array_B[i];                                             // store actual value to tmep varibale
            array_B[i] = a;                                                     // set test to maximizer
            int moveVal = minimax(0, false);                       // set final score from mimimax function
            array_B[i] = temp;                                                  // to undo

            if (moveVal > bestVal) {                                            // when value of current move is greater
                bestMove = i;                                                   // than the best value, update best move
                bestVal = moveVal;                                              // and value
            }
        }
    }
    return bestMove;
}

