#pragma once

#include <stdio.h>
#include <vector>
#include <cstdlib>

#include "tcpSocket.h"
#include "dbModels.h"
#include "databaseController.h"
#include "measurementController.h"
#include "patientController.h"
#include "Task.h"
#include "threadPool.h"

using namespace bms;
using std::string;



//- Reading the Envioment variables for the system
extern const char* connectionstring;
extern const char* systemApplication;
extern const char* patientActive;
extern const char* measureActive;



namespace bms{
  extern bool IsRunning;

  void write(string s);
  void writeLine(string s);

}
