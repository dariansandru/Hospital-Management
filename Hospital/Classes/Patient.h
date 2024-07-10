#pragma once

#ifndef HOSPITAL_PATIENT_H
#define HOSPITAL_PATIENT_H

#include "Doctor.h"
#include "DateTime.h"

class Patient{
public:
    Patient() = default;
    Patient(int, const std::string&, const std::string&, const std::string&);
    Patient(int, const std::string&, const std::string&);

    void showFile();
    void assignData(int, DateTime, const std::string& , const std::string&, const std::string&);
    void assignPassword(const std::string&);

    std::string createLine();
    std::string createFile();
    std::string showAccount();

    int getID() const;
    bool empty() const;
    bool emptyFile() const;

    friend void operator <<(std::ostream&, Patient);
protected:
    int UID;
    std::string password;

    std::string name;
    std::string surname;

    int doctorID;
    DateTime dateOfBirth;
    std::string address;
    std::string phoneNumber;

    std::string symptoms;
};

#endif //HOSPITAL_PATIENT_H