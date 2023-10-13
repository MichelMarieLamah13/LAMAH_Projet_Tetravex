#include "../headers/RecursiveFactory.h"
RecursiveFactory::RecursiveFactory():SolverFactory{}
{}

Solver * RecursiveFactory::createSolver()
{
    return new RecursiveSolver();
}