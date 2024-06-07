#include "Header.h"
#include "../Service/DoctorOperations.h"
#include "../Service/PatientOperations.h"

void showHospitalHeader(){
    std::cout << "--------Welcome to Mercy Hospital--------" << std::endl;
    std::cout << "We are here to tend to all of your needs!" << std::endl << std::endl;

    std::cout << "If you would like to login, please enter:" << std::endl;
    std::cout << "login [NAME] [SURNAME] if you are a patient" << std::endl;
    std::cout << "login [NAME] [SURNAME] [ADMINPASS] if you are a doctor" << std::endl << std::endl;

    std::cout << "If you would like to register, please enter:" << std::endl;
    std::cout << "register [NAME] [SURNAME] if you are a patient" << std::endl;
    std::cout << "register [NAME] [SURNAME] [ADMINPASS] if you are a doctor" << std::endl << std::endl;

    std::string commandLine; std::getline(std::cin, commandLine);

    while (true){
        if (validPatientRegister(commandLine) || validDoctorRegister(commandLine)){
            std::cout << "You have registered successfully!" << std::endl << std::endl;
            if (!loggedPatient.empty()) showPatientHeader();
            else showDoctorHeader();

            break;
        }
        else if (validPatientLogin(commandLine) || validDoctorLogin(commandLine)){
            std::cout << "You have logged in successfully!" << std::endl << std::endl;
            if (!loggedPatient.empty()) showPatientHeader();
            else showDoctorHeader();

            break;
        }

        if (!validCommand(commandLine)) std::cout << "Command could not be found!" << std::endl;

        std::cout << "If you would like to try again, please use one of the commands from above:" << std::endl;
        std::getline(std::cin, commandLine);
    }
}

void showPatientHeader(){
    std::cout << loggedPatient;
    showPatientOptions();

    std::string choice; getline(std::cin, choice);
    choice = Lower(choice);
    choice = Strip(choice,  ' ');
    do{
        if (choice == "1" || choice == "fill medical file") FillMedicalFile();
        else if (choice == "2" || choice == "see medical file") SeeMedicalFile();
        else if (choice == "3" || choice == "see medicine list") pSeeMedicineList();
        else if (choice == "4" || choice == "add doctor appointment") AddDoctorAppointment();
        else if (choice == "5" || choice == "check doctor appointment") CheckDoctorAppointment();
        else if (!choice.empty()) std::cout << "Command could not be found, please select one from below!" << std::endl;

        if (!choice.empty()) showPatientOptions();
        getline(std::cin, choice);
    }while(choice != "6" && choice != "exit");

    std::cout << "We hope you had a good time! Please be safe " + loggedPatient.showAccount() + "!";
}

void showDoctorHeader(){
    std::cout << loggedDoctor;
    showDoctorOptions();

    std::string choice; getline(std::cin, choice);
    choice = Lower(choice);
    choice = Strip(choice, ' ');
    do{
        if (choice == "1" || choice == "see doctor file") SeeDoctorFile();
        else if (choice == "2" || choice == "fill doctor file") FillDoctorFile();
        else if (choice == "3" || choice == "see patient appointments") SeePatientAppointments();
        else if (choice == "4" || choice == "fill medicine file") FillMedicineFile();
        else if (choice == "5" || choice == "modify medicine list") ModifyMedicineList();
        else if (choice == "6" || choice == "see medicine list") dSeeMedicineList();
        else if (!choice.empty()) std::cout << "Command could not be found, please select one from below!" << std::endl;

        if (!choice.empty()) showDoctorOptions();
        getline(std::cin, choice);
    }while(choice != "7" && choice != "exit");

    std::cout << "We hope you had a productive time! Please stay safe " + loggedDoctor.showAccount() + "!";
}

void showPatientOptions(){
    std::cout << "Please select the feature you would like to access from the list below!" << std::endl;
    std::cout << "1. Fill Medical File            2. See Medical File" << std::endl;
    std::cout << "3. See Medicine List            4. Add Doctor Appointment" << std::endl;
    std::cout << "5. Check Doctor Appointment     6. Exit" << std::endl;
}

void showDoctorOptions(){
    std::cout << "Please select the feature you would like to access from the list below!" << std::endl;
    std::cout << "1. See Doctor File             2. Fill Doctor File" << std::endl;
    std::cout << "3. See Patient Appointments    4. Fill Medicine File" << std::endl;
    std::cout << "5. Modify Medicine List        6. See Medicine List" << std::endl;
    std::cout << "7. Exit" << std::endl;
}