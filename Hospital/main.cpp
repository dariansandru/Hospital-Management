#include "./Utilities/ParseFunctions.h"
#include "./UI/Header.h"
#include "Repos/DoctorRepo.h"
#include "Repos/MedicineRepo.h"
#include "Repos/PatientRepo.h"

int main() {
    auto* patientRepo = new PatientRepo();
    auto* doctorRepo = new DoctorRepo();
    auto* medicineRepo = new MedicineRepo();
    auto* header = new Header();

    patientRepo->PatientRepoLoad();
    doctorRepo->DoctorRepoLoad();
    medicineRepo->MedicineRepoLoad();

    parseFunctions.init(doctorRepo, medicineRepo, patientRepo);
    doctorOperations.init(doctorRepo, medicineRepo, patientRepo);
    patientOperations.init(doctorRepo, medicineRepo, patientRepo);
    header->init(doctorRepo, medicineRepo, patientRepo);

    header->showHospitalHeader();
}