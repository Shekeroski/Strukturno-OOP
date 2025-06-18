#include<iostream>
#include<cstring>
using namespace std;

class Potpisuvac {
private:
    char name[10];
    char surname[10];
    char embg[14];
public:
    Potpisuvac(){}
    Potpisuvac(char* n, char* s, char * e) {
        strcpy(name, n);
        strcpy(surname, s);
        strcpy(embg, e);
    }
    Potpisuvac(const Potpisuvac &p) {
        strcpy(name, p.name);
        strcpy(surname, p.surname);
        strcpy(embg, p.embg);
    }
    char* getembg() {
        return embg;
    }
};
class Dogovor {
    private:
    int br;
    char kategorija[50];
    Potpisuvac p[3];
public:
    Dogovor(){}
    Dogovor(int _br, char* k, Potpisuvac *_p) {
        br = _br;
        strcpy(kategorija, k);
        for (int i = 0; i < 3; i++) {
            p[i]=_p[i];
        }
    }
    bool proverka() {
        for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 3; j++) {
                if(strcmp(p[i].getembg(), p[j].getembg()) == 0) {
                    return true;
                }
                return false;
            }
        }
    }
};

int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
        Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
        if (d.proverka())
            cout << "Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}