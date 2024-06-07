#ifndef HOSPITAL_PATIENTOPERATIONS_H
#define HOSPITAL_PATIENTOPERATIONS_H

#include <iostream>
#include <string>
#include "../Utilities/ParseFunctions.h"
#include "../Utilities/Global.h"
#include "../Utilities/StringFunctions.h"
#include "../Service/PersonInfo.h"

void SeeMedicalFile();

void FillMedicalFile();

void pSeeMedicineList();

void AddDoctorAppointment();

void CheckDoctorAppointment();

void showFile(const std::string&);

#endif //HOSPITAL_PATIENTOPERATIONS_H