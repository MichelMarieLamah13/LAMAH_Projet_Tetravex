#include "../headers/IterativeFactory.h"
IterativeFactory::IterativeFactory(): SolverFactory{}
{}

Solver * IterativeFactory::createSolver()
{
    return new IterativeSolver();
}