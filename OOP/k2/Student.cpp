#include <iostream>
#include<string>
#include <fstream>
using namespace std;
class StudentFailedException:public exception {
private:
    string id;
    public:
    StudentFailedException(string id):id(id) {
    }
    void print() {
        cout<<"Student with id "<<id<<" failed the course"<<endl;
    }
};
class Student {
private:
    string index;
    string name;
    string surname;
    int points;
public:
    Student(string index="",string name="",string surname="",int points=0) {
        this->index=index;
        this->name=name;
        this->surname=surname;
        this->points=points;
    }
    int grade() const{
        if(points>=0 && points <=49) {
            return 5;
        }
        else if(points>=50 && points<=59) {
            return 6;
        }
        else if(points>=60 && points<=69) {
            return 7;
        }
        else if(points>=70 && points<=79) {
            return 8;
        }
        else if(points>=80 && points<=89) {
            return 9;
        }
        else if(points>=90 && points<=100) {
            return 10;
        }
    }
    int getPoints() const{
        return points;
    }
    string getIndex() const {
        return index;
    }
    string getName() const {
        return name;
    }
    string getSurname() const {
        return surname;

    }
};
class Results {
private:
    Student *students;
    int n;
public:
    Results() {
        n=0;
        students=nullptr;
    }
    Results(Student *students,int n) {
        this->n=n;
        this->students=new Student[n];
        for(int i=0;i<n;i++) {
            this->students[i]=students[i];
        }
    }
    Results(const Results &other) {
        this->n=other.n;
        students=new Student[other.n];
        for(int i=0;i<n;i++) {
            this->students[i]=other.students[i];
        }
    }
    Results& operator=(const Results &other) {
        if(this!=&other) {
         this->n=other.n;
            delete [] students;
            students=new Student[other.n];
            for(int i=0;i<n;i++) {
                students[i]=other.students[i];
            }
        }
        return *this;
    }
    int getN() {
        return n;
    }
    ~Results() {
        delete[] students;
    }
    Results &operator+=(const Student &other) {
             if(other.getPoints()<50) {
               throw StudentFailedException(other.getIndex());
             }
        Student *temp=new Student[n+1];
        for(int i=0;i<n;i++) {
            temp[i]=students[i];
        }
        temp[n]=other;
        delete [] students;
        students=temp;
        ++n;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Results &r) {
        for(int i=0;i<r.n;i++) {
            os<<r.students[i].getIndex()<<" "<<r.students[i].getName()<<" "<<r.students[i].getSurname()<<" "<<r.students[i].getPoints()<<" Grade: "<<r.students[i].grade()<<endl;
        }
        return os;
    }
    Results withGrade(int grade) {
        Results results;
        for(int i=0;i<n;i++) {
            if(students[i].grade()==grade) {
                results+=students[i];
            }
        }
            return results;
    }
};
void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----"){
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {
    string index;
    string name;
    string surname;
    int points;
    wtf();

    Results results;
    //TODO your code here
    //TODO Read the students from the file and add them in `results`
    ifstream fin("input.txt");
    while(fin>>index>>name>>surname>>points) {
        fin.ignore();
        try {
            Student student(index,name,surname,points);
            results+=student;
        }catch(StudentFailedException &e) {
            e.print();
        }
    }
    
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    int grade;
    cin >> grade;
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files output1.txt and output2.txt after this line
    ofstream fout1("output1.txt");
    fout1<<results;
    ofstream fout2("output2.txt");
        Results r = results.withGrade(grade);
        fout2<<r;

    //DO NOT MODIFY THE CODE BELLOW
    cout << "All students:" << endl;
    rff("output1.txt");
    cout << "Grade report for grade " << grade << ": " << endl;
    rff("output2.txt");


    return 0;
}