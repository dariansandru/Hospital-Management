#include "DoctorRepo.h"

void DoctorRepoLoad(){
    if (totalDoctors != 0) return;
    std::ifstream dFin(doctorPath);

    std::string line;
    while (getline(dFin, line)) {
        doctorRepo[totalDoctors] = line;
        totalDoctors++;
    }

    dFin.close();
}

void DoctorRepoSave(){
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

void DoctorRepoAdd(const std::string& line){
    doctorRepo[totalDoctors] = line;
    totalDoctors++;
    DoctorRepoSave();
}

void DoctorRepoShow(){
    int pos = 0;

    while (pos != totalDoctors){
        std::cout << doctorRepo[pos];
        pos++;
    }
}

bool DoctorRepoDuplicate(const std::string& line){
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

bool DoctorRepoExist(const std::string& line){
    int pos = 0;
    while (pos != totalDoctors){
        std::string account = Split(doctorRepo[pos], ',', 1) + " " + Split(doctorRepo[pos], ',', 2);
        if (account == line) return true;

        pos++;
    }

    return false;
}

std::string DoctorRepoPassword(const std::string& line){
    int pos = 0;
    while (pos != totalDoctors){
        std::string account = Split(doctorRepo[pos], ',', 1) + " " + Split(doctorRepo[pos], ',', 2);
        if (account == line) return Split(doctorRepo[pos], ',', 3);

        pos++;
    }

    return line;
}