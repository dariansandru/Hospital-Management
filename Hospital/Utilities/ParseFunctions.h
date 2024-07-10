#pragma once

#ifndef HOSPITAL_PARSEFUNCTIONS_H
#define HOSPITAL_PARSEFUNCTIONS_H

#include "../Utilities/StringFunctions.h"
#include "../Utilities/Global.h"
#include "../Repos/PatientRepo.h"
#include "../Repos/MedicineRepo.h"
#include "../Repos/DoctorRepo.h"
#include "../Service/PersonInfo.h"
#include <iostream>
#include <string>

class ParseFunctions{
private:
    std::unique_ptr<class DoctorRepo> doctorRepo;
    std::unique_ptr<class MedicineRepo> medicineRepo;
    std::unique_ptr<class PatientRepo> patientRepo;
public:
    void init(DoctorRepo* _doctorRepo,
              MedicineRepo* _medicineRepo,
              PatientRepo* _patientRepo) {
        doctorRepo = std::make_unique<class DoctorRepo>(*_doctorRepo);
        medicineRepo = std::make_unique<class MedicineRepo>(*_medicineRepo);
        patientRepo = std::make_unique<class PatientRepo>(*_patientRepo);
    }

    ParseFunctions() {}
    ParseFunctions(ParseFunctions& other){};

    int getID(const std::string&, const std::string&);

    bool validName(std::string);

    bool validPatientLogin(std::string);

    bool validPatientRegister(std::string);

    bool validDoctorLogin(std::string);

    bool validDoctorRegister(std::string);

    bool validCommand(std::string);

    std::string createPassword();

    bool passwordValidation(const std::string&);

    void patientFileAssign(int id);

    void doctorFileAssign(int id);
};


#endif //HOSPITAL_PARSEFUNCTIONS_H