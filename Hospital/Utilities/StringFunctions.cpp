#include "StringFunctions.h"

std::string Split(const std::string& line, char delim, int pos){
    std::string currentLine;
    int currentPos = 0;

    int index = 0;
    while (index != line.size()){

        if (line[index] == delim && line[index - 1] != delim){
            if (currentPos == pos) return currentLine;

            currentLine = "";
            currentPos++;
        }
        else{
            currentLine += line[index];
        }

        index++;
    }

    if (currentPos == pos) return Strip(currentLine, delim);
    return line;
}

std::string Strip(const std::string& line, char delim){
    std::string finalLine;

    int rightPos = line.size() - 1;
    int leftPos = 0;

    int pos = 0;
    while (line[pos] == delim){
        leftPos++;
        pos++;
    }

    pos = line.size() - 1;
    while (line[pos] == delim){
        rightPos--;
        pos--;
    }

    if (leftPos == 0 && rightPos == line.size()) return finalLine;

    while (leftPos != rightPos + 1){
        finalLine += line[leftPos];
        leftPos++;
    }
    return finalLine;
}

std::string Lower(const std::string& line){
    std::string newLine;

    int pos = 0;
    while (line[pos] != '\0'){
        if ('a' <= line[pos] && line[pos] <= 'z') newLine += tolower(line[pos]);
        else newLine += line[pos];

        pos++;
    }

    return newLine;
}

bool birthValidation(std::string& line){
    line = Strip(line, ' ');

    if (line.empty()) return false;
    if (Split(line, '/', 2) == line) return false;

    int pos = 0;
    while (line[pos] != '\0'){
        if (!('0' <= line[pos] && line[pos] <= '9') && line[pos] != '/') return false;
        pos++;
    }

    std::string dd = Split(line, '/', 0);
    if (dd.length() > 2) return false;

    std::string MM = Split(line, '/', 1);
    if (MM.length() > 2) return false;

    std::string yyyy = Split(line, '/', 2);
    if (yyyy.length() != 4) return false;
    if (yyyy[0] == '0') return false;

    return true;
}

bool phoneNumberValidation(const std::string& line){
    if (line.empty()) return false;

    int pos = 0;
    while (line[pos] != '\0'){
        if ('A' <= line[pos] && line[pos] <+ 'z') return false;
        pos++;
    }

    return true;
}

std::string getSpeciality(int choice){
    switch(choice){
        case 1:
            return "Anesthesiology";
            break;
        case 2:
            return "Cardiology";
            break;
        case 3:
            return "Dermatology";
            break;
        case 4:
            return "Gynecology";
            break;
        case 5:
            return "Neurology";
            break;
        case 6:
            return "Ophthalmology";
            break;
        case 7:
            return "Orthopaedic";
            break;
        case 8:
            return "Pathology";
            break;
        case 9:
            return "Rheumatology";
            break;
        case 10:
            return "Urology";
            break;
        default:
            return "NULL";
            break;
    }
}