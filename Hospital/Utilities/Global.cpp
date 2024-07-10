#include "Global.h"

int totalDoctors = 0;
int totalPatients = 0;
int totalMedicine = 0;

std::string patientPath = "./Files/Patients.txt";
std::string doctorPath = "./Files/Doctors.txt";
std::string pFilePath = "./Files/PatientFile.txt";
std::string dFilePath = "./files/DoctorFile.txt";
std::string medicinePath = "./files/Medicine.txt";
std::string doctorPatients = "./files/DoctorPatients.txt";
std::string appointmentsPath = "./files/Appointments.txt";

DoctorOperations doctorOperations = DoctorOperations();
PatientOperations patientOperations = PatientOperations();
ParseFunctions parseFunctions = ParseFunctions();

Doctor loggedDoctor;
Patient loggedPatient;

std::string adminPass = "abc";