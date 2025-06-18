#include<iostream>
#include<cstring>
using namespace std;
class Students {
   char *name;
   float prosek;
   int godina;
public:
   Students(){};
   Students( char *name, float prosek=0.0, int godina=0) {
      this->name = new char[strlen(name)+1];
      strcpy(this->name, name);
      this->godina = godina;
      this->prosek = prosek;
   }
   Students(const Students &s) {
      this->name = new char(strlen(s.name)+1);
      strcpy(this->name, s.name);
      this->godina = s.godina;
      this->prosek = s.prosek;
   }
   ~Students() {
      delete [] name;
   }
   Students& operator=(const Students &s) {
      if(this!=&s) {
         delete [] name;
         this->name = new char(strlen(s.name)+1);
         strcpy(this->name, s.name);
         this->godina = s.godina;
         this->prosek = s.prosek;
      }
      return *this;
   }
   Students& operator++() {
      this->godina++;
      return *this;
   }
   Students operator++(int) {
      Students temp(*this);
      this->godina++;
      return temp;
   }
   friend ostream& operator<<(ostream &COUT,const Students &s) {
      COUT<<"Name: "<<s.name<<endl;
      COUT<<"Godina: "<<s.godina<<endl;
      COUT<<"Prosek: "<<s.prosek<<endl;
      return COUT;
   }
   bool operator>(const Students &s) {
      return this->prosek>s.prosek;
   }
};
class Paralelka {
   Students *student;
   int broj_studenti;
public:
   Paralelka() {
      this->broj_studenti = 0;
      this->student = NULL;
   }
   Paralelka(const Paralelka &p) {
      this->broj_studenti = p.broj_studenti;
      this->student = new Students[this->broj_studenti];
      for(int i=0;i<this->broj_studenti;i++) {
         this->student[i] = p.student[i];
      }
   }
   ~Paralelka() {
      delete [] this->student;
   }
   Paralelka& operator=(const Paralelka &p) {
      if(this!=&p) {
         delete [] this->student;
         this->broj_studenti = p.broj_studenti;
         this->student= new Students[this->broj_studenti];
         for(int i=0;i<this->broj_studenti;i++) {
            this->student[i] = p.student[i];
         }
      }else {
         return *this;
      }
   }
   Paralelka & operator+=(const Students &p) {
      Students *temp = new Students[broj_studenti+1];
      for(int i=0;i<broj_studenti;i++) {
         temp[i] = this->student[i];
      }
      temp[broj_studenti]=p;
      broj_studenti++;
      delete [] this->student;
      this->student = temp;
      return *this;
   }
   Paralelka & operator++(int) {
      Paralelka temp = *this;
      for(int i=0;i<broj_studenti;i++) {
         this->student[i]++;
      }
      return *this;
   }
   friend ostream& operator<<(ostream &COUT,const Paralelka &p) {
      for(int i=0;i<p.broj_studenti;i++) {
         COUT<<p.student[i];
      }
      return COUT;
   }
};
int main() {
   Students u1("Martina Martinovska",9.5,3);
   Students u2("Angela Angelovska",10,3);
   Paralelka p;
   Paralelka p1;
   p+=u1;
   p+=u2;
   cout<<p;
}