#pragma once

#ifndef HOSPITAL_PARSEFUNCTIONS_H
#define HOSPITAL_PARSEFUNCTIONS_H

#include "../Utilities/StringFunctions.h"
#include "../Utilities/Global.h"
#include "../Repos/PatientRepo.h"
#include "../Repos/DoctorRepo.h"
#include "../Service/PersonInfo.h"
#include <iostream>
#include <string>

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

#endif //HOSPITAL_PARSEFUNCTIONS_H