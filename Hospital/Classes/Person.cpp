#include "Person.h"

Person::Person(const std::string& name, const std::string& surname, const std::string& password) {
    this->name = name;
    this->surname = surname;
    this->password = password;
}