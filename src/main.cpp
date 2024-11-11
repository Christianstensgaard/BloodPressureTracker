#include <stdio.h>
#include <cstdlib>
#include "headers/tcpSocket.h"

#include "headers/databaseController.h"
#include "headers/threadPool.h"
#include "headers/dbModels.h"

  // Sample JSON as a char*
const char* json_data = R"(
{
  "patient": {
    "ssn": "002020201",
    "mail":"BjarneHus@outlook.dk",
    "name":"Bjarne Hus Lund"
    }
  }
}
)";







const char* connectionstring = std::getenv("connectionstring");
const char* systemApplication = std::getenv("sysApp");
const char* patientActive = std::getenv("patient_active");
const char* measureActive = std::getenv("measure_active");

using namespace bms;

DatabaseController db;


void copy(char* t1, const char* t2, int size){
  strncpy(t1, t2, size);
  t1[size] = '\0';
}



bool equal(const char* t1, const char* t2){


  for (size_t i = 0; i < 200; i++)
  {
    if(t1[i] == '\0' || t2[i] == '\0')
      break;

    if(t1[i] != t2[i])
      return false;
  }
  return true;
}









int main(int argc, char const *argv[])
{
  JsonElement jElement(json_data);



  int size = 0;

  jElement.seekTotalElements(size);


  printf("%i\n", size);


  int start = 0;
  int end = 0;

  int state = jElement.seekElement("patient", start, end);




  printf("Start: %i\n", start);
  printf("End:   %i\n", end);
  printf("State: %i\n", state);

  printf("-------------------------------------\n");
  return 0;
}
