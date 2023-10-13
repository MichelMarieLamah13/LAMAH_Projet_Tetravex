
#include "../headers/MultiThread.h"
MultiThread::MultiThread() : Solver{}
{
}

Piece * MultiThread::workToDo(int pieceIdx, bool &isComplete)
{
    Piece * solution = new Piece[size];
    bool states[size];
    fill(states, states + size, false);
    // Set the starting piece
    vector<SolverState> stacks{SolverState{0, pieceIdx, 0}};

    while (!isComplete && !stacks.empty())
    {
        SolverState current = stacks.back(); // The last piece added

        if (current.position == size) // The last piece in Plateau is already added
        {
            isComplete = true;
            return solution;
        }
        else
        {
            bool hasPlacedPiece = false;
            for (int i = current.piece; i < size; i++)
            {
                if (!states[i])
                {

                    if (isValidMove(solution, &pieces[i], current.position))
                    {
                        states[i] = true; // we set the state to true because it's already placed
                        solution[current.position] = pieces[i];
                        stacks.push_back(SolverState{current.position + 1, 0, i});
                        hasPlacedPiece = true;
                        break;
                    }
                }
            }

            if (!hasPlacedPiece)
            {
                states[current.popPiece] = false;
                solution[current.position] = Piece();

                stacks.pop_back(); // remove the last state added
                if (!stacks.empty())
                {
                    stacks.back().piece = current.popPiece + 1; // we move to the next piece in initial
                }
            }
        }
    }
    return NULL;
}