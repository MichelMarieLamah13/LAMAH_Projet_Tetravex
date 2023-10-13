#pragma once
#include "SolverFactory.h"
#include "ThreadPoolSolver.h"
class ThreadPoolFactory : public virtual SolverFactory
{
public:
    ThreadPoolFactory();
    Solver * createSolver();
};
