#pragma once

#ifndef HOSPITAL_MEDICINEREPO_H
#define HOSPITAL_MEDICINEREPO_H

#include <iostream>
#include <string>
#include "../Utilities/Global.h"
#include "../Utilities/StringFunctions.h"
#include <fstream>

class MedicineRepo{
private:
    std::vector<std::string> medicineRepo;
public:
    void MedicineRepoLoad();

    void MedicineRepoSave();

    void MedicineRepoAdd(const std::string&);

    void MedicineRepoRemove(const std::string&);

    void MedicineRepoModify(const std::string&, const std::string&);

    int getQuantity(const std::string&);

    bool MedicineRepoExist(const std::string&);

};

#endif //HOSPITAL_MEDICINEREPO_H