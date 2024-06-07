#pragma once

#ifndef HOSPITAL_HEADER_H
#define HOSPITAL_HEADER_H

#include <iostream>
#include "../Utilities/Global.h"
#include "../Utilities/ParseFunctions.h"
#include "../Repos/DoctorRepo.h"
#include "../Repos/PatientRepo.h"

void showHospitalHeader();

void showPatientHeader();

void showDoctorHeader();

void showPatientOptions();

void showDoctorOptions();

#endif //HOSPITAL_HEADER_H