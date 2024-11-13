#include "headers/bloodMeasurement.h"


namespace bms
{
  const char* connectionstring  = std::getenv("connectionstring");
  const char* systemApplication = std::getenv("sysApp");
  const char* patientActive     = std::getenv("patient_active");
  const char* measureActive     = std::getenv("measure_active");


  void write(string s)
  {
    std::cout << s;
  }

  void writeLine(string s)
  {
    std::cout << s << "\n";
  }


} // namespace bms




