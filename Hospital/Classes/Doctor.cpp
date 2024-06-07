#include "Doctor.h"

Doctor::Doctor(int UID, const std::string &name, const std::string &surname, const std::string &password) {
    this->UID = UID;
    this->password = password;

    this->name = name;
    this->surname = surname;
}

int Doctor::getID() const {
    return this->UID;
}

void Doctor::assignPatient(int patientID) {
    this->patients[this->totalPatients] = patientID;
    totalPatients++;
}

std::string Doctor::createLine() {
    return std::to_string(this->UID) + "," + this->name + "," + this->surname + "," + this->password;
}

std::string Doctor::createFile() {
    return std::to_string(this->UID) + "," + this->dateOfBirth.showTime() + "," + this->address + "," +
           this->phoneNumber + "," + this->speciality;
}

bool Doctor::empty() const{
    if (this->name.empty() && this->surname.empty()) return true;
    return false;
}

std::string Doctor::showAccount() {
    return this->name + " " + this->surname;
}

void Doctor::showFile() {
    if (this->speciality.empty() || this->address.empty()){
        std::cout << "You have not filed your file yet!" << std::endl << std::endl;
        return;
    }

    std::cout << "Doctor File:" << std::endl << std::endl;

    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Surname: " << this->surname << std::endl;
    std::cout << "Speciality: " << this->speciality << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;

    std::cout << "Address: " << this->address << std::endl;
    std::cout << "Date of Birth: ";
    this->dateOfBirth.showTime("dd/MM/yyyy");
    std:: cout << std::endl;
}

bool Doctor::emptyFile() const {
    if (this->address.empty() && this->phoneNumber.empty()) return true;
    return false;
}

void Doctor::assignData(DateTime _dateOfBirth, const std::string &_address, const std::string &_phoneNumber,
                        const std::string &_speciality) {
    this->dateOfBirth = _dateOfBirth;
    this->address = _address;
    this->phoneNumber = _phoneNumber;
    this->speciality = _speciality;
}

void operator<<(std::ostream &o, Doctor doctor) {
    o << "Welcome " << doctor.showAccount() << "! We hope your time here will be productive!" << std::endl;
}