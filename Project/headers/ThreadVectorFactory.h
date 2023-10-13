#pragma once
#include "SolverFactory.h"
#include "ThreadVectorSolver.h"
class ThreadVectorFactory: public virtual SolverFactory
{
public:
    ThreadVectorFactory();
    Solver * createSolver();
    
};
