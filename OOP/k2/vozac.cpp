#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Vozac {
protected:
    char name[20];
    int age;
    int numberofRaces;
    bool daliVeteran;
public:
    Vozac() {}
    Vozac(char* name, int age, int numberofRaces,bool daliVeteran) {
        strcpy(this->name, name);
        this->age = age;
        this->numberofRaces = numberofRaces;
        this->daliVeteran = daliVeteran;
    }
    friend ostream& operator<<(ostream&COUT,const Vozac &V) {
        COUT<<"Name: "<<V.name<<endl;
        COUT<<"Age: "<<V.age<<endl;
        COUT<<"Number of Races: "<<V.numberofRaces<<endl;
        if(V.daliVeteran) {
            COUT<<"Veteran "<<endl;
        }
        return COUT;
    }
    virtual float zarabotuvacka()const =0;
    virtual float danok()const =0;
    bool operator==(const Vozac &v) const{
     return this->zarabotuvacka()==v.zarabotuvacka();
    }
    ~Vozac() {}
};
class Avtomobilist : public Vozac {
private:
    float cenaNaAvtomobil;
public:
    Avtomobilist(char *name,int age,int trki,bool vet,float cenaNaAvtomobil):Vozac(name,age,trki,vet) {
        this->cenaNaAvtomobil = cenaNaAvtomobil;
    }
    float zarabotuvacka() const override{
        return cenaNaAvtomobil/5.0;
    }
    float danok()const override {
        if(numberofRaces>10) {
            return 0.15*zarabotuvacka();
        }else {
            return 0.10*zarabotuvacka();
        }
    }
};
class Motociklist : public Vozac {
private:
    int mocnost;
public:
    Motociklist(char *name,int age,int trki,bool vet,int mocnost):Vozac(name,age,trki,vet) {
        this->mocnost = mocnost;
    }
     float zarabotuvacka() const override {
        return mocnost*20;
    }
    float danok()const override {
        if(daliVeteran) {
            return 0.25*zarabotuvacka();
        }else {
            return 0.20*zarabotuvacka();
        }
    }
};
int soIstaZarabotuvachka(Vozac **v,int n, Vozac * vz) {
    int count=0;
    for(int i=0;i<n;i++) {
        if(*v[i]==*vz) {
            count ++;
           cout<<*v[i]<<endl;
        }
    }
    return count;
}
int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}