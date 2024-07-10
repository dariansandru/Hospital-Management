#ifndef HOSPITAL_PATIENTOPERATIONS_H
#define HOSPITAL_PATIENTOPERATIONS_H

#include <iostream>
#include <string>
#include "../Utilities/ParseFunctions.h"
#include "../Utilities/Global.h"
#include "../Utilities/StringFunctions.h"
#include "../Service/PersonInfo.h"
#include "../Repos/MedicineRepo.h"
#include "../Repos/DoctorRepo.h"
#include "../Repos/PatientRepo.h"

class PatientOperations{
public:
    void init(DoctorRepo* _doctorRepo,
              MedicineRepo* _medicineRepo,
              PatientRepo* _patientRepo) {
        doctorRepo = std::make_unique<class DoctorRepo>(*_doctorRepo);
        medicineRepo = std::make_unique<class MedicineRepo>(*_medicineRepo);
        patientRepo = std::make_unique<class PatientRepo>(*_patientRepo);
    }

    void SeeMedicalFile();

    void FillMedicalFile();

    void pSeeMedicineList();

    void AddDoctorAppointment();

    void CheckDoctorAppointment();

    void showFile(const std::string&);

    PatientOperations() {};

private:
    std::unique_ptr<DoctorRepo> doctorRepo;
    std::unique_ptr<MedicineRepo> medicineRepo;
    std::unique_ptr<PatientRepo> patientRepo;
    std::unique_ptr<ParseFunctions> parse;

};

#endif //HOSPITAL_PATIENTOPERATIONS_H