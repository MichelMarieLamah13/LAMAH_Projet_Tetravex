#pragma once
#include "Solver.h"
class Sequentiel: virtual public Solver
{
private:
    virtual Piece * algorithm() = 0;

protected:
    bool * states;
    Piece * solution;
public:
    Sequentiel();
};