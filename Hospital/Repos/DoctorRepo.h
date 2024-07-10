#pragma once

#ifndef HOSPITAL_DOCTORREPO_H
#define HOSPITAL_DOCTORREPO_H

#include "../Utilities/Global.h"
#include "../Utilities/StringFunctions.h"
#include <fstream>
#include <iostream>

class DoctorRepo {
private:
    std::vector<std::string> doctorRepo;
public:
    void DoctorRepoLoad();

    void DoctorRepoSave();

    void DoctorRepoAdd(const std::string&);

    bool DoctorRepoDuplicate(const std::string&);

    bool DoctorRepoExist(const std::string&);

    std::string DoctorRepoPassword(const std::string&);

};

#endif //HOSPITAL_DOCTORREPO_H