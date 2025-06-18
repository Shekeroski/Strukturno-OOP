#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;
class InvalidCodeFormatException : public exception {
    string code;
    public:
    InvalidCodeFormatException(string code) : code(code) {
    }
    void mssg() {
        cout<<"The code "<<code<<" is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA."<<endl;
    }
};
class Doctor {
protected:
    string name;
    string surname;
    float salary;
    string code;
public:
   virtual float calculate_salary()=0;
    virtual void print()=0;
    Doctor(string name="", string surname="", string code="1x2c3v4g",float salary=0) {
        this->name = name;
        this->surname = surname;
        this->salary = salary;
        this->code = code;
        if(code.length()!=8 || code.find(',')!=string::npos) {
            throw InvalidCodeFormatException(code);
        }
    }
    string getCode() {
        return code;
    }
};
class GeneralDoctor : public Doctor {
    private:
    int numberOfPacients;
public:
    GeneralDoctor(string name="", string surname="",string code="1x2c3v4g",int numberOfPacients=0,float salary=45000):Doctor(name,surname,code,salary) {
        this->numberOfPacients = numberOfPacients;
    }
    void print()override {
       cout<<"General Doctor: "<<name<<" "<<surname<<" "<<"CODE:"<<code<<" Salary: "<<calculate_salary()<<endl;
    }
    float calculate_salary()override {
       float plata=45000;
        plata = plata+((numberOfPacients/10.0f)*3000);
        plata=plata - (plata*0.07);
        return plata;
    }
};
    class Specialist : public Doctor {
    private:
        string special;
        int numberOfInterventions;
        int years;
    public:
        Specialist(string name="", string surname="", string code="1x2c3v4g",string special="",int numberOfInterventions=0,int years=0,float salary=55000):Doctor(name,surname,code,salary) {
            this->special = special;
            this->numberOfInterventions = numberOfInterventions;
            this->years = years;
        }
        float calculate_salary() override {
            double baseSalary = 55000;
            double intervencija=numberOfInterventions*85;
            double doovde = baseSalary + intervencija;
            double bonus=baseSalary*(years*0.05);
             doovde+=bonus;
            doovde=doovde-(doovde*0.07);
            return doovde;
        }
        void print()override {
            cout<<"Specialist: "<<name<<" "<<surname<<" "<<"CODE:"<<code<<" "<<special<<" "<<"Salary: "<<calculate_salary()<<endl;
        }
    };
void findDoctorsPercentage(Doctor **doctors,int n) {
    float general=0;
    int count=0;
    float special=0;
    for(int i=0;i<n;i++) {
        if(dynamic_cast<GeneralDoctor*>(doctors[i])) {
            if(doctors[i]->getCode().length()!=8 || doctors[i]->getCode().find(',')!=string::npos) {
                general--;
            }
            count++;
            general++;
        }else if(dynamic_cast<Specialist*>(doctors[i])) {
            if(doctors[i]->getCode().length()!=8 || doctors[i]->getCode().find(',')!=string::npos) {
                special--;
            }
            count++;
            special++;
        }
    }
    cout<<special*100.0/count<<"%"<<" of the doctors are specialists and "<<general*100.0/count<<"%"<<" are general doctors."<<endl;
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
        }catch(InvalidCodeFormatException &ex) {
            ex.mssg();
        }
            cout << "EXCEPTION HANDLING OK!" << endl;
    }
    else if (testCase == 4)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
        }catch(InvalidCodeFormatException &ex) {
            ex.mssg();
        }
            cout << "EXCEPTION HANDLING OK!" << endl;

    }
    else if (testCase == 5)
    {
        cout << "TESTING EXCEPTION HANDLING" << endl;
        try {
            Doctor *d = new Specialist("Beth", "Davis", "9,R$$334", "Cardiologist", 45, 5);
            d->print();
        }catch(InvalidCodeFormatException &ex) {
            ex.mssg();
        }
           try {
               Doctor *d1 = new Specialist("William", "Wilson", "785#Qy2B", "Pulmonologist", 50, 7);
               d1->print();
           }catch(InvalidCodeFormatException &ex) {
               ex.mssg();
           }
            try {
                Doctor *d2 = new Specialist("Beth", "Davis", "96Tr,", "Cardiologist", 45, 5);
                d2->print();
            }catch(InvalidCodeFormatException &ex) {
                ex.mssg();
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
            if (t == 1) // General doctor
            {

                    cin >> numberOfPatients;
                try{
                    doctors[i] = new GeneralDoctor(name, surname, code, numberOfPatients);
                }catch(InvalidCodeFormatException &ex) {
                    ex.mssg();
                }
            }
            else // Specialist
            {
                cin >> specialty;
                cin >> numberOfInterventions >> yearsOfExperience;
                    try {
                        doctors[i] = new Specialist(name, surname, code, specialty, numberOfInterventions, yearsOfExperience);
                    }catch(InvalidCodeFormatException &ex) {
                        ex.mssg();
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
        delete [] doctors;
    }
    return 0;
}
