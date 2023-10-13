#pragma once
#include "SolverFactory.h"
#include "IterativeSolver.h"
class IterativeFactory: public virtual SolverFactory
{
public:
    IterativeFactory();
    Solver * createSolver();
};
