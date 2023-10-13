#pragma once
#include <vector>
#include <string>

#include "SolverFactory.h"
#include "IterativeFactory.h"
#include "RecursiveFactory.h"
#include "ThreadVectorFactory.h"
#include "ThreadPoolFactory.h"
#include "Helper.h"

using namespace std;
class Tetravex
{
private:
    enum SolverType
    {
        RECURSIVE,
        ITERATIVE,
        THREAD_POOL,
        THREAD_VECTOR
    };

    static vector<string> ALGO_NAMES;

    static vector<string> ALGO_DIRS;

    static vector<string> FORMAT_NAMES;

    static int choisirAlgoResolution();

    static int choisirFormat();

    static void runSolver(int algo, int format);

    static string getDataFileName(int format);
    
    static string getSolutionFilenName(int algo, int format);

public:
    Tetravex();
    static void jouer();
    static void jouer(int format, int algo);
};

