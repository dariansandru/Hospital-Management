#pragma once
#ifndef HOSPITAL_DOCTOROPERATIONS_H
#define HOSPITAL_DOCTOROPERATIONS_H

#include "../Utilities/Global.h"
#include <string>
#include <iostream>
#include <stack>
#include <memory>
#include "../Utilities/ParseFunctions.h"
#include "../Utilities/StringFunctions.h"
#include "../Repos/MedicineRepo.h"
#include "../Repos/DoctorRepo.h"
#include "../Repos/PatientRepo.h"

class DoctorOperations{
private:
    std::unique_ptr<DoctorRepo> doctorRepo;
    std::unique_ptr<MedicineRepo> medicineRepo;
    std::unique_ptr<PatientRepo> patientRepo;
    std::unique_ptr<class ParseFunctions> parse;

public:
    void init(DoctorRepo* _doctorRepo,
              MedicineRepo* _medicineRepo,
              PatientRepo* _patientRepo) {
        doctorRepo = std::make_unique<class DoctorRepo>(*_doctorRepo);
        medicineRepo = std::make_unique<class MedicineRepo>(*_medicineRepo);
        patientRepo = std::make_unique<class PatientRepo>(*_patientRepo);
    }

    void SeeDoctorFile();

    void FillDoctorFile();

    void SeePatientAppointments();

    void dSeeMedicineList();

    void ModifyMedicineList();

    void FillMedicineFile();

    void makeAppointment(int, DateTime);

    void saveFile(const std::string&);

    bool hasAppointment(const std::string&);

    void showPatientFile(int);

    DoctorOperations() {};
};

#endif //HOSPITAL_DOCTOROPERATIONS_H