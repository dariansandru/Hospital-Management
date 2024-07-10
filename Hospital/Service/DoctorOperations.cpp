#include "DoctorOperations.h"

void DoctorOperations::SeeDoctorFile(){
    loggedDoctor.showFile();
    std::cout << std::endl;
}

void DoctorOperations::FillDoctorFile(){
    bool change = false;

    if (!loggedDoctor.emptyFile()) {
        std::cout << "You have already filled out your Doctor File, would you like to modify it?" << std::endl;
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
    phoneNUmber = Strip(phoneNUmber, ' ');

    std::cout << "Please select the field you specialise in:" << std::endl;
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
    while (choice < 0 || choice > 10){
        std::cout << "Please select a correct field!" << std::endl;
        std::cin >> choice;
    }

    loggedDoctor.assignData(birth, address, phoneNUmber, getSpeciality(choice));

    if (change) {
        modifyDoctorFile(loggedDoctor.getID(), loggedDoctor.createFile());
        std::cout << "You have modified your file successfully!" << std::endl << std::endl;
    }
    else {
        saveDoctorFile(loggedDoctor.createFile());
        std::cout << "You have saved your file successfully!" << std::endl << std::endl;
    }
}

void DoctorOperations::SeePatientAppointments(){
    bool found = false;

    int patientNumber = 1;
    std::string patients[100];
    std::ifstream aFin(appointmentsPath);

    std::string data;
    while (getline(aFin, data)){
        int doctorID = stoi(Split(data, ',', 0));
        int patientID = stoi(Split(data, ',', 1));

        if (loggedDoctor.getID() == doctorID){
            if (!found){
                std::cout << "Requesting Patients:" << std::endl;
                found = true;
            }
            patients[patientNumber] = getPatientByID(patientID);
            std::cout << patientNumber << ". " << getPatientByID(patientID);
            patientNumber++;

            if (Split(data, ',', 2) == data){
                std:: cout << " - Not appointed";
            }
            else std::cout << " - Appointed at " << Split(data, ',', 2);
            std::cout << std::endl;
        }
    }

    if (!found){
        std::cout << "There are no requesting patients!" << std::endl;
        return;
    }
    std::cout << std::endl;

    std::cout << "Would you like to confirm or change an appointment?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int choice; std::cin >> choice;
    while (choice != 1 && choice != 2){
        std::cout << "Please input a valid choice!" << std::endl;
        std::cin >> choice;
    }

    if (choice == 2) return;

    std::cout << "Please select which patient you would like to appoint a date to!" << std::endl;

    std::cin >> choice;
    while (choice <= 0 || choice >= patientNumber){
        std::cout << "Please select a valid choice!" << std::endl;
        std::cin >> choice;
    }

    int patientID = this->parse->getID(patients[choice], patientPath);
    std::cout << "Input a date for the appointment (dd/MM/yyyy): ";
    std::string date; getline(std::cin, date);

    while (!birthValidation(date)){
        if (!date.empty()) std::cout << "Please input a valid date!" << std::endl;
        getline(std::cin, date);
    }

    std::string dd = Split(date, '/', 0);
    std::string MM = Split(date, '/', 1);
    std::string yyyy = Split(date, '/', 2);

    if (dd[0] == '0') dd = dd[1];
    if (MM[0] == '0') MM = MM[1];
    DateTime appointment = {stoi(dd), stoi(MM), stoi(yyyy)};

    makeAppointment(patientID, appointment);

}

void DoctorOperations::dSeeMedicineList(){
    std::cout << "Medicine List:" << std::endl;
    std::ifstream fin(medicinePath);

    std::string data;
    while (getline(fin, data)){
        std::cout << Split(data, ',', 0);
        if (stoi(Split(data, ',', 1)) != 0) std::cout << " - Available (" << Split(data, ',', 1) << " left)";
        else std::cout << " - Unavailable";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void DoctorOperations::ModifyMedicineList(){
    std::stack<std::string> changes;
    std::stack<std::string> redo;
    dSeeMedicineList();

    std::cout << "If you would like to add a medicine, type 'add [Medicine] [Quantity]'" << std::endl;
    std::cout << "If you would like to remove a medicine, type 'remove [Medicine] [Quantity]'" << std::endl;
    std::cout << "If you would like to undo an operation, type 'undo'" << std::endl;
    std::cout << "If you would like to redo an operation, type 'redo'" << std::endl;
    std::cout << "To view, please type 'view'" << std::endl;
    std::cout << "To stop, please type 'stop'" << std::endl;

    std::string choice; getline(std::cin, choice);
    do{
        choice = Strip(choice, ' ');
        std::string command = Split(choice, ' ', 0);
        std::string medicine = Split(choice, ' ', 1);
        std::string quantity = Split(choice, ' ', 2);

        if (Lower(command) == "add"){
            if (medicine == choice || quantity == choice){
                std::cout << "Please input both the medicine and quantity!" << std::endl;
                getline(std::cin, choice);
                continue;
            }
            if (this->medicineRepo->MedicineRepoExist(medicine)){
                int newQuantity = this->medicineRepo->getQuantity(medicine) + stoi(quantity);
                this->medicineRepo->MedicineRepoModify(medicine, std::to_string(newQuantity));
                std::cout << "Medicine was added successfully!" << std::endl;
                std::getline(std::cin, choice);
                continue;
            }
            this->medicineRepo->MedicineRepoAdd(medicine + "," + quantity);
            changes.push(medicine + "," + quantity);
            std::cout << "Medicine was added successfully!" << std::endl;
            std::getline(std::cin, choice);
        }
        else if (Lower(command) == "remove"){
            if (medicine == choice || quantity == choice){
                std::cout << "Please input both the medicine and the quantity!" << std::endl;
                getline(std::cin, choice);
                continue;
            }
            if (stoi(quantity) > this->medicineRepo->getQuantity(medicine)){
                std::cout << "The quantity you want to remove exceeds the total quantity!" << std::endl;
                getline(std::cin, choice);
                continue;
            }
            int newQuantity = this->medicineRepo->getQuantity(medicine) - stoi(quantity);
            this->medicineRepo->MedicineRepoModify(medicine, std::to_string(newQuantity));
            std::cout << "Medicine was removed successfully!" << std::endl;
            std::getline(std::cin, choice);
        }
        else if (Lower(command) == "undo"){
            if (changes.empty()){
                getline(std::cin, choice);
                continue;
            }
            std::string lastChange = changes.top();
            this->medicineRepo->MedicineRepoRemove(lastChange);
            redo.push(changes.top());
            changes.pop();
            dSeeMedicineList();
            std::getline(std::cin, choice);
        }
        else if (Lower(command) == "redo"){
            if (redo.empty()){
                getline(std::cin, choice);
                continue;
            }
            std::string lastChange = redo.top();
            this->medicineRepo->MedicineRepoAdd(lastChange);
            changes.push(redo.top());
            redo.pop();
            dSeeMedicineList();
            std::getline(std::cin, choice);
        }
        else if (Lower(command) == "view"){
            dSeeMedicineList();
            std::getline(std::cin, choice);
        }
        else{
            std::cout << "Command could not be found!" << std::endl;
            std::getline(std::cin, choice);
        }
    }while(choice != "stop");
}

void DoctorOperations::FillMedicineFile(){
    bool found = false;

    int patientNumber = 1;
    std::string patients[100];
    std::ifstream aFin(appointmentsPath);

    std::string data;
    while (getline(aFin, data)){
        int doctorID = stoi(Split(data, ',', 0));
        int patientID = stoi(Split(data, ',', 1));

        if (loggedDoctor.getID() == doctorID){
            if (!found){
                std::cout << "Requesting Patients:" << std::endl;
                found = true;
            }
            patients[patientNumber] = getPatientByID(patientID);
            std::cout << patientNumber << ". " << getPatientByID(patientID);
            patientNumber++;

            if (Split(data, ',', 2) == data){
                std:: cout << " - Not appointed";
            }
            else std::cout << " - Appointed at " << Split(data, ',', 2);
            std::cout << std::endl;
        }
    }

    if (!found){
        std::cout << "There are no requesting patients!" << std::endl;
        return;
    }
    std::cout << std::endl;

    std::cout << "Which file would you like to fill?" << std::endl;
    int choice; std::cin >> choice;

    while (choice < 0 || choice >= patientNumber || !hasAppointment(patients[choice])){
        std::cout << "Please select a valid patient!" << std::endl;
        std::cin >> choice;
    }

    std::string currentPatient = patients[choice];
    std::cout << "Are you sure you want to fill " + currentPatient + "'s file?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    std::cin >> choice;

    while (choice != 1 && choice != 2){
        std::cout << "Please select a valid choice!" << std::endl;
        std::cin >> choice;
    }

    if (choice == 2) return;

    std::cout << "Would you like to see " << currentPatient << "'s Medical file?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    std::cin >> choice;

    while (choice != 1 && choice != 2){
        std::cout << "Please select a valid choice!" << std::endl;
        std::cin >> choice;
    }

    if (choice == 1) {
        showPatientFile(this->parse->getID(currentPatient, patientPath));
        std::cout << std::endl;
    }

    std::cout << "In order to fill the Patient's Diagnosis file, please provide the following:" << std::endl;
    std::cout << "Date of Diagnosis (dd/MM/yyyy): ";
    std::string date; getline(std::cin, date);

    while (!birthValidation(date)){
        if (!date.empty()) std::cout << "Please input a valid date!" << std::endl;
        getline(std::cin, date);
    }

    std::string dd = Split(date, '/', 0);
    std::string MM = Split(date, '/', 1);
    std::string yyyy = Split(date, '/', 2);

    if (dd[0] == '0') dd = dd[1];
    if (MM[0] == '0') MM = MM[1];
    DateTime birth = {stoi(dd), stoi(MM), stoi(yyyy)};

    std::cout << "Diagnosis: ";
    std::string diagnosis; std::getline(std::cin, diagnosis);

    std::cout << "Prescription: ";
    std::string prescription; std::getline(std::cin, prescription);

    std::string file = std::to_string(loggedDoctor.getID()) + "," + std::to_string(this->parse->getID(patients[choice], patientPath))
            + "," + birth.showTime() + "," + diagnosis + "," + prescription;
    saveFile(file);

    std::cout << "The file was saved successfully!" << std::endl << std::endl;

}

void DoctorOperations::makeAppointment(int patientID, DateTime date){
    std::ifstream aFin(appointmentsPath);
    std::string appointments[100];
    int num = 0;

    std::string data;
    while (getline(aFin, data)){
        num++;
        appointments[num] = data;
    }

    aFin.close();

    for ( int i = 1 ; i <= num ; i++ ){
        if (stoi(Split(appointments[i], ',', 0)) == loggedDoctor.getID()){
            if (stoi(Split(appointments[i], ',', 1)) == patientID
                    && Split(appointments[i], ',', 2) == appointments[i]){
                appointments[i] += "," + date.showTime();
                break;
            }
            else if (stoi(Split(appointments[i], ',', 1)) == patientID
                    && Split(appointments[i], ',', 2) != appointments[i]){
                std::string _doctorID = Split(appointments[i], ',', 0);
                std::string _patientID = Split(appointments[i], ',', 1);
                std::string _date = date.showTime();
                appointments[i] = _doctorID + "," + _patientID + "," + _date;
                break;
            }
        }
    }

    std::ofstream aTrunc(appointmentsPath, std::ios_base::trunc);
    aTrunc.close();

    std::ofstream aFout(appointmentsPath, std::ios_base::app);
    for ( int i = 1 ; i <= num ; i++) aFout << appointments[i] << std::endl;

    std::cout << "The appointment was successful!" << std::endl << std::endl;
}

void DoctorOperations::saveFile(const std::string& file){
    std::ofstream fout(doctorPatients, std::ios_base::app);
    fout << file << std::endl;
}

bool DoctorOperations::hasAppointment(const std::string& patient){
    int patientID = this->parse->getID(patient, patientPath);

    std::ifstream fin(appointmentsPath);
    std::string data;
    while (getline(fin, data)){
        if (Split(data, ',', 1) == std::to_string(patientID)) return true;
    }
    return false;

}

void DoctorOperations::showPatientFile(int ID){
    std::ifstream fin(pFilePath);
    std::string data;

    std::string name = Split(getPatientByID(ID), ' ', 0);
    std::string surname = Split(getPatientByID(ID), ' ', 1);
    std::string phoneNumber;
    std::string address;
    std::string symptoms;
    std::string dateOfBirth;

    while (getline(fin, data)){
        if (stoi(Split(data, ',', 0)) == ID) break;
    }

    dateOfBirth = Split(data, ',', 2);
    address = Split(data, ',', 3);
    phoneNumber = Split(data, ',', 4);
    symptoms = Split(data, ',', 5);

    std::cout << "Patient File:" << std::endl << std::endl;

    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;

    std::cout << "Address: " << address << std::endl;
    std::cout << "Date of Birth: " << dateOfBirth;
    std::cout << std::endl;

    std::cout << "Symptoms: " << std::endl << symptoms << std::endl;
}
