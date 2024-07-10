#include "PatientOperations.h"

void PatientOperations::FillMedicalFile(){
    bool change = false;

    if (!loggedPatient.emptyFile()) {
        std::cout << "You have already filled out your Medical File, would you like to modify it?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;

        std::string choice; getline(std::cin, choice);
        choice = Lower(choice);
        while (choice != "1" && choice != "2" && choice != "yes" && choice != "no"){
            std::cout << "Please enter a valid choice!" << std::endl;
            getline(std::cin, choice);
        }

        if (choice == "2" || choice == "no"){
            std::cout << "Your file has not been modified!" << std::endl;
            return;
        }
        else change = true;
    }

    std::cout << "In order to fill your Medical File, please fill out the following fields:" << std::endl;
    std::cout << "Address: ";
    std::string address; getline(std::cin, address);

    while (address.empty()){
        std::cout << "Please input an address!" << std::endl;
        getline(std::cin, address);
    }

    std::cout << "Date of Birth (dd/MM/yyyy): ";
    std::string dateOfBirth; getline(std::cin, dateOfBirth);

    while (!birthValidation(dateOfBirth)){
        std::cout << "Please input a valid date of birth!" << std::endl;
        getline(std::cin, dateOfBirth);
    }

    std::string dd = Split(dateOfBirth, '/', 0);
    std::string MM = Split(dateOfBirth, '/', 1);
    std::string yyyy = Split(dateOfBirth, '/', 2);

    if (dd[0] == '0') dd = dd[1];
    if (MM[0] == '0') MM = MM[1];
    DateTime birth = {stoi(dd), stoi(MM), stoi(yyyy)};

    std::cout << "Phone Number: ";
    std::string phoneNUmber; getline(std::cin, phoneNUmber);

    while (!phoneNumberValidation(phoneNUmber)){
        std::cout << "Please enter a valid phone number!" << std::endl;
        getline(std::cin, phoneNUmber);
    }

    std::cout << "Please describe your symptoms: " << std::endl;
    std::string symptoms; getline(std::cin, symptoms);

    // doctorID 1 is placeholder and is not needed anymore !!
    // Be careful when fetching data from PatientFile
    loggedPatient.assignData(1, birth, address, phoneNUmber, symptoms);

    if (change) {
        modifyPatientFile(loggedPatient.getID(), loggedPatient.createFile());
        std::cout << "You have modified your file successfully!" << std::endl << std::endl;
    }
    else {
        savePatientFile(loggedPatient.createFile());
        std::cout << "You have saved your file successfully!" << std::endl << std::endl;
    }
}

void PatientOperations::SeeMedicalFile(){
    loggedPatient.showFile();
}

void PatientOperations::pSeeMedicineList(){
    std::cout << "Medicine List:" << std::endl;
    std::ifstream fin(medicinePath);

    std::string data;
    while (getline(fin, data)){
        std::cout << Split(data, ',', 0);
        if (stoi(Split(data, ',', 1)) != 0) std::cout << " - Available";
        else std::cout << " - Unavailable";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PatientOperations::AddDoctorAppointment(){
    std::cout << "Which speciality should your doctor be?" << std::endl;

    std::cout << "1. Anesthesiology" << std::endl;
    std::cout << "2. Cardiology" << std::endl;
    std::cout << "3. Dermatology" << std::endl;
    std::cout << "4. Gynecology" << std::endl;
    std::cout << "5. Neurology" << std::endl;
    std::cout << "6. Ophthalmology" << std::endl;
    std::cout << "7. Orthopaedic" << std::endl;
    std::cout << "8. Pathology" << std::endl;
    std::cout << "9. Rheumatology" << std::endl;
    std::cout << "10. Urology" << std::endl;

    int choice; std::cin >> choice;
    while (0 > choice || choice > 10){
        std::cout << "Please select a valid choice" << std::endl;
        std::cin >> choice;
    }

    std::cout << "Please select which doctor you would like to make an appointment with:" << std::endl;
    std::ifstream dFin(dFilePath);
    std::string data;

    int pos = 1;
    std::string doctors[100];

    while(getline(dFin, data)){
        std::string speciality = Split(data, ',', 4);
        if (speciality == getSpeciality(choice)){
            doctors[pos] = getDoctorByID(stoi(Split(data, ',', 0)));
            pos++;
        }
    }
    dFin.close();

    int pos1 = 1;
    while (pos1 != pos){
        std::cout << pos1 << ". " << doctors[pos1] << std::endl;
        pos1++;
    }

    std::cin >> choice;
    while (choice < 0 || choice >= pos){
        std::cout << "Please select a valid doctor!" << std::endl;
        std::cin >> choice;
    }
    std::string line = std::to_string(this->parse->getID(doctors[choice], doctorPath)) + "," +
            std::to_string(loggedPatient.getID());

    std::ofstream aFout(appointmentsPath, std::ios_base::app);
    aFout << line << std::endl;

    std::cout << "Your appointment request has been sent to Dr. " + doctors[choice] + "!" +
    " You will be notified with the date of your appointment!";
    std::cout << std::endl << std::endl;
}

void PatientOperations::CheckDoctorAppointment(){
    bool found = false;
    
    std::ifstream aFin(appointmentsPath);
    std::string data;

    while (getline(aFin, data)){
        int doctorID = stoi(Split(data, ',', 0));
        int patientID = stoi(Split(data, ',', 1));

        if (loggedPatient.getID() == patientID){
            if (!found){
                std::cout << "Current Appointments:" << std::endl;
                found = true;
            }

            if (Split(data, ',', 2) == data)
                std::cout << getDoctorByID(doctorID) + " - Not appointed";
            else std::cout << getDoctorByID(doctorID) + " - Appointed at " + Split(data, ',', 2);
            std::cout << std::endl;
        }
    }
    aFin.close();
    std::cout << std::endl;

    std::ifstream fin(doctorPatients);

    while (getline(fin, data)){
        int doctorID = stoi(Split(data, ',', 0));
        int patientID = stoi(Split(data, ',', 1));

        if (loggedPatient.getID() == patientID) showFile(data);
    }
}

void PatientOperations::showFile(const std::string& file){
    int doctorID = stoi(Split(file, ',', 0));
    int patientID = stoi(Split(file, ',', 1));
    std::string date = Split(file, ',', 2);
    std::string diagnosis = Split(file, ',', 3);
    std::string prescription = Split(file, ',', 4);

    std::cout << "Medical File:" << std::endl;
    std::cout << "Doctor: " << getDoctorByID(doctorID) << std::endl;
    std::cout << "Patient: " << getPatientByID(patientID) << std::endl << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Diagnosis: " << diagnosis << std::endl;
    std::cout << "Prescription: " << prescription << std::endl;
    std::cout << std::endl;
}