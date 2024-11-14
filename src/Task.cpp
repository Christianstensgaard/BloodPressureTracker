#include "headers/Task.h"
namespace bms{
  Task::Task() : okFunction(nullptr), errorFunction(nullptr), finalFunction(nullptr) {}


  Task *Task::create(std::string taskName){
    //- TODO Allocation and Creation of Task. 

    return this;
  }

  Task *Task::ok(std::function<void()> handler) {
      okFunction = handler;
      return this;
  }

  Task *Task::error(std::function<void()> handler) {
      errorFunction = handler;
      return this;
  }

  Task *Task::run(std::function<int()> handler){
    taskFunction = handler;
    return this;
  }

  Task *Task::final(std::function<void()> handler) {
    finalFunction = handler;
    return this;
  }

   void Task::execute() {
      try {
          int result = taskFunction();

          if (result == 0 && okFunction) {
              okFunction();
          } else if (result != 0 && errorFunction) {
              errorFunction();
          }
      } catch (const std::exception& e) {
          std::cerr << "Error occurred: " << e.what() << std::endl;
          if (errorFunction) {
              errorFunction();
          }
      } catch (...) {
          std::cerr << "Unknown error occurred." << std::endl;
          if (errorFunction) {
              errorFunction();
          }
      }

      if (finalFunction) {
          finalFunction();
      }
    }
}
