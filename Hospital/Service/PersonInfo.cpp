#include "PersonInfo.h"

std::string getPatientByID(int id){
    std::ifstream pFin(patientPath);

    std::string data;
    while (getline(pFin, data)) {
        int currentID = stoi(Split(data, ',', 0));

        if (currentID == id){
            return Split(data, ',', 1) + " " + Split(data, ',', 2);
        }
    }

    pFin.close();
    return data; // BAD IDEA
}

std::string getDoctorByID(int id){
    std::ifstream dFin(doctorPath);

    std::string data;
    while (getline(dFin, data)) {
        int currentID = stoi(Split(data, ',', 0));

        if (currentID == id){
            return Split(data, ',', 1) + " " + Split(data, ',', 2);
        }
    }

    dFin.close();
    return data; // BAD IDEA
}

void savePatientFile(const std::string& line){
    std::ofstream pFout(pFilePath, std::ios_base::app);
    pFout << line << std::endl;

    pFout.close();
}

void saveDoctorFile(const std::string& line){
    std::ofstream dFout(dFilePath, std::ios_base::app);
    dFout << line << std::endl;

    dFout.close();
}

void modifyPatientFile(int id, const std::string& line){
    std::ifstream pFin(pFilePath);
    std::string fileRepo[100];

    std::string data;
    int pos = 0;
    while (getline(pFin, data)){
        if (!data.empty()) fileRepo[pos] = data;
        pos++;
    }

    int pos1 = 0;
    while (pos1 != pos){
        if (Split(fileRepo[pos1], ',', 0) == fileRepo[pos1]){
            pos1++;
            continue;
        }
        if (stoi(Split(fileRepo[pos1], ',', 0)) == id){
            fileRepo[pos1] = line;
            break;
        }
        pos1++;
    }

    std::ofstream pTrunc(pFilePath, std::ios_base::trunc);
    pTrunc.close();

    pos1 = 0;
    while (pos1 != pos){
        if (!fileRepo[pos1].empty()) savePatientFile(fileRepo[pos1]);
        pos1++;
    }

}

void modifyDoctorFile(int id, const std::string& line){
    std::ifstream dFin(dFilePath);
    std::string fileRepo[100];

    std::string data;
    int pos = 0;
    while (getline(dFin, data)){
        if (!data.empty()) fileRepo[pos] = data;
        pos++;
    }

    int pos1 = 0;
    while (pos1 != pos){
        if (Split(fileRepo[pos1], ',', 0) == fileRepo[pos1]){
            pos1++;
            continue;
        }
        if (stoi(Split(fileRepo[pos1], ',', 0)) == id){
            fileRepo[pos1] = line;
            break;
        }
        pos1++;
    }

    std::ofstream dTrunc(dFilePath, std::ios_base::trunc);
    dTrunc.close();

    pos1 = 0;
    while (pos1 != pos){
        if (!fileRepo[pos1].empty()) saveDoctorFile(fileRepo[pos1]);
        pos1++;
    }
}

std::string getPatientFile(int id){
    std::ifstream pFin(pFilePath);

    std::string data;
    while (getline(pFin, data)){
        if (Split(data, ',', 0) == data) continue;
        if (stoi(Split(data, ',', 0)) == id) return data;
    }

    return data; // TERRIBLE IDEA
}

std::string getDoctorFile(int id){
    std::ifstream dFin(dFilePath);

    std::string data;
    while (getline(dFin, data)){
        if (Split(data, ',', 0) == data) continue;
        if (stoi(Split(data, ',', 0)) == id) return data;
    }

    return data; // TERRIBLE IDEA
}