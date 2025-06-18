#include<iostream>
#include<cstring>
using namespace std;
class NoCourseException : public exception {
private:
    int index;
public:
    NoCourseException(int index) {
        this->index = index;
    }
    void mssg() {
        cout<<"Demonstratorot so indeks "<<index<<" ne drzi laboratoriski vezbi , каде "<<index<<" е индексот на демонстраторот"<<endl;
    }
};
class Kurs {
protected:
    char name[20];
    int krediti;
    public:
    Kurs(){}
    Kurs(char *name,int krediti) {
        strcpy(this->name,name);
        this->krediti=krediti;
    }
    void print() {
        cout<<"Kurs: "<<name<<" "<<krediti<<" ECTS"<<endl;
    }
    char *getIme() {
        return name;
    }
};
class Student {
protected:
    int index;
    int *niza;
    int n;
    public:
    Student() {
        index=0;
        niza=nullptr;
    }
    Student(int index,int*niza,int n) {
        this->index=index;
        this->n=n;
        this->niza=new int[n];
        for(int i=0;i<n;i++) {
            this->niza[i]=niza[i];
        }
    }
    Student(const Student &s) {
        this->index=s.index;
        this->n=s.n;
        this->niza=new int[s.n];
        for(int i=0;i<s.n;i++) {
            this->niza[i]=s.niza[i];
        }
    }
    Student& operator=(const Student &s) {
        if(this!=&s) {
            delete[] this->niza;
            this->index=s.index;
            this->n=s.n;
            this->niza=new int[s.n];
            for(int i=0;i<s.n;i++) {
                this->niza[i]=s.niza[i];
            }
        }
        return *this;
    }
    ~Student() {
        delete[] this->niza;
    }
    virtual int getBodovi() {
        int counter=0;
        int s=0;
        int polozeni=0;
        for(int i=0;i<n;i++) {
            counter++;
            if(niza[i]>5) {
                polozeni++;
            }
        }
        int ocenkaprocent=100/counter;
        int krajna=ocenkaprocent*polozeni;
        return krajna;
    }
    virtual void pecati() {
        cout<<index<<endl;
    }
};
class Predavach {
private:
    char *name;
    Kurs *kursevi;
    int n;
public:
    Predavach() {
        name=nullptr;
        kursevi=nullptr;
        n=0;
    }
    Predavach(char *name,Kurs *kursevi,int n) {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->n=n;
        this->kursevi=new Kurs[n];
        for(int i=0;i<n;i++) {
            this->kursevi[i]=kursevi[i];
        }
    }
    Predavach(const Predavach &s) {
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
        this->n=s.n;
        this->kursevi=new Kurs[s.n];
        for(int i=0;i<s.n;i++) {
            this->kursevi[i]=s.kursevi[i];
        }
    }
    ~Predavach() {
        delete[] this->name;
        delete[] this->kursevi;
    }
    Predavach& operator=(const Predavach &s) {
        if(this!=&s) {
            delete[] this->name;
            this->name=new char[strlen(s.name)+1];
            strcpy(this->name,s.name);
            this->n=s.n;
            delete[] this->kursevi;
            for(int i=0;i<s.n;i++) {
                this->kursevi[i]=s.kursevi[i];
            }
        }
        return *this;
    }
};
class Demonstrator : public Student {
private:
    char *name;
    Kurs *kursevi;
    int n;
    int brcasovi;
    public:
    Demonstrator() {
        name=nullptr;
        kursevi=nullptr;
        n=0;
        brcasovi=0;
    }
    Demonstrator(int index,int*niza,int br,char *name,Kurs *kursevi,int n,int brcasovi):Student(index,niza,br) {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->n=n;
        this->kursevi=new Kurs[n];
        for(int i=0;i<n;i++) {
            this->kursevi[i]=kursevi[i];
        }
        this->brcasovi=brcasovi;
    }
    Demonstrator& operator=(const Demonstrator &s) {
        if(this!=&s) {
            Student::operator=(s);
            delete[] this->name;
            this->name=new char[strlen(s.name)+1];
            strcpy(this->name,s.name);
            this->n=s.n;
            this->kursevi=new Kurs[n];
            for(int i=0;i<n;i++) {
                this->kursevi[i]=s.kursevi[i];
            }
            this->brcasovi=s.brcasovi;
        }
        return *this;
    }
    Demonstrator(const Demonstrator &s):Student(s){
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
        this->n=s.n;
        this->kursevi=new Kurs[n];
        for(int i=0;i<n;i++) {
            this->kursevi[i]=s.kursevi[i];
        }
        this->brcasovi=s.brcasovi;
    }
    ~Demonstrator() {
        delete[] this->name;
        delete[] this->kursevi;
    }
    int getBodovi() override {
        if(n==0) {
            throw NoCourseException(index);
        }
        int c=Student::getBodovi();
        int s=(20*brcasovi)/n;
        return s;
    }
    void pecati() override{
        cout<<index<<": "<<name<<" (";
        for(int i=0;i<n;i++) {
            kursevi[i].print();
        }
    }
    int getN() {
        return n;
    }
    int getBrojKursevi() {
        return n;
    }
    char *getIme() {
        return name;
    }
    Kurs *getKursevi() {
        return kursevi;
    }
};
Student& vratiNajdobroRangiran(Student ** studenti, int n ) {
    int najmnogu=0;
    int najindex=0;
    Student s;
    for(int i=0;i<n;i++) {
        int bodovi=0;
        try {
            bodovi=studenti[i]->getBodovi();
        }catch(NoCourseException &e) {
            e.mssg();
        }
        if(bodovi>najmnogu) {
            najmnogu=bodovi;
            najindex=i;
        }
    }
    return *studenti[najindex];
}
void pecatiDemonstratoriKurs(const char* kurs, Student** studenti, int n) {
    for (int i = 0; i < n; i++) {
        Demonstrator* d = dynamic_cast<Demonstrator*>(studenti[i]);
            for (int j = 0; j < d->getBrojKursevi(); j++) {
                if (strcmp(d->getKursevi()[j].getIme(), kurs) == 0) {
                    cout << d->getIme() << endl;
                    break;
                }
            }
    }
}

int main(){

Kurs kursevi[10];
int indeks,brojKursevi, ocenki[20],ocenka,brojOcenki,tip,brojCasovi,krediti;
char ime[20],imeIPrezime[50];

cin>>tip;

if (tip==1) //test class Demonstrator
{
    cout<<"-----TEST Demonstrator-----"<<endl;
    cin>>indeks>>brojOcenki;
    for (int i=0;i<brojOcenki;i++){
         cin>>ocenka;
         ocenki[i]=ocenka;
    }
    cin>>imeIPrezime>>brojKursevi;
    for (int i=0;i<brojKursevi;i++){
         cin>>ime>>krediti;
         kursevi[i]=Kurs(ime,krediti);
    }
    cin>>brojCasovi;

Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
cout<<"Objekt od klasata Demonstrator e kreiran";

} else if (tip==2) //funkcija pecati vo Student
{
    cout<<"-----TEST pecati-----"<<endl;
    cin>>indeks>>brojOcenki;
    for (int i=0;i<brojOcenki;i++){
         cin>>ocenka;
         ocenki[i]=ocenka;
    }

Student s(indeks,ocenki,brojOcenki);
s.pecati();

} else if (tip==3) //funkcija getVkupnaOcenka vo Student
{
     cout<<"-----TEST getVkupnaOcenka-----"<<endl;
    cin>>indeks>>brojOcenki;
    for (int i=0;i<brojOcenki;i++){
         cin>>ocenka;
         ocenki[i]=ocenka;
    }
    try {
        Student s(indeks,ocenki,brojOcenki);
        cout<<"Broj na bodovi: "<<s.getBodovi()<<endl;
    }catch(NoCourseException &n) {
        n.mssg();
    }

} else if (tip==4) //funkcija getVkupnaOcenka vo Demonstrator
{
  cout<<"-----TEST getVkupnaOcenka-----"<<endl;
  cin>>indeks>>brojOcenki;
    for (int i=0;i<brojOcenki;i++){
         cin>>ocenka;
         ocenki[i]=ocenka;
    }
    cin>>imeIPrezime>>brojKursevi;
    for (int i=0;i<brojKursevi;i++){
         cin>>ime>>krediti;
         kursevi[i]=Kurs(ime,krediti);
    }
    cin>>brojCasovi;
try {
    Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
    cout<<"Broj na bodovi: "<<d.getBodovi()<<endl;
}catch(NoCourseException &n) {
    n.mssg();
}
} else if (tip==5) //funkcija pecati vo Demonstrator
{
  cout<<"-----TEST pecati -----"<<endl;
 cin>>indeks>>brojOcenki;
    for (int i=0;i<brojOcenki;i++){
         cin>>ocenka;
         ocenki[i]=ocenka;
    }
    cin>>imeIPrezime>>brojKursevi;
    for (int i=0;i<brojKursevi;i++){
         cin>>ime>>krediti;
         kursevi[i]=Kurs(ime,krediti);
    }
    cin>>brojCasovi;

Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
d.pecati();

} else if (tip==6) //site klasi
{
    cout<<"-----TEST Student i Demonstrator-----"<<endl;
 cin>>indeks>>brojOcenki;
    for (int i=0;i<brojOcenki;i++){
         cin>>ocenka;
         ocenki[i]=ocenka;
    }
    cin>>imeIPrezime>>brojKursevi;
    for (int i=0;i<brojKursevi;i++){
         cin>>ime>>krediti;
         kursevi[i]=Kurs(ime,krediti);
    }
    cin>>brojCasovi;

Student *s=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
s->pecati();
cout<<"\nBroj na bodovi: "<<s->getBodovi()<<endl;
delete s;


} else if (tip==7) //funkcija vratiNajdobroRangiran
{
    cout<<"-----TEST vratiNajdobroRangiran-----"<<endl;
int k, opt;
cin>>k;
Student **studenti=new Student*[k];
for (int j=0;j<k;j++){
    cin>>opt; //1 Student 2 Demonstrator
      cin>>indeks>>brojOcenki;
   for (int i=0;i<brojOcenki;i++)
      {
         cin>>ocenka;
         ocenki[i]=ocenka;
      }
   if (opt==1){
    studenti[j]=new Student(indeks,ocenki,brojOcenki);
   }else{
   cin>>imeIPrezime>>brojKursevi;
    for (int i=0;i<brojKursevi;i++)
      {
         cin>>ime>>krediti;
         kursevi[i]=Kurs(ime,krediti);
      }
      cin>>brojCasovi;
   studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
   }
}
Student& najdobar=vratiNajdobroRangiran(studenti,k);
cout<<"Maksimalniot broj na bodovi e:"<<najdobar.getBodovi();
cout<<"\nNajdobro rangiran:";
najdobar.pecati();

for (int j=0;j<k;j++) delete studenti[j];
 delete [] studenti;

} else if (tip==8) //funkcija pecatiDemonstratoriKurs
{
cout<<"-----TEST pecatiDemonstratoriKurs-----"<<endl;
int k, opt;
cin>>k;
Student **studenti=new Student*[k];
for (int j=0;j<k;j++){
    cin>>opt; //1 Student 2 Demonstrator
      cin>>indeks>>brojOcenki;
   for (int i=0;i<brojOcenki;i++)
      {
         cin>>ocenka;
         ocenki[i]=ocenka;
      }
   if (opt==1){
    studenti[j]=new Student(indeks,ocenki,brojOcenki);
   }else{
   cin>>imeIPrezime>>brojKursevi;
    for (int i=0;i<brojKursevi;i++)
      {
         cin>>ime>>krediti;
         kursevi[i]=Kurs(ime,krediti);
      }
      cin>>brojCasovi;
   studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
   }
}
char kurs[20];
cin>>kurs;
cout<<"Demonstratori na "<<kurs<<" se:"<<endl;
pecatiDemonstratoriKurs (kurs,studenti,k);
for (int j=0;j<k;j++) delete studenti[j];
 delete [] studenti;

}


return 0;
}

