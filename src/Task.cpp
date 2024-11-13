#include "headers/Task.h"
namespace bms{
  Task::Task() : okFunction(nullptr), errorFunction(nullptr), finalFunction(nullptr) {}

  void Task::ok(std::function<void()> handler) {
      okFunction = handler;
  }

  void Task::error(std::function<void()> handler) {
      errorFunction = handler;
  }

  void Task::run(std::function<int()> handler){
    taskFunction = handler;
  }

  void Task::final(std::function<void()> handler) {
    finalFunction = handler;
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
