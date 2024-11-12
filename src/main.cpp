#include "headers/bloodMeasurement.h"

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


int main(int argc, char const *argv[])
{
  JsonElement jElement(json_data);
  std::vector<patientModel> m; 

  patientModel demo = {"22345677", "Bjarne@mail.dk", "Bjarne"};


  writeLine("Testing Patient controller!");
  printf("\n");
  db.openConnection();
  pC.createPatient(demo);
  pC.getPatient(demo.ssn);
  pC.getPatients(m);
  writeLine("");
  std::cout << "Array size: " << m.size() << "\n\n";


  writeLine("--------------------------------------");
  writeLine("Testing measurement controller!");




  writeLine("");
  printf("\n-------------------------------------\n");
  return 0;
}
