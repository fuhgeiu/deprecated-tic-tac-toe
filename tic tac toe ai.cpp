#include<iostream>

using namespace std;


int game::evaluate()
{

    // Winning combinations for 'a' (AI)
    if ((array_B[0] == a && array_B[1] == a && array_B[2] == a) ||
        (array_B[3] == a && array_B[4] == a && array_B[5] == a) ||
        (array_B[6] == a && array_B[7] == a && array_B[8] == a) ||
        (array_B[0] == a && array_B[3] == a && array_B[6] == a) ||
        (array_B[1] == a && array_B[4] == a && array_B[7] == a) ||
        (array_B[2] == a && array_B[5] == a && array_B[8] == a) ||
        (array_B[0] == a && array_B[4] == a && array_B[8] == a) ||
        (array_B[2] == a && array_B[4] == a && array_B[6] == a))

        return +10;

        // Winning combinations for 'b' (Player)
    else if ((array_B[0] == b && array_B[1] == b && array_B[2] == b) ||
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


int game::minimax(int depth, bool isMax) {


    int score = evaluate();

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (isMax)
    {
        int best = -1000;


        for (int i =0; i <9; i++){

            if (array_B[i] != a) {

                char temp = array_B[i];
                array_B[i] = a;

                best = max( best,
                            minimax(depth+1, !isMax) );

                array_B[i] = temp;
            }
        }

        return best;
    }

    else
    {
        int best = 1000;

        for (int i =0; i <9; i++){

            if (array_B[i] != b) {

                char temp = array_B[i];
                array_B[i] = b;

                best = min( best,
                            minimax(depth+1, !isMax) );

                array_B[i] = temp;
            }
        }

        return best;
    }
}

// This will return the best possible move for the player
int game::findBestMove() {

    int bestVal = -1000;
    int bestMove;

    for (int i = 0; i < 9; i++) {

            if (array_B[i] != a) {

                char temp = array_B[i];
                // Make the move
                array_B[i] = a;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(0, false);

                // Undo the move
                array_B[i] = temp;

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove = i;
                    bestVal = moveVal;
                }
            }

    }

    return bestMove;
}



