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
MeasurementController mC(&db);


int main(int argc, char const *argv[])
{
  const char* connectionstring = std::getenv("connectionstring");
  const char* systemApplication = std::getenv("sysApp");
  const char* patientActive = std::getenv("patient_active");
  const char* measureActive = std::getenv("measure_active");



  JsonElement jElement(json_data);
  std::vector<patientModel> m; 

  patientModel demo = {"22345677", "Bjarne@mail.dk", "Bjarne"};
  patientModel result;

  writeLine("Testing Patient controller!");
  printf("\n");
  db.openConnection();
  pC.createPatient(demo);
  pC.getPatient(demo.ssn, result);


  writeLine("--------------------------");
  writeLine("getPatient() result:");
  writeLine("ssn: "   + result.ssn);
  writeLine("mail: "  + result.mail);
  writeLine("name: "  + result.name);
  writeLine("--------------------------");



  writeLine("--------------------------");
  pC.getPatients(m);
  writeLine("");
  std::cout << "Array size: " << m.size() << "\n\n";


  writeLine("--------------------------------------");
  writeLine("Testing measurement controller!");
  measurementModel targetMeasurement = {
    0,
    demo.ssn,
    "2024-11-13 12:30:00",
    110,
    30,
    0
  };


  writeLine("ssn: "   + targetMeasurement.ssn);
  writeLine("date: "  +targetMeasurement.date);
  mC.createMeasurement(targetMeasurement);





  writeLine("");
  printf("\n-------------------------------------\n");
  return 0;
}
