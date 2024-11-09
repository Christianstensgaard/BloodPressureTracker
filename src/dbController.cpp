#include "dbController.h"

void bms::createPatient(sql::Connection* con, patientModel &patient)
{
  // SQL query to insert a new patient
    const std::string query = "INSERT INTO patients (ssn, mail, name) VALUES (?, ?, ?)";
    
    try {
        sql::PreparedStatement* stmt = con->prepareStatement(query);
        stmt->setString(1, patient.ssn);
        stmt->setString(2, patient.mail);
        stmt->setString(3, patient.name);
        stmt->executeUpdate();
        std::cout << "Patient created successfully." << std::endl;
        delete stmt;
    } catch (sql::SQLException& e) {
        std::cerr << "Insert Error: " << e.what() << std::endl;
    }
}



