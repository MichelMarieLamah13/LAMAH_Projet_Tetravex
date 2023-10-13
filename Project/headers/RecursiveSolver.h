#pragma once
#include "Sequentiel.h"
class RecursiveSolver: virtual public Sequentiel
{
private:
    Piece * algorithm();
    bool recursiveAlgorithm(SolverState current);
public:
    RecursiveSolver();
};