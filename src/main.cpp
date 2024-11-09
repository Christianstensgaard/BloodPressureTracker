#include <stdio.h>
#include <cstdlib>

#define CONNECTIONSTRING "DO_SOME_CONNECTON";


const char* connectionstring = std::getenv("connectionstring");
const char* systemApplication = std::getenv("sysApp");


const char* patientActive = std::getenv("patient_active");
const char* measureActive = std::getenv("measure_active");




void openConnectionToDb(){
  const char* connectionString = CONNECTIONSTRING;
  printf("connecting to database!\n");

}

void openConnectionToSocket(){
  




  printf("Connecting to Websocket!\n");
}

int main(int argc, char const *argv[])
{
  printf("Hello from main!\n");

  printf("Reading Envioment\n");
  printf("Patient feature active:    -: %s\n", patientActive);
  printf("Measurement feature active -: %s\n", measureActive);
  printf("------------------\n");


  printf("Starting All the underlaying system ");


  openConnectionToDb();
  openConnectionToSocket();


  printf("Closing Application!\n");
  return 0;
}
