#include<iostream>
#include<cstring>
using namespace std;

class Student {
    char name[10];
    static int id;
    float gpa;
    int _id;
    static int vkupno_studenti;
    static float vkupno_prosek;
public:
    Student(){}
    Student(char *n, int _id, float g) {
        strcpy(name, n);
        gpa = g;
        vkupno_studenti++;
        vkupno_prosek+=gpa;
        this->_id=id;
        id++;

    }
    static int getVkupno() {
        return vkupno_studenti;
    }
    static float getVkupno_prosek() {
        return vkupno_prosek/vkupno_studenti;
    }
    void print() {
        cout << "Name: " << name;
        cout << "Id: " << id;
        cout << "GPA: " << gpa << endl;
    }
};
int Student::vkupno_studenti=0;
float Student::vkupno_prosek=0.0;
int main() {
    int n;
    cin>>n;
    Student student[n];
    char name[10];
    int id;
    float gpa;
    for(int i=0;i<n;i++) {
        cin>>name>>gpa;
        student[i]=Student(name,id,gpa);
    }
    for(int i=0;i<n;i++) {
        student[i].print();
    }
    cout<<Student::getVkupno_prosek()<<endl;
    cout<<Student::getVkupno()<<endl;
    return 0;
}