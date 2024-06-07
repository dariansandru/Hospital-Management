#include "PatientRepo.h"

void PatientRepoLoad(){
    if (totalPatients != 0) return;
    std::ifstream pFin(patientPath);

    std::string line;
    while (getline(pFin, line)) {
        patientRepo[totalPatients] = line;
        totalPatients++;
    }

    pFin.close();
}

void PatientRepoSave(){
    std::ofstream pTrunc(patientPath, std::ios_base::trunc);
    pTrunc.close();

    std::ofstream pFout(patientPath, std::ios_base::app);

    int pos = 0;
    while (pos != totalPatients){
        pFout << patientRepo[pos] << std::endl;
        pos++;
    }

    pFout.close();
}

void PatientRepoAdd(const std::string& line){
    patientRepo[totalPatients] = line;
    totalPatients++;
    PatientRepoSave();
}

void PatientRepoShow(){
    int pos = 0;

    while (pos != totalPatients){
        std::cout << patientRepo[pos] << std::endl;
        pos++;
    }
}

bool PatientRepoDuplicate(const std::string& line){
    std::ifstream dFin(patientPath);

    std::string data;
    while (getline(dFin, data)) {
        std::string account = Split(data, ',', 1) + " " + Split(data, ',', 2);

        if (line == account){
            return true;
        }
    }

    dFin.close();
    return false;
}

bool PatientRepoExist(const std::string& line){
    int pos = 0;
    while (pos != totalPatients){
        std::string account = Split(patientRepo[pos], ',', 1) + " " + Split(patientRepo[pos], ',', 2);
        if (account == line) return true;

        pos++;
    }

    return false;
}

std::string PatientRepoPassword(const std::string& line){
    int pos = 0;
    while (pos != totalPatients){
        std::string account = Split(patientRepo[pos], ',', 1) + " " + Split(patientRepo[pos], ',', 2);
        if (account == line) return Split(patientRepo[pos], ',', 3);

        pos++;
    }

    return line;
}