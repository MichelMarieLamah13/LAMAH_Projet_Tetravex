#include "../headers/RecursiveSolver.h"

RecursiveSolver::RecursiveSolver():Sequentiel{}
{}

Piece * RecursiveSolver::algorithm()
{
    solution = new Piece[size];
    states = new bool[size];
    fill(states, states + size, false);
    recursiveAlgorithm(SolverState{0,0,0});
    return solution;
}

bool RecursiveSolver::recursiveAlgorithm(SolverState current)
{
    if(current.position == size)
    {
        return true;
    }else{
        for (int i = current.piece; i < size; i++)
        {
            if(!states[i])
            {
                if(isValidMove(solution, &pieces[i], current.position))
                {
                    states[i] = true;
                    solution[current.position]=pieces[i];
                    if(recursiveAlgorithm(SolverState{current.position + 1, 0, i}))
                    {
                        return true;
                    }
                    
                    // we undo the move
                    states[i] = false;
                    solution[current.position] = Piece();

                }
            }
        }
        
    }
    return false;
}