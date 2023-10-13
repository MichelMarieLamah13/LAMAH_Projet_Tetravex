#include "../headers/ThreadVectorSolver.h"

ThreadVectorSolver::ThreadVectorSolver() : MultiThread{}
{
}

Piece * ThreadVectorSolver::algorithm()
{
    Piece * solution = NULL;
    vector<thread> threads = {};
    bool isComplete = false;
    for (int i = 0; i < size; i++)
    {
        auto action = [&solution, &isComplete, i, this]()
        {
            Piece * tmp = MultiThread::workToDo(i, isComplete);
            if(tmp != NULL)
            {
                solution = tmp;
            }
        };

        threads.push_back(thread(action));
    }
    
    for (auto &thread : threads)
    {
        thread.join();
    }
    
    return solution;
}