#pragma once
#include "dbModels.h"
namespace bms{

  typedef unsigned char uchar;

  class PatientController{
    public:

    int addPatient(uchar* stream);
    int getPatient(uchar* stream);


    private:
    patientModel* convertToModel(uchar* stream);
    uchar* convertToStream(patientModel* model);

  };
}