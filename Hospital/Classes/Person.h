#pragma once

#ifndef HOSPITAL_PERSON_H
#define HOSPITAL_PERSON_H

#include <iostream>
#include <string>
#include "Patient.h"
#include "Doctor.h"

class Person {
public:
    Person() = default;
    Person(const std::string&, const std::string&, const std::string&);

protected:
    std::string name;
    std::string surname;
    std::string password;
};

#endif //HOSPITAL_PERSON_H