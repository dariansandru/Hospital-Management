#pragma once

#ifndef HOSPITAL_PATIENTREPO_H
#define HOSPITAL_PATIENTREPO_H

#include "../Utilities/Global.h"
#include "../Utilities/StringFunctions.h"
#include <fstream>
#include <iostream>

class PatientRepo{
private:
    std::vector<std::string> patientRepo;
public:
    void PatientRepoLoad();

    void PatientRepoSave();

    void PatientRepoAdd(const std::string&);

    bool PatientRepoDuplicate(const std::string&);

    bool PatientRepoExist(const std::string&);

    std::string PatientRepoPassword(const std::string&);

};

#endif //HOSPITAL_PATIENTREPO_H