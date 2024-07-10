#include "DoctorRepo.h"

void DoctorRepo::DoctorRepoLoad(){
    if (totalDoctors != 0) return;
    std::ifstream dFin(doctorPath);

    std::string line;
    while (getline(dFin, line)) {
        doctorRepo.push_back(line);
        totalDoctors++;
    }

    dFin.close();
}

void DoctorRepo::DoctorRepoSave(){
    std::ofstream dTrunc(doctorPath, std::ios_base::trunc);
    dTrunc.close();

    std::ofstream dFout(doctorPath, std::ios_base::app);

    int pos = 0;
    while (pos != totalDoctors){
        dFout << doctorRepo[pos] << std::endl;
        pos++;
    }

    dFout.close();
}

void DoctorRepo::DoctorRepoAdd(const std::string& line){
    doctorRepo[totalDoctors] = line;
    totalDoctors++;
    DoctorRepoSave();
}

bool DoctorRepo::DoctorRepoDuplicate(const std::string& line){
    std::ifstream dFin(doctorPath);

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

bool DoctorRepo::DoctorRepoExist(const std::string& line){
    int pos = 0;
    while (pos != totalDoctors){
        std::string account = Split(doctorRepo[pos], ',', 1) + " " + Split(doctorRepo[pos], ',', 2);
        if (account == line) return true;

        pos++;
    }

    return false;
}

std::string DoctorRepo::DoctorRepoPassword(const std::string& line){
    int pos = 0;
    while (pos != totalDoctors){
        std::string account = Split(doctorRepo[pos], ',', 1) + " " + Split(doctorRepo[pos], ',', 2);
        if (account == line) return Split(doctorRepo[pos], ',', 3);

        pos++;
    }

    return line;
}