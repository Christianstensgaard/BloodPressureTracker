#pragma once
#include "dbModels.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <string>


namespace bms{
  void createPatient(patientModel  &patient);
  void getPatient(patientModel     &patient);
  void getAllPatients(patientModel *patients[]);

  void createMeasurement(measurementModel &measurement);
  void readMeasurement(measurementModel   &measurement);
  void updateMeasurement(measurementModel &measurement);
  void deleteMesurement(measurementModel  &measurement);

  void selectAllMeasurements(measurementModel *measurements[]);











}

