#pragma once
#include <iostream>
#include <cstring>

namespace bms
{
  /// @brief Patient model, used to store the data into the database
  struct patientModel
  {
    char ssn[10];
    char mail[128];
    char name[50];
  };

  /// @brief Measurement model, used to store the data into the databse
  struct measurementModel
  {
    unsigned int id;
    char ssn[10];
    char date[19];

    unsigned int systolic;
    unsigned int diastolic;
    unsigned char seen;
  };


  struct queryModel
  {
    const char* quarystring;
    const char* table;
    const char* value;
  };





  void parsePatientToModel(unsigned char* stream, patientModel& patient) {
    // Copy SSN (first 10 bytes) into patient.ssn
    std::memcpy(patient.ssn, stream, 9);
    patient.ssn[9] = '\0';  // Null-terminate SSN to make it a valid C-string

    // Copy Email (next 128 bytes) into patient.mail
    std::memcpy(patient.mail, stream + 9, 127);
    patient.mail[127] = '\0';  // Null-terminate email to make it a valid C-string

    // Copy Name (next 50 bytes) into patient.name
    std::memcpy(patient.name, stream + 9 + 127, 49);
    patient.name[49] = '\0';  // Null-terminate name to make it a valid C-string
  }
  void parsePatientToStream(const patientModel& patient, unsigned char* stream) {
    // Copy SSN (10 bytes) into the stream
    std::memcpy(stream, patient.ssn, 9);  // 9 bytes (excluding null terminator)
    // Copy Email (128 bytes) into the stream
    std::memcpy(stream + 9, patient.mail, 127);  // 127 bytes (excluding null terminator)
    // Copy Name (50 bytes) into the stream
    std::memcpy(stream + 9 + 127, patient.name, 49);  // 49 bytes (excluding null terminator)
}
  void parseMeasurementData(unsigned char* stream, measurementModel& measurement) {
    // Parse 'id' (4 bytes)
    std::memcpy(&measurement.id, stream, sizeof(measurement.id));
    stream += sizeof(measurement.id);  // Move the stream pointer
    std::memcpy(measurement.ssn, stream, 9);  // 9 bytes (excluding null terminator)
    measurement.ssn[9] = '\0';  // Null-terminate SSN
    stream += 9;  // Move the stream pointer
    std::memcpy(measurement.date, stream, 18);  // 18 bytes (excluding null terminator)
    measurement.date[18] = '\0';  // Null-terminate date
    stream += 18;  // Move the stream pointer
    std::memcpy(&measurement.systolic, stream, sizeof(measurement.systolic));
    stream += sizeof(measurement.systolic);  // Move the stream pointer
    std::memcpy(&measurement.diastolic, stream, sizeof(measurement.diastolic));
    stream += sizeof(measurement.diastolic);  // Move the stream pointer
    std::memcpy(&measurement.seen, stream, sizeof(measurement.seen));
  }
  void convertToMeasurementStream(const measurementModel& measurement, unsigned char* stream) {
    std::memcpy(stream, &measurement.id, sizeof(measurement.id));
    stream += sizeof(measurement.id);  // Move the stream pointer
    std::memcpy(stream, measurement.ssn, 9);  // 9 bytes (excluding null terminator)
    stream += 9;  // Move the stream pointer
    std::memcpy(stream, measurement.date, 18);  // 18 bytes (excluding null terminator)
    stream += 18;  // Move the stream pointer
    std::memcpy(stream, &measurement.systolic, sizeof(measurement.systolic));
    stream += sizeof(measurement.systolic);  // Move the stream pointer
    std::memcpy(stream, &measurement.diastolic, sizeof(measurement.diastolic));
    stream += sizeof(measurement.diastolic);  // Move the stream pointer
    std::memcpy(stream, &measurement.seen, sizeof(measurement.seen));
  }
} // namespace bms
