#include<iostream>
#include<cstring>
using namespace std;
class Pizza {
private:
    char name[10];
    int cena;
    char sostojki[10];
    float namaluvanje_cena;
public:
    Pizza() {}
    Pizza(char *n, char *s, int n_cena, float n_namaluvanje) {
        strcpy(name, n);
        cena = n_cena;
        namaluvanje_cena = n_namaluvanje;
        strcpy(sostojki, s);
    }
    Pizza(const Pizza &p) {
        strcpy(name, p.name);
        cena = p.cena;
        strcpy(sostojki, p.sostojki);
        namaluvanje_cena = p.namaluvanje_cena;
    }
    void pecati() {
        cout<<name<<" "<<sostojki<<" "<<cena<<endl;
    }
    bool IstiSe(const Pizza &other) {
        if(strcmp(sostojki, other.sostojki) == 0) {
            return false;
        }
        return true;
    }
};
class picerija {
    char name[10];
    Pizza *p;
    int brpici;
public:
    picerija() {}
    picerija(char *n, Pizza *_p, int n_piceri) {
        strcpy(name, n);
        brpici = n_piceri;
        p=_p;
    }
    picerija(const picerija &pi) {
        strcpy(name, pi.name);
        brpici = pi.brpici;
        p=pi.p;
    }
    void dodadipica(Pizza pica) {
        p[brpici++]=pica;
    }
};