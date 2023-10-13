#include "../headers/ThreadPoolFactory.h"

ThreadPoolFactory::ThreadPoolFactory():SolverFactory{}
{

}

Solver * ThreadPoolFactory::createSolver()
{
    return new ThreadPoolSolver();
}

