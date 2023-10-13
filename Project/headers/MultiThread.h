#pragma once
#include "Solver.h"
class MultiThread: virtual public Solver
{
private:
    virtual Piece * algorithm() = 0;

protected:
    Piece * workToDo(int pieceIdx, bool & isComplete);
    
public:
    MultiThread();
    
};