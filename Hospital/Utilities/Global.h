#pragma once

#ifndef HOSPITAL_GLOBAL_H
#define HOSPITAL_GLOBAL_H

#include <string>
#include <vector>
#include "../Classes/Patient.h"
#include "../Classes/Doctor.h"
#include "../Service/DoctorOperations.h"
#include "../Service/PatientOperations.h"
#include "ParseFunctions.h"

extern std::string patientPath;
extern std::string doctorPath;
extern std::string pFilePath;
extern std::string dFilePath;
extern std::string medicinePath;
extern std::string doctorPatients;
extern std::string appointmentsPath;

extern Doctor loggedDoctor;
extern Patient loggedPatient;

extern int totalDoctors;
extern int totalPatients;
extern int totalMedicine;

extern class DoctorOperations doctorOperations;
extern class PatientOperations patientOperations;
extern class ParseFunctions parseFunctions;

extern std::string adminPass;

#endif //HOSPITAL_GLOBAL_H