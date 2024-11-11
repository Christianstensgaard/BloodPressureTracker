#pragma once
#include <pthread.h>
namespace bms
{
  class Thread{


    public:
    template <typename Func>
    void start(Func function) {
        // Store the function pointer as a void* (for internal use)
        threadEntry = reinterpret_cast<void*>(function);

      runFunction();
    }


    //- Create some type of promise, and callback, for async


    int addToThreadPool(){
      // do nothing here yet

      return 0;
    }
    

    void runFunction(){
      if (threadEntry) {
            // Cast `threadEntry` back to the correct function pointer type and call it
            auto func = reinterpret_cast<void (*)()>(threadEntry);
            func();
        }
    }




    private:
    unsigned int threadId;
    void* threadEntry;
  };

  class Thread_engine{
    #define POL_SIZE 10

    public:
    Thread_engine(){
    }

    ~Thread_engine(){

    }

    void init(){
      printf("T_start()\n");
    }

    private:
    int position_end;
    Thread pool[POL_SIZE];
    pthread_t runners[4];
    
  };


  













} // namespace bmt



