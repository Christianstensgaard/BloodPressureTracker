#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <memory>
#include <thread>

#include "threadPool.h"

namespace bms{

    class Task{
    public:
    using TaskFunction = std::function<int()>;
    Task();
    Task *invoke();
    Task *await();
    Task *run(std::function<int()> handler);
    Task *ok(std::function<void()> handler);
    Task *error(std::function<void()> handler);
    Task *final(std::function<void()> handler);
    void execute();


    void* payLoad;

    int id = 0;

    private:
    TaskFunction taskFunction;  // The main task to be executed
    std::function<void()> okFunction;  // Handler for success (OK)
    std::function<void()> errorFunction;  // Handler for error
    std::function<void()> finalFunction;  // Handler for final actions
  
    std::unique_ptr<Thread> t;  // Replaced std::thread with Thread



  };
}
