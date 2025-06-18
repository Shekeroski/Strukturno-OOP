#include<iostream>
#include<cstring>
using namespace std;

class Employee {
protected:
    char *name;
    int godini;
    int rabotno_iskustvo;
    void copy(const Employee &l) {
        name = new char[strlen(l.name) + 1];
        strcpy(name, l.name);
        this->godini = l.godini;
        this->rabotno_iskustvo = l.rabotno_iskustvo;
    }
public:
    bool operator==( Employee &e) {
        return (this->godini == e.godini && this->bonus()==e.bonus());
    }
    virtual double plata()=0;
    virtual double bonus()=0;
    Employee(char *name, int godini, int rabotno_iskustvo) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->godini = godini;
        this->rabotno_iskustvo = rabotno_iskustvo;
    }
    Employee(const Employee &e) {
        copy(e);
    }
    Employee &operator=(const Employee &e) {
        if (this != &e) {
            delete [] name;
            copy(e);
        }
        return *this;
    }
    ~Employee() {
        delete [] name;
    }
};
class SalaryEmployee : public Employee {
private:
    int osnovna_plata;
public:
    SalaryEmployee(char *name,int godini,int rabotno_iskustvo,int osnovna_plata):Employee(name,godini,rabotno_iskustvo) {
        this->osnovna_plata=osnovna_plata;
    }
    double bonus() {
        return (rabotno_iskustvo/100.0)*osnovna_plata;
    }
    double plata() {
        return osnovna_plata+bonus();
    }
};
class HourlyEmployee : public Employee {
    private:
    int vkp_casovi;
    int plata_cas;
public:
    HourlyEmployee(char *name,int godini,int rabotno_iskustvo,int vkp_casovi,int plata_cas):Employee(name,godini,rabotno_iskustvo) {
        this->vkp_casovi=vkp_casovi;
        this->plata_cas=plata_cas;
    }
    double bonus() {
        if(vkp_casovi>320) {
            return (vkp_casovi-320)*plata_cas*0.5;
        }else {
            return 0;
        }
    }
    double plata() {
        return vkp_casovi*(plata_cas+bonus());
    }
};
class Freelancer : public Employee {
private:
    int br_proekti;
    double sum[10];
public:
    Freelancer(char *name,int godini,int rabotno_iskustvo,int br_proekti,double *sum) : Employee(name,godini,rabotno_iskustvo) {
        this->br_proekti=br_proekti;
        for(int i=0;i<br_proekti;i++) {
            this->sum[i]=sum[i];
        }
    }
    double bonus() {
        if(br_proekti>5) {
          return (br_proekti-5)*1000;
        }else {
            return 0;
        }
    }
    double plata() {
        double s=0;
        for(int i=0;i<br_proekti;i++) {
            s+=sum[i];
        }
        return s;
    }
};
class Company {
private:
    char name[10];
    int br_vraboteni;
    Employee **employees;
public:
    Company(char *name) {
        strcpy(this->name,name);
    }
    Company &operator +=(Employee *c) {
        Employee **temp = new Employee *[employees +1];
        for(int i=0;i<br_vraboteni;i++) {
            temp[i]=employees[i];
        }
        temp[br_vraboteni]=c;
        delete []employees;
        employees=temp;
        br_vraboteni++;
        return *this;
    }
    double vkupnaPlata() {
        double s=0;
        for(int i=0;i<br_vraboteni;i++) {
            s+=employees[i]->plata();
        }
        return s;
    }
    double filtriranaPlata(Employee *emp) {
        double s=0;
        for(int i=0;i<br_vraboteni;i++) {
            if(*emp==*employees[i]) {
                s+= emp->plata();
            }
        }
        return s;
    }
    void pecatiRabotnici() {
        int s=0,h=0,f=0;
        for(int i=0;i<br_vraboteni;i++) {
            SalaryEmployee *salary= dynamic_cast<SalaryEmployee *>(employees[i]);
            HourlyEmployee *hourly= dynamic_cast<HourlyEmployee *>(employees[i]);
            Freelancer *freelancer= dynamic_cast<Freelancer *>(employees[i]);
            if(dynamic_cast<SalaryEmployee *>(employees[i])) {
                s++;
            }
            if(dynamic_cast<HourlyEmployee *>(employees[i])) {
                h++;
            }
            if(dynamic_cast<Freelancer *>(employees[i])) {
                f++;
            }
        }
        cout<<"vo kompanijata "<<name<<" rabotat: "<<endl;
        cout << "Salary employees: " << s << endl;
        cout << "Hourly employees: " << h << endl;
        cout << "Freelancers: " << f << endl;
    }
};
int main() {
    char name[50];
    cin >> name;
    Company c(name);

    int n;
    cin >> n;

    char employeeName[50];
    int age;
    int experience;
    int type;

    for (int i = 0; i < n; ++i)
    {
        cin >> type;
        cin >> employeeName >> age >> experience;

        if (type == 1)
        {
            int basicSalary;
            cin >> basicSalary;
            c += new SalaryEmployee(employeeName, age, experience, basicSalary);
        }

        else if (type == 2)
        {
            int hoursWorked;
            int hourlyPay;
            cin >> hoursWorked >> hourlyPay;
            c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
        }

        else
        {
            int numProjects;
            cin >> numProjects;
            double projects[10];
            for (int i = 0; i < numProjects; ++i)
            {
                cin >> projects[i];
            }
            c += new Freelancer(employeeName, age, experience, numProjects, projects);
        }
    }

    c.pecatiRabotnici();
    cout << "Vkupnata plata e: " << c.vkupnaPlata() << endl;
    Employee *emp = new HourlyEmployee("Petre_Petrov", 31, 6, 340, 80);
    cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

    delete emp;
}