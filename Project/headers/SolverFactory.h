#pragma once
#include "Solver.h"
class SolverFactory
{
public:
    SolverFactory();
    virtual Solver * createSolver() = 0;
};
