#include<iostream>
using namespace std;

struct Employe {
    int id;
    int salary;
    char name[10];
    void read() {
        cin>>name>>id>>salary;
    }
    void print() {
        cout<<name<<" "<<id<<" "<<salary;
    }
};
//   void read(Employe &e) {
//       cin>>e.name>>e.id>>e.salary;
//   }
// void print(Employe &e) {
//       cout<<e.name<<" "<<e.id<<" "<<e.salary;
//   }
int main() {
    Employe e;
    // read(e);
    // print(e);
    e.read();
    e.print();
}