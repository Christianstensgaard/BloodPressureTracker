#pragma once
#include <iostream>
#include <functional>

namespace bms{
  class Task{
    public:
    using TaskFunction = std::function<int()>;
    Task();
    void run(std::function<int()> handler);
    void ok(std::function<void()> handler);
    void error(std::function<void()> handler);
    void final(std::function<void()> handler);
    void execute();


    void* payLoad;

    private:
    TaskFunction taskFunction;  // The main task to be executed
    std::function<void()> okFunction;  // Handler for success (OK)
    std::function<void()> errorFunction;  // Handler for error
    std::function<void()> finalFunction;  // Handler for final actions





  };
}