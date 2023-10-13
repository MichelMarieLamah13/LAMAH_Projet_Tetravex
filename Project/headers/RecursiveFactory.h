#pragma once
#include "SolverFactory.h"
#include "RecursiveSolver.h"
class RecursiveFactory : public virtual SolverFactory
{
public:
    RecursiveFactory();
    Solver * createSolver();
};
