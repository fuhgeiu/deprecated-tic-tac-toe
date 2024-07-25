#include<iostream>


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

