#pragma once
#include <vector>
#include <queue>
#include <functional>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <iomanip>

using namespace std;

class ThreadPool
{
private:
    typedef function<void()> task_type;
    int maxThreads;

    vector<thread> workers;
    mutex mu;
    condition_variable cv;

    queue<task_type> tasks;
    bool isStopSignal;
    double stopWatch(task_type func);
public:
    ThreadPool();
    ThreadPool(int maxThreads);
    ThreadPool(const ThreadPool& tp): maxThreads(tp.maxThreads){};

    void doTask();
    void add(task_type task);
    void start();
    void stop();
};

