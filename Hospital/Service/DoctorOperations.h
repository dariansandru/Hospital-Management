#pragma once
#ifndef HOSPITAL_DOCTOROPERATIONS_H
#define HOSPITAL_DOCTOROPERATIONS_H

#include "../Utilities/Global.h"
#include <string>
#include <iostream>
#include <stack>
#include "../Utilities/ParseFunctions.h"
#include "../Utilities/StringFunctions.h"
#include "../Classes/Stack.h"
#include "../Repos/MedicineRepo.h"

void SeeDoctorFile();

void FillDoctorFile();

void SeePatientAppointments();

void dSeeMedicineList();

void ModifyMedicineList();

void FillMedicineFile();

std::string getSpeciality(int);

void makeAppointment(int, DateTime);

void saveFile(const std::string&);

bool hasAppointment(const std::string&);

void showPatientFile(int);

#endif //HOSPITAL_DOCTOROPERATIONS_H