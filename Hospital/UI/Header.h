#pragma once

#ifndef HOSPITAL_HEADER_H
#define HOSPITAL_HEADER_H

#include <iostream>
#include "../Utilities/Global.h"
#include "../Utilities/ParseFunctions.h"
#include "../Repos/DoctorRepo.h"
#include "../Repos/PatientRepo.h"

class Header{
private:
    std::unique_ptr<DoctorRepo> doctorRepo;
    std::unique_ptr<MedicineRepo> medicineRepo;
    std::unique_ptr<PatientRepo> patientRepo;
public:
    void init(DoctorRepo* _doctorRepo,
              MedicineRepo* _medicineRepo,
              PatientRepo* _patientRepo) {
        doctorRepo = std::make_unique<class DoctorRepo>(*_doctorRepo);
        medicineRepo = std::make_unique<class MedicineRepo>(*_medicineRepo);
        patientRepo = std::make_unique<class PatientRepo>(*_patientRepo);
    }

    void showHospitalHeader();

    void showPatientHeader();

    void showDoctorHeader();

    void showPatientOptions();

    void showDoctorOptions();
};

#endif //HOSPITAL_HEADER_H