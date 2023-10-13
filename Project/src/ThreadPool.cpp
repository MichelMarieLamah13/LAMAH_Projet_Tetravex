#include "../headers/ThreadPool.h"

ThreadPool::ThreadPool() : ThreadPool(thread::hardware_concurrency()) {}

ThreadPool::ThreadPool(int maxThreads)
{
    this->maxThreads = maxThreads;
    isStopSignal = false;
    start();
}

void ThreadPool::add(task_type task)
{
    {
        unique_lock<mutex> lock(mu);
        tasks.push(task);
    }
    cv.notify_one();
}

void ThreadPool::doTask()
{
    while (true)
    {
        task_type task;
        {
            unique_lock<mutex> lock(mu);
            cv.wait(lock, [this]
                    { return !tasks.empty() || isStopSignal; });

            if (isStopSignal && tasks.empty())
            {
                return;
            }

            task = tasks.front();
            tasks.pop();
        }

        task();
    }
}

void ThreadPool::start()
{
    for (int i = 0; i < maxThreads; i++)
    {
        workers.push_back(thread(&ThreadPool::doTask, this));
    }
}

void ThreadPool::stop()
{
    {
        unique_lock<mutex> lock(mu);
        isStopSignal = true;
    }

    cv.notify_all();

    for (thread &t : workers)
    {
        t.join();
    }

    workers.clear();
}