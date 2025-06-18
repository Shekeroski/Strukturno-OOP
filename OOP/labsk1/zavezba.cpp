#include<iostream>
#include<cstring>
using namespace std;

class Datum {
private:
    int den;
    int mesec;
    int godina;
public:
    Datum() {}
    Datum(int d, int m, int g) {
        den = d;
        mesec = m;
        godina = g;
    }
    ~Datum() {}
    void setDen(int d) {
        den = d;
    }
    void setMesec(int m) {
        mesec = m;
    }
    void setGodina(int g) {
        godina = g;
    }
    int getDen() {
        return den;
    }
    int getMesec() {
        return mesec;
    }
    int getGodina() {
        return godina;
    }
};

class Vraboten {
private:
    char name[10];
    int plata;
    Datum datum;
public:
    Vraboten() {}
    Vraboten(char *n, int p,const Datum &d) {
      strcpy(name, n);
        plata = p;
        datum = d;
    }
    ~Vraboten() {}
    void setName(char *n) {
        strcpy(name, n);
    }
    void setDatum(const Datum &d) {
        datum = d;
    }
    void setPlata(int p) {
        plata = p;
    }
    Datum getDatum() {
        return datum;
    }
    int getPlate() {
        return plata;
    }
    char *getName() {
        return name;
    }

    Vraboten najgolemaplata(Vraboten *v, int n) {
        int max=0;
        int idx;
        for(int i=0;i<n;i++) {
            if(v[i].getPlate() > max ) {
                max=v[i].getPlate();
                idx=i;
            }
        }
        return v[idx];
    }
    int sporedba(Datum d1, Datum d2) {
        if (d1.getGodina() > d2.getGodina()) return 1;
        else if (d1.getGodina() < d2.getGodina()) return 2;
        else if (d1.getMesec() > d2.getMesec()) return 1;
        else if (d1.getMesec() < d2.getMesec()) return 2;
        else if (d1.getDen() > d2.getDen()) return 1;
        else if (d1.getDen() < d2.getDen()) return 2;
        else return 0;
    }
    //go vrakja najmladiot vraboten od nizata v
    Vraboten najmlad(Vraboten v[], int n) {
        Datum data(v[0].getDatum());
        int ind = 0;
        for (int i = 1; i < n; i++) {
            if (sporedba(v[i].getDatum(), data) == 1) {
                data = v[i].getDatum();
                ind = i;
            }
        }
        return v[ind];
    }
};

int main() {
     Datum d1(1, 1, 1980);
     Datum d2(1, 2, 1983);
     Datum d3(11, 12, 1984);

     Vraboten v[3];
     Vraboten v1("Marjan", 40000, d1);
     Vraboten v2("Stefan", 30000, d2);
     Vraboten v3("Marko", 20000, d3);
     v[0] = v1;   v[1] = v2;   v[2] = v3;

     cout << "Najmlad vraboten: " << endl;
     najmlad(v, 3).print();

     cout << "Vraboten so najgolema plata: " << endl;
     najgolemPlata(v, 3).print();

     return 0;
 }