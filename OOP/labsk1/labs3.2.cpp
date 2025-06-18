#include<iostream>
#include<cstring>
using namespace std;

class Employee {
  char name[10];
    int id;
    double salary;
public:
    friend class Company;
    Employee() {
    }
    Employee(char name[], int id, double salary) {
        strcpy(this->name,name);
        this->id = id;
        this->salary = salary;
    }
    Employee(const Employee &e) {
        strcpy(this->name,e.name);
        this->id = e.id;
        this->salary = e.salary;
    }
   friend void updateSalary(Company &c,int idd,double newsalary);
};
class Company {
    char name[10];
    Employee *employees;
    int br_vraboteni;
public:
    friend class Employee;
    Company() {
        strcpy(this->name,"TechCorp");
        this->br_vraboteni = 0;
    }
    void addEmployee(Employee &e) {
        if(br_vraboteni < 100) {
            employees[br_vraboteni++] = e;
        }
    }
   friend void updateSalary(Company &c,int idd,double newsalary);
};
void updateSalary(Company &c,int idd,double newsalary) {
    for(int i=0;i<c.br_vraboteni;i++) {
        if(c.employees[i].id==idd) {
            c.employees[i].salary = newsalary;
            cout<<"Salary updated for employee: "<<c.employees[i].name<<endl;
        }
    }
}

int main() {
    Company techCorp;
    int m;
    cout << "Vnesi broj na vraboteni: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        char name[10];
        int id;
        double salary;
        cout << "Vnesi ime, ID i plata za vraboten " << i + 1 << ": ";
        cin >> name >> id >> salary;
        Employee e(name, id, salary);
        techCorp.addEmployee(e);
    }


    int empId;
    double newSalary;
    cout << "Vnesi ID za promena na plata: ";
    cin >> empId;
    cout << "Vnesi nova plata: ";
    cin >> newSalary;

    updateSalary(techCorp, empId, newSalary);

    return 0;
}