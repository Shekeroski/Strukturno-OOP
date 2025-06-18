#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;

class BadInputException {
public:
    void mssg() {
        cout << "Greshna opisna ocenka" << endl;
    }
};

class StudentKurs {
protected:
    char ime[30];
    int ocenkaa;
    bool daliUsno;
    static int Max;
    static const int MINOCENKA = 6;
public:
    StudentKurs(const char* ime = "", int finalenIspit = 0) {
        strcpy(this->ime, ime);
        this->ocenkaa = finalenIspit;
        this->daliUsno = false;
    }

    virtual ~StudentKurs() {}

    bool getDaliUsno() const {
        return daliUsno;
    }

    static void setMAX(int a) {
        Max = a;
    }

    virtual int ocenkaFinalna() const {
        return ocenkaa;
    }

    const char* getIme() const {
        return ime;
    }

    friend ostream& operator<<(ostream& os, const StudentKurs& student) {
        os << student.ime << " --- " << student.ocenkaFinalna();
        return os;
    }
};

int StudentKurs::Max = 10;

class StudentKursUsno : public StudentKurs {
private:
    char* opisnaOcenka;
public:
    StudentKursUsno(const char* ime = "", int ocenka = 0, const char* opis = nullptr) : StudentKurs(ime, ocenka) {
        this->opisnaOcenka = nullptr;
        if (opis) {
            this->opisnaOcenka = new char[strlen(opis) + 1];
            strcpy(this->opisnaOcenka, opis);
        }
        this->daliUsno = true;
    }

    StudentKursUsno(const StudentKursUsno& s) : StudentKurs(s) {
        if (s.opisnaOcenka) {
            this->opisnaOcenka = new char[strlen(s.opisnaOcenka) + 1];
            strcpy(this->opisnaOcenka, s.opisnaOcenka);
        } else {
            this->opisnaOcenka = nullptr;
        }
        this->daliUsno = true;
    }

    StudentKursUsno& operator=(const StudentKursUsno& s) {
        if (this != &s) {
            delete[] this->opisnaOcenka;
            this->opisnaOcenka = s.opisnaOcenka ? new char[strlen(s.opisnaOcenka) + 1] : nullptr;
            if (s.opisnaOcenka) strcpy(this->opisnaOcenka, s.opisnaOcenka);
            strcpy(this->ime, s.ime);
            this->ocenkaa = s.ocenkaa;
            this->daliUsno = true;
        }
        return *this;
    }

    ~StudentKursUsno() {
        delete[] this->opisnaOcenka;
    }

    StudentKursUsno& operator+=(const char* s) {
        for (int i = 0; i < strlen(s); i++) {
            if (isdigit(s[i])) {
                throw BadInputException();
            }
        }
        delete[] this->opisnaOcenka;
        this->opisnaOcenka = new char[strlen(s) + 1];
        strcpy(this->opisnaOcenka, s);
        return *this;
    }

    int ocenkaFinalna() const override {
        if (!opisnaOcenka) return ocenkaa;

        if (strcmp(opisnaOcenka, "odlicen") == 0) {
            return min(ocenkaa + 2, Max);
        } else if (strcmp(opisnaOcenka, "dobro") == 0) {
            return min(ocenkaa + 1, Max);
        } else if (strcmp(opisnaOcenka, "losho") == 0) {
            return max(ocenkaa - 1, 1);
        } else {
            return ocenkaa;
        }
    }

    char* getOpisnaOcenka() {
        return this->opisnaOcenka;
    }
};

class KursFakultet {
private:
    char naziv[30];
    StudentKurs* studenti[20];
    int broj;

public:
    KursFakultet(const char* naziv, StudentKurs** studenti, int broj) {
        strcpy(this->naziv, naziv);
        for (int i = 0; i < broj; i++) {
            if (studenti[i]->getDaliUsno()) {
                this->studenti[i] = new StudentKursUsno(*dynamic_cast<StudentKursUsno*>(studenti[i]));
            } else {
                this->studenti[i] = new StudentKurs(studenti[i]->getIme(), studenti[i]->ocenkaFinalna());
            }
        }
        this->broj = broj;
    }

    ~KursFakultet() {
        for (int i = 0; i < broj; i++) delete studenti[i];
    }

    void pecatiStudenti() {
        cout << "Kursot " << naziv << " go polozile:" << endl;
        for (int i = 0; i < broj; i++) {
            if (studenti[i]->ocenkaFinalna() >= 6) {
                cout << *studenti[i] << endl;
            }
        }
    }

    void postaviOpisnaOcenka(const char* ime, const char* opisnaOcenka) {
        for (int i = 0; i < broj; i++) {
            if (strcmp(studenti[i]->getIme(), ime) == 0 && studenti[i]->getDaliUsno()) {
                StudentKursUsno* su = dynamic_cast<StudentKursUsno*>(studenti[i]);
                try {
                    *su += opisnaOcenka;
                } catch (BadInputException& e) {
                    e.mssg();
                    char popravka[100];
                    int j = 0;
                    for (int k = 0; k < strlen(opisnaOcenka); k++) {
                        if (isalpha(opisnaOcenka[k])) {
                            popravka[j++] = opisnaOcenka[k];
                        }
                    }
                    popravka[j] = '\0';
                    *su += popravka;
                }
            }
        }
    }
};

int main() {
    StudentKurs** niza;
    int n, m, ocenka;
    char ime[30], opisna[10];
    bool daliUsno;

    cin >> n;
    niza = new StudentKurs * [n];
    for (int i = 0; i < n; i++) {
        cin >> ime >> ocenka >> daliUsno;
        if (!daliUsno)
            niza[i] = new StudentKurs(ime, ocenka);
        else
            niza[i] = new StudentKursUsno(ime, ocenka);
    }

    KursFakultet programiranje((char*)"OOP", niza, n);
    for (int i = 0; i < n; i++) delete niza[i];
    delete[] niza;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ime >> opisna;
        programiranje.postaviOpisnaOcenka(ime, opisna);
    }

    StudentKurs::setMAX(9);
    programiranje.pecatiStudenti();
    return 0;
}