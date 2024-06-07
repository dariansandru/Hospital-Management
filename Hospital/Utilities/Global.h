#pragma once

#ifndef HOSPITAL_GLOBAL_H
#define HOSPITAL_GLOBAL_H

#include <string>
#include "../Classes/Patient.h"
#include "../Classes/Doctor.h"

extern std::string patientPath;
extern std::string doctorPath;
extern std::string pFilePath;
extern std::string dFilePath;
extern std::string medicinePath;
extern std::string doctorPatients;
extern std::string appointmentsPath;

extern std::string doctorRepo[100];
extern std::string patientRepo[100];
extern std::string medicineRepo[100];

extern Doctor loggedDoctor;
extern Patient loggedPatient;

extern int totalDoctors;
extern int totalPatients;
extern int totalMedicine;

extern std::string adminPass;

#endif //HOSPITAL_GLOBAL_H