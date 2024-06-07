#pragma once

#ifndef HOSPITAL_DATETIME_H
#define HOSPITAL_DATETIME_H

#include <iostream>
#include <string>

class DateTime {
public:
    DateTime() = default;
    DateTime(int, int, int);

    void showTime(const std::string&) const;
    std::string showTime() const;
protected:
    int dd;
    int MM;
    int yyyy;
};


#endif //HOSPITAL_DATETIME_H