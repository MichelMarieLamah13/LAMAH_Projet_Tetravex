#include "../headers/IterativeSolver.h"

IterativeSolver::IterativeSolver() : Sequentiel{}
{
}

Piece * IterativeSolver::algorithm()
{
    solution = new Piece[size];
    states = new bool[size];
    fill(states, states + size, false);
    // Set the starting piece
    vector<SolverState> stacks = {SolverState{0, 0, 0}};

    bool isComplete = false;
    while (!isComplete && !stacks.empty())
    {
        SolverState current = stacks.back(); // The last piece added

        if (current.position == size) // The last piece in Plateau is already added
        {
            isComplete = true;
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
                        solution[current.position]=pieces[i];
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

                stacks.pop_back();                          // remove the last state added
                stacks.back().piece = current.popPiece + 1; // we move to the next piece in initial
            }
        }
    }
    return solution;
}