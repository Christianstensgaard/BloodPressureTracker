#pragma once
#include "dbModels.h"
#include "databaseController.h"
#include <vector>
namespace bms
{
  class PatientController{
    public:
    PatientController(DatabaseController* db);


    /// @brief Create new patient
    void createPatient(patientModel &model);
    /// @brief Get patient
    void getPatients(std::vector<patientModel> &models);
    void getPatient(std::string ssn);


    private:
    DatabaseController *db;

  };
} // namespace bms
