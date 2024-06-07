#include "DateTime.h"

DateTime::DateTime(int dd, int MM, int yyyy) {
    this->dd = dd;
    this->MM = MM;
    this->yyyy = yyyy;
}

void DateTime::showTime(const std::string& format) const {
    if (format == "dd/MM/yyyy") std::cout << this->dd << "/" << this->MM << "/" << this->yyyy;
    else if (format == "MM/dd/yyyy") std::cout << this->MM << "/" << this->dd << "/" << this->yyyy;
    else throw "Unknown format";
}

std::string DateTime::showTime() const {
    return std::to_string(this->dd) + "/" + std::to_string(this->MM) + "/" + std::to_string(this->yyyy);
}