#include "headers/bloodMeasurement.h"
#include <thread>

  // Sample JSON as a char*
const char* json_data = R"(
{
  "patient": {
    "ssn": "002020201",
    "mail":"BjarneHus@outlook.dk",
    "name":"Bjarne Hus Lund"
  },

  "patient": {
    "ssn": "002020201",
    "mail":"BjarneHus@outlook.dk",
    "name":"Bjarne Hus Lund"
  }
}
)";


DatabaseController db;
PatientController pC(&db);
MeasurementController mC(&db);



//- Json handler
void apiEntry(){
  writeLine("Entry point, ");
}



//- Function to handle doctor input
int doctorHandle(){
  return 0;
}


//- Function to handle patient input
int patientHandler(){
  return 0;
}










int main(int argc, char const *argv[])
{
  Task pTask;
  pTask.run([&pTask](){
    
    writeLine("Run()");

    return *(int*) pTask.payLoad;
  });

  pTask.ok([](){
    writeLine("Ok()");
  });

  pTask.error([](){
    writeLine("Error()");
  });

  pTask.final([](){
    writeLine("Final()");
  });








  //-- | Demo function | -- 
  int value = 0;
  for (size_t i = 0; i < 10; i++)
  {
    if(i%2 == 0){
      pTask.payLoad = (void*) &value;
      value = 1;
      pTask.execute();
    } else{
      pTask.payLoad = (void*) &value;
      value = 0;
      pTask.execute();
    }

    writeLine(".");
     std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  
  return 0;
}
