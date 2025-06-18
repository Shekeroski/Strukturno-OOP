#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;
class InvalidCodeFormatException : public exception {
private:
    string kod;
    public:
    InvalidCodeFormatException(string kod) {
        this->kod = kod;
    }
    void mssg() {
        cout << "The code "<<kod<<" is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA." << endl;
    }
};
class Doctor {
    protected:
    string name;
    string prezime;
    float plata;
    string kod;
    public:
    Doctor(string name="", string prezime="", float plata=0.0, string kod="1k83d87h") {
        this->name = name;
        this->prezime = prezime;
        this->plata = plata;
        this->kod = kod;
        if(kod.length()!=8 || kod.find(',')!=string::npos) {
            throw InvalidCodeFormatException(kod);
        }
    }
    Doctor(string name, string prezime, string kod) {
        this->name = name;
        this->prezime = prezime;
        this->kod = kod;
        if(kod.length()!=8 || kod.find(',')!=string::npos) {
            throw InvalidCodeFormatException(kod);
        }
    }
    virtual float calculateSalary()=0;
    virtual void print()=0;
    string getCode() {
        return kod;
    }
};
class GeneralDoctor : public Doctor {
private:
    int brojPacienti;
public:
    GeneralDoctor(string name, string prezime, float plata, string kod,int pacienti):Doctor(name,prezime,plata,kod) {
        this->brojPacienti = pacienti;
    }
    float calculateSalary() override {
        float baseSalary=45000;
        float dopolnitelni=(brojPacienti/10)*3000;
        float vkupno=baseSalary+dopolnitelni;
        float krajna=vkupno-(vkupno*0.07);
        return krajna;
    }
    GeneralDoctor(string name,string prezime,string kod,int pacienti):Doctor(name,prezime,kod) {
        this->brojPacienti = pacienti;
    }
    void print() override {
        cout<<"General Doctor: "<<name<<" "<<prezime<<" CODE:"<<kod<<" Salary: "<<calculateSalary()<<endl;
    }
};
class Specialist : public Doctor {
private:
    string specijalnost;
    int intervencii;
    int godiniIskustvo;
public:

    Specialist(string name, string prezime, string kod,string specijalnost,int intervencii,int godiniIskustvo):Doctor(name,prezime,kod) {
        this->specijalnost = specijalnost;
        this->intervencii = intervencii;
        this->godiniIskustvo = godiniIskustvo;
    }
    void print() override {
        cout<<"Specialist: "<<name<<" "<<prezime<<" CODE:"<<kod<<" "<<specijalnost<<" Salary: "<<calculateSalary()<<endl;
    }
    float calculateSalary() override {
        float baseSalary=55000;
        float dopolnitelni=intervencii*85;
        float godinibonus=baseSalary*(godiniIskustvo*0.05);
        float vkupno=baseSalary+dopolnitelni+godinibonus;
        float krajna=vkupno-(vkupno*0.07);
        return krajna;
    }
};
void findDoctorsPercentage(Doctor **doctors, int n) {
    int generals=0;
    int specialists=0;
    int counter=0;
    for(int i=0; i<n; i++) {
        if(dynamic_cast<GeneralDoctor *>(doctors[i])) {
            if(doctors[i]->getCode().length()!=8 || doctors[i]->getCode().find(',')!=string::npos) {
                generals--;
            }
            counter++;
            generals++;
        }
        else if(dynamic_cast<Specialist *>(doctors[i])) {
            if(doctors[i]->getCode().length()!=8 || doctors[i]->getCode().find(',')!=string::npos) {
                specialists--;
            }
            counter++;
            specialists++;
        }
    }
    cout<<(specialists*100.0)/counter<<"% of the doctors are specialists and "<<(generals*100.0)/counter<<"% are general doctors."<<endl;
}
int main()
{
    int testCase, n;
    string name, surname, specialty, code;
    int numberOfPatients, yearsOfExperience, numberOfInterventions;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "TESTING GENERAL DOCTOR CLASS" << endl;
            Doctor *d = new GeneralDoctor("John", "Smith", "236XY@2B", 120);
            Doctor *d1 = new GeneralDoctor("Marco", "Brown", "345X!Y2B", 120);
            Doctor *d2 = new GeneralDoctor("Emily", "Johnson", "ABCD123@", 230);
            d->print();
            d1->print();
            d2->print();

        cout << "GENERAL DOCTOR CLASS OK!" << endl;
    }
    else if (testCase == 2)
    {
        cout << "TESTING SPECIALIST DOCTOR CLASS" << endl;
            Doctor *d = new Specialist("Beth", "Davis", "96Tr$$33", "Cardiologist", 45, 5);
            Doctor *d1 = new Specialist("William", "Wilson", "785#Qy2B", "Pulmonologist", 50, 7);
            Doctor *d2 = new Specialist("Micheal", "Rosen", "7896YZ$s", "Radiologist", 41, 10);
            d->print();
            d1->print();
            d2->print();
        cout << "SPECIALIST DOCTOR CLASS OK!" << endl;
    }
    else if (testCase == 3)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new GeneralDoctor("John", "Smith", "23Y@2B", 120);
            d->print();
        }catch(InvalidCodeFormatException &e) {
            e.mssg();
        }

        cout << "EXCEPTION HANDLING OK!" << endl;
    }
    else if (testCase == 4)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
        }catch(InvalidCodeFormatException &e) {
            e.mssg();
        }
        cout << "EXCEPTION HANDLING OK!" << endl;
    }
    else if (testCase == 5)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
        }catch(InvalidCodeFormatException &e) {
            e.mssg();
        }
        try {
            Doctor *d1 = new Specialist("William", "Wilson", "785#Qy2B", "Pulmonologist", 50, 7);
            d1->print();
        }catch(InvalidCodeFormatException &e) {
            e.mssg();
        }
        try {
            Doctor *d2 = new Specialist("Beth", "Davis", "96Tr,", "Cardiologist", 45, 5);
            d2->print();
        }catch(InvalidCodeFormatException &e) {
            e.mssg();
        }
        cout << "EXCEPTION HANDLING OK!" << endl;
    }
    else
    {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION!" << endl;
        cin >> n;
        Doctor **doctors = new Doctor *[n];
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            cin >> name >> surname;
            cin >> code;
            if (t == 1)
            {
                cin >> numberOfPatients;
                   try {
                       doctors[i] = new GeneralDoctor(name, surname, code, numberOfPatients);
                   }catch(InvalidCodeFormatException &e) {
                       e.mssg();
                   }

            }
            else
            {
                cin >> specialty;
                cin >> numberOfInterventions >> yearsOfExperience;
                    try {
                        doctors[i] = new Specialist(name, surname, code, specialty, numberOfInterventions, yearsOfExperience);
                    }catch(InvalidCodeFormatException &e) {
                        e.mssg();
                    }

            }
        }
        cout << "LIST OF ALL DOCTORS: " << endl;
        for (int i = 0; i < n; i++)
        {
            if(doctors[i] != nullptr)
                doctors[i]->print();
        }
        findDoctorsPercentage(doctors, n);
        for (int i = 0; i < n; i++)
        {
            delete doctors[i];
        }
        delete[] doctors;
    }
    return 0;
}
