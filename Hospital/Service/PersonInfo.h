#ifndef HOSPITAL_PERSONINFO_H
#define HOSPITAL_PERSONINFO_H

#include <iostream>
#include <fstream>
#include <string>
#include "../Utilities/Global.h"
#include "../Utilities/StringFunctions.h"

std::string getPatientByID(int);

std::string getDoctorByID(int);

void savePatientFile(const std::string&);

void saveDoctorFile(const std::string&);

void modifyPatientFile(int, const std::string&);

void modifyDoctorFile(int, const std::string&);

std::string getPatientFile(int);

std::string getDoctorFile(int);

#endif //HOSPITAL_PERSONINFO_H