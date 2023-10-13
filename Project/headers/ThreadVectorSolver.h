#pragma once

#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>
#include "MultiThread.h"

class ThreadVectorSolver: virtual public MultiThread
{
private:
    Piece * algorithm();
public:
    ThreadVectorSolver();
};