cmake_minimum_required(VERSION 3.27)
project(Hospital)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hospital main.cpp
        Classes/Patient.cpp
        Classes/Patient.h
        Classes/Doctor.cpp
        Classes/Doctor.h
        Classes/DateTime.cpp
        Classes/DateTime.h
        Utilities/Global.h
        Utilities/Global.cpp
        Repos/PatientRepo.h
        Repos/PatientRepo.cpp
        Repos/DoctorRepo.h
        Repos/DoctorRepo.cpp
        UI/Header.h
        UI/Header.cpp
        Utilities/StringFunctions.h
        Utilities/StringFunctions.cpp
        Utilities/ParseFunctions.h
        Utilities/ParseFunctions.cpp
        Service/PatientOperations.h
        Service/PatientOperations.cpp
        Service/DoctorOperations.h
        Service/DoctorOperations.cpp
        Service/PersonInfo.h
        Service/PersonInfo.cpp
        Repos/MedicineRepo.h
        Repos/MedicineRepo.cpp
)
