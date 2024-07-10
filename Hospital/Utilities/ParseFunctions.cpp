#include "ParseFunctions.h"

int ParseFunctions::getID(const std::string& name, const std::string& path){
    std::ifstream dFin(path);

    std::string line;
    while (getline(dFin, line)) {
        std::string account = Split(line, ',', 1) + " " + Split(line, ',', 2);
        if (account == name){
            int ID = stoi(Split(line, ' ', 0));
            return ID;
        }
    }

    dFin.close();
    return -1;
}

bool ParseFunctions::validName(std::string line){
    int pos = 0;
    while (pos != line.size()){
        if (line[pos] == ' '){
            pos++;
            continue;
        }
        if (!('A' <= line[pos] && line[pos] <= 'z')) return false;
        pos++;
    }
    return true;
}

bool ParseFunctions::validPatientLogin(std::string line){
    if (line.empty()) return false;

    line = Strip(line, ' ');
    std::string command = Split(line, ' ', 0);

    if (command != "login" || Split(line, ' ', 3) == adminPass) return false;

    std::string account = Split(line, ' ', 1) + " " + Split(line, ' ', 2);
    if (!validName(account)){
        std::cout << account << " is not a valid name!" << std::endl;
        return false;
    }

    if (!this->patientRepo->PatientRepoExist(account)){
        std::cout << "This account does not exist!" << std::endl;
        return false;
    }

    if (passwordValidation(account)) {
        loggedPatient = {getID(account, patientPath), Split(account, ' ', 0),
                         Split(account, ' ', 1), this->patientRepo->PatientRepoPassword(account)};
        patientFileAssign(getID(account, patientPath));
        return true;
    }

    return false;
}

bool ParseFunctions::validPatientRegister(std::string line){
    if (line.empty()) return false;

    line = Strip(line, ' ');
    std::string command = Split(line, ' ', 0);

    if (command != "register" || Split(line, ' ', 3) == adminPass) return false;

    std::string account = Split(line, ' ', 1) + " " + Split(line, ' ', 2);
    if (!validName(account)) {
        std::cout << account << " is not a valid name!" << std::endl;
        return false;
    }
    if (!this->patientRepo->PatientRepoDuplicate(account)){
        std::string password = createPassword();
        loggedPatient = {totalPatients + 1, Split(account,  ' ', 0), Split(account, ' ', 1), password};
        this->patientRepo->PatientRepoAdd(loggedPatient.createLine());

        return true;
    }
    else{
        std::cout << "This account already exists!" << std::endl;
        return false;
    }

}

bool ParseFunctions::validDoctorLogin(std::string line){
    if (line.empty()) return false;

    line = Strip(line, ' ');
    std::string command = Split(line, ' ', 0);

    if (command != "login" || Split(line, ' ', 3) != adminPass) return false;

    std::string account = Split(line, ' ', 1) + " " + Split(line, ' ', 2);
    if (!validName(account)){
        std::cout << account << " is not a valid name!" << std::endl;
        return false;
    }

    if (!this->doctorRepo->DoctorRepoExist(account)){
        std::cout << "This account does not exist!" << std::endl;
        return false;
    }

    if (passwordValidation(account)) {
        loggedDoctor = {getID(account, doctorPath), Split(account, ' ', 0),
                         Split(account, ' ', 1), this->doctorRepo->DoctorRepoPassword(account)};
        doctorFileAssign(getID(account, doctorPath));
        return true;
    }

    return false;
}

bool ParseFunctions::validDoctorRegister(std::string line){
    if (line.empty()) return false;

    line = Strip(line, ' ');
    std::string command = Split(line, ' ', 0);

    if (command != "register" || Split(line, ' ', 3) != adminPass) return false;
    std::string account = Split(line, ' ', 1) + " " + Split(line, ' ', 2);

    if (!validName(account)){
        std::cout << account << "is not a valid name!" << std::endl;
        return false;
    }
    if (!this->doctorRepo->DoctorRepoDuplicate(account)) {
        std::string password = createPassword();
        loggedDoctor = {totalDoctors + 1, Split(account,  ' ', 0), Split(account, ' ', 1), password};
        this->doctorRepo->DoctorRepoAdd(loggedDoctor.createLine());

        return true;
    }
    else{
        std::cout << "This account already exists!" << std::endl;
        return false;
    }

}

bool ParseFunctions::validCommand(std::string line){
    line = Strip(line, ' ');
    std::string commandLine = Split(line, ' ', 0);

    if (commandLine == "login" || commandLine == "register") return true;
    return false;
}

std::string ParseFunctions::createPassword(){
    std::cout << "Please input a password for you account!" << std::endl;
    std::string newPassword;  std::getline(std::cin, newPassword);

    while (newPassword.empty()){
        std::cout << "Please input a password for your account!" << std::endl;
        std::getline(std::cin, newPassword);
    }

    return newPassword;
}

bool ParseFunctions::passwordValidation(const std::string& account){
    std::cout << "Please enter your password:" << std::endl;
    std::string password; std::getline(std::cin, password);

    if (this->patientRepo->PatientRepoPassword(account) == password || this->doctorRepo->DoctorRepoPassword(account) == password) return true;

    std::cout << "The password you entered is incorrect!" << std::endl;
    return false;
}

void ParseFunctions::patientFileAssign(int id){
    std::ifstream pFin(pFilePath);

    std::string data;
    while (getline(pFin, data)){
        if (stoi(Split(data, ',', 0)) == id){
            int doctorID = stoi(Split(data, ',', 1));

            std::string dob = Split(data, ',', 2);
            int dd = stoi(Split(dob, '/', 0));
            int MM = stoi(Split(dob, '/', 1));
            int yyyy = stoi(Split(dob, '/', 2));
            DateTime dateOfBirth = {dd, MM, yyyy};

            std::string address = Split(data, ',', 3);
            std::string phoneNumber = Split(data, ',', 4);
            std::string symptoms = Split(data, ',', 5);

            loggedPatient.assignData(doctorID, dateOfBirth, address, phoneNumber, symptoms);
        }
    }
}

void ParseFunctions::doctorFileAssign(int id){
    std::ifstream dFin(dFilePath);

    std::string data;
    while (getline(dFin, data)){
        if (stoi(Split(data, ',', 0)) == id){

            std::string dob = Split(data, ',', 1);
            int dd = stoi(Split(dob, '/', 0));
            int MM = stoi(Split(dob, '/', 1));
            int yyyy = stoi(Split(dob, '/', 2));
            DateTime dateOfBirth = {dd, MM, yyyy};

            std::string address = Split(data, ',', 2);
            std::string phoneNumber = Split(data, ',', 3);
            std::string speciality = Split(data, ',', 4);

            loggedDoctor.assignData(dateOfBirth, address, phoneNumber, speciality);
        }
    }
}