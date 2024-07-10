#include "Patient.h"

Patient::Patient(int ID, const std::string& name, const std::string& surname, const std::string& password) {
    this->UID = ID;
    this->name = name;
    this->surname = surname;
    this->password = password;
}

void Patient::showFile() {

    if (this->symptoms.empty() || this->address.empty()){
        std::cout << "You have not filed your file yet!" << std::endl << std::endl;
        return;
    }

    std::cout << "Patient File:" << std::endl << std::endl;

    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Surname: " << this->surname << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;

    std::cout << "Address: " << this->address << std::endl;
    std::cout << "Date of Birth: ";
    this->dateOfBirth.showTime("dd/MM/yyyy");
    std:: cout << std::endl;

    std::cout << "Symptoms: " << std::endl << this->symptoms << std::endl << std::endl;
}

void Patient::assignData(int _doctorID, DateTime _dateOfBirth, const std::string& _address, const std::string& _phoneNumber,
                         const std::string& _symptoms) {
    this->doctorID = _doctorID;
    this->dateOfBirth = _dateOfBirth;
    this->address = _address;
    this->phoneNumber = _phoneNumber;
    this->symptoms = _symptoms;
}

int Patient::getID() const {
    return this->UID;
}

Patient::Patient(int id, const std::string &name, const std::string &surname) {
    this->UID = id;
    this->name = name;
    this->surname = surname;
}

void Patient::assignPassword(const std::string& _password){
    this->password = _password;
}

std::string Patient::createLine() {
    return std::to_string(this->UID) + "," + this->name + "," + this->surname + "," + this->password;
}

bool Patient::empty() const{
    if (this->name.empty() && this->surname.empty()) return true;
    return false;
}

std::string Patient::showAccount() {
    return this->name + " " + this->surname;
}

bool Patient::emptyFile() const {
    if (this->address.empty() && this->phoneNumber.empty()) return true;
    return false;
}

std::string Patient::createFile(){
    return std::to_string(this->UID) + "," + std::to_string(this->doctorID) + "," + this->dateOfBirth.showTime() + "," + this->address + "," +
            this->phoneNumber + "," + this->symptoms;
}

void operator<<(std::ostream &o, Patient patient) {
    o << "Welcome " << patient.showAccount() << "! We hope your time here will be good!" << std::endl;
}