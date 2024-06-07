#pragma once

#ifndef HOSPITAL_STRINGFUNCTIONS_H
#define HOSPITAL_STRINGFUNCTIONS_H

#include <string>

std::string Split(const std::string& line, char delim, int pos);

std::string Strip(const std::string& line, char delim);

std::string Lower(const std::string& line);

bool phoneNumberValidation(const std::string&);

bool birthValidation(std::string&);

std::string getSpeciality(int choice);

#endif //HOSPITAL_STRINGFUNCTIONS_H