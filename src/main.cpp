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
      "type": "c",
      "action":"createPatient",
      "name" : "Hans Petersen",
      "mail" : "hansP@outlook.dk",
      "ssn" :  "002020201",
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

void ParseJsonAndCreateTask(){
  //- Create the char* to json format. 

  JsonElement json(json_getPatient);
  json.handleRawData(); //- Create Key,value pairs for the elements


  auto res = json.find("action");

  if(res == nullptr)
    return;
 
  if(stringEqual("createPatient", res->value))
  {
    std::cout << "postMeasurement - Activated" << "\n";

    auto task = Task().create("createPatient")
      -> run([&json](){

        patientModel patient;
        patient.ssn  = json.find("ssn")->value;
        patient.name = json.find("name")->value;
        patient.mail = json.find("mail")->value;


        pC.createPatient(patient);
        return 0;
      }) -> error([](){
        std::cout << "Error creating patient";
      });

      task->execute();
    return;
  }

  if(stringEqual("getPatient", res->value)){
    std::cout << "getPatient - Activated" << '\n';

    auto task = Task().create("getPatient")
     -> run([&json](){
        auto ssn = json.find("ssn");
        std::cout << ssn->value << "\n\n";

        if(ssn == nullptr)
          return 1;

        patientModel result;
        pC.getPatient(ssn->value, result);

        std::cout << "-------------------------------------------------------\n";
        std::cout << "|\tName: " << result.name << "\n|\tMail: " << result.mail << "\n|\tssn: " << result.ssn << "\n";
        std::cout << "-------------------------------------------------------\n";

        return 0;
     }) -> error([](){
        std::cout << "\nError getting patient\n";

     }) -> final([](){
        std::cout << "Called in the end\n";
     });

     task->execute();
    return;
  }

}


int main(int argc, char const *argv[])
{
  
  //- Open Connection to db
  if(!db.openConnection())
  {
    writeLine("Failed to open connection");
    return 0;
  }

  writeLine("\n------------------------------------\n");
  //- Setup features Enable/Disable
  ParseJsonAndCreateTask();

  while(IsRunning){

  }

  return 0;
}
