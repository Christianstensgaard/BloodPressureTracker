#include "headers/bloodMeasurement.h"
#include <thread>

  // Sample JSON as a char*
  const char* json_data = R"(
  {
    "patient": {
      "type": "c",
      "action":"getMeasurement",
      "ssn" : "002020201",
      "mail": "BjarneHus@outlook.dk",
      "name": "Bjarne Hus Lund"
    }
  }
  )";


  const char* json_getPatient = R"(
  {
    "patient": {
      "type": "c",
      "action":"getPatient",
      "ssn" : "002020201",
    }
  }
  )";


  const char* json_createPatient = R"(
  {
    "patient": {
      "type":   "patient",
      "action": "createPatient",
      "name" :  "Hans Petersen",
      "mail" :  "hansP@outlook.dk",
      "ssn" :   "002020201",
    }
  }
  )";


DatabaseController db;
PatientController pC(&db);
MeasurementController mC(&db);


/// @brief Handle Raw input from network-stream
/// @param payload
void requestHandler(void* payload){
  //- Unsure what this should be doing.
  //- 14-11

}
bool stringEqual(const char* t1, const char* t2){
  int position = 0;
  while(t1[position] != '\0' || t2[position] != '\0'){
    char t1value = t1[position];
    char t2value = t2[position];

    if(t1value != t2value)
      return false;

    position++;
  }
  return true;
}

void DemoPointerTest(){
  int id;
  createJson(json_getPatient, id);

  Task *pTask = createTask(id)
  ->run ([id](){

    std::cout << "id: " << id << "\n";
    JsonElement *pJson = getJson(id);

    auto ssn = pJson->find("ssn");

    std::cout << "ssn: " << ssn->value << "\n";

    return 0;
  })->invoke()->await();
}


int main(int argc, char const *argv[])
{
  




  if(!db.openConnection())
  {
    writeLine("Failed to open connection");
    return 0;
  }


  DemoPointerTest();


  while(IsRunning){
    //- API CALL SHOULD BE PALCED HERE
  }


  std::this_thread::sleep_for(std::chrono::seconds(5));

  return 0;
}
