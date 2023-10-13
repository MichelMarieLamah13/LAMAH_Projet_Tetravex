#include "../headers/ThreadVectorFactory.h"

ThreadVectorFactory::ThreadVectorFactory():SolverFactory{}
{}

Solver * ThreadVectorFactory::createSolver()
{
    return new ThreadVectorSolver();
}