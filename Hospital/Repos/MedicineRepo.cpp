#include "MedicineRepo.h"

void MedicineRepo::MedicineRepo::MedicineRepoLoad(){
    std::ifstream mFin(medicinePath);
    std::string data;

    while (getline(mFin, data)){
        medicineRepo.push_back(data);
        totalMedicine++;
    }
}

void MedicineRepo::MedicineRepoSave(){
    std::ofstream mTrunc(medicinePath, std::ios_base::trunc);
    mTrunc.close();

    std::ofstream mFout(medicinePath, std::ios_base::app);
    for ( int i = 0 ; i < totalMedicine ; i++ ){
        mFout << medicineRepo[i] << std::endl;
    }

    mFout.close();
}

void MedicineRepo::MedicineRepoAdd(const std::string& line){
    medicineRepo[totalMedicine] = line;
    totalMedicine++;
    MedicineRepoSave();
}

void MedicineRepo::MedicineRepoRemove(const std::string& line){
    bool found = false;
    std::ifstream mFin(medicinePath);
    int newTotal = 0;

    std::string data;
    while (getline(mFin, data)){
        if (data != line){
            medicineRepo[newTotal] = data;
            found = true;
        }
        newTotal++;
    }
    mFin.close();
    if (found) totalMedicine--;

    MedicineRepoSave();
}

void MedicineRepo::MedicineRepoModify(const std::string& medicine, const std::string& quantity){
    std::ifstream fin(medicinePath);
    std::string data;

    int pos = 0;
    while (pos != totalMedicine){
        if (Split(medicineRepo[pos], ',', 0) == medicine){
            std::string newMedicine = medicine + "," + quantity;
            medicineRepo[pos] = newMedicine;
            MedicineRepoSave();
            return;
        }
        pos++;
    }
}

int MedicineRepo::getQuantity(const std::string& medicine){
    std::ifstream fin(medicinePath);
    std::string data;

    while(getline(fin, data)){
        if (Split(data, ',',0) == medicine) return stoi(Split(data, ',', 1));
    }
    return -1;
}

bool MedicineRepo::MedicineRepoExist(const std::string& medicine){
    std::ifstream fin(medicinePath);
    std::string data;

    while(getline(fin, data)){
        if (Split(data, ',',0) == medicine) return true;
    }
    return false;
}