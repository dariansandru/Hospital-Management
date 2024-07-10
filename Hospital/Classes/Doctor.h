#pragma once

#ifndef HOSPITAL_DOCTOR_H
#define HOSPITAL_DOCTOR_H

#include <string>
#include <iostream>
#include <vector>
#include "../Classes/DateTime.h"

class Doctor{
public:
    Doctor() = default;
    Doctor(int, const std::string&, const std::string&, const std::string&);
    void assignData(DateTime, const std::string&, const std::string&, const std::string&);

    void showFile();

    int getID() const;
    void assignPatient(int);

    std::string createLine();
    std::string createFile();
    std::string showAccount();

    bool empty() const;
    bool emptyFile() const;

    friend void operator <<(std::ostream&, Doctor);

protected:
    int UID;
    std::string password;

    std::string name;
    std::string surname;
    std::string speciality;

    std::string phoneNumber;
    std::string address;
    DateTime dateOfBirth;

    std::vector<int> patients;
    int totalPatients = 0;
};

#endif //HOSPITAL_DOCTOR_H