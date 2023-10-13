#pragma once
#include "Sequentiel.h"

class IterativeSolver : virtual public Sequentiel
{
private:
    Piece * algorithm();    
public:
    IterativeSolver();
};
