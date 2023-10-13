#pragma once
#include "MultiThread.h"
#include "ThreadPool.h"
class ThreadPoolSolver : virtual public MultiThread
{
private:
    Piece * algorithm();
public:
    ThreadPoolSolver();
};