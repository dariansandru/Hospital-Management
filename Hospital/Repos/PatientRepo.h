#pragma once

#ifndef HOSPITAL_PATIENTREPO_H
#define HOSPITAL_PATIENTREPO_H

#include "../Utilities/Global.h"
#include "../Utilities/StringFunctions.h"
#include <fstream>
#include <iostream>

void PatientRepoLoad();

void PatientRepoSave();

void PatientRepoAdd(const std::string&);

void PatientRepoShow();

bool PatientRepoDuplicate(const std::string&);

bool PatientRepoExist(const std::string&);

std::string PatientRepoPassword(const std::string&);

#endif //HOSPITAL_PATIENTREPO_H