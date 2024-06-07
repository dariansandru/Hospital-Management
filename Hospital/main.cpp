#include "./Utilities/ParseFunctions.h"
#include "./Repos/MedicineRepo.h"
#include "./UI/Header.h"

int main() {
    PatientRepoLoad();
    DoctorRepoLoad();
    MedicineRepoLoad();

    showHospitalHeader();
}