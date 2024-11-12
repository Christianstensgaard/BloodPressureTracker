#pragma once

#include <stdio.h>
#include <cstdlib>


#include "tcpSocket.h"
#include "databaseController.h"
#include "patientController.h"
#include "threadPool.h"
#include "dbModels.h"


//- common used classes and namespaces
using namespace bms;
using std::string;


//- Reading the Envioment variables for the system
const char* connectionstring = std::getenv("connectionstring");
const char* systemApplication = std::getenv("sysApp");
const char* patientActive = std::getenv("patient_active");
const char* measureActive = std::getenv("measure_active");


namespace bms{
  void write(string s){
    std::cout << s;
  }

  void writeLine(string s){
    std::cout << s << "\n";
  }

}
