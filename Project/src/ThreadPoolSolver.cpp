#include "../headers/ThreadPoolSolver.h"

ThreadPoolSolver::ThreadPoolSolver(): MultiThread{}
{

}

Piece * ThreadPoolSolver::algorithm()
{
    Piece * solution;
    ThreadPool tp(size);

    bool isComplete = false;
    for (int i = 0; i < size; i++)
    {
        auto action = [&isComplete, this, &solution, i]{
            Piece* tmp = MultiThread::workToDo(i, isComplete);
            if(tmp != NULL){
                solution = tmp;
            }
        };

        tp.add(action);
    }
    
    tp.stop();
    return solution;
}
