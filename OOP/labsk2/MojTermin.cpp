#include<iostream>
#include<cstring>
using namespace std;

class Lekar {
protected:
    int faksimil;
    char ime[10];
    char prezime[10];
    double osn_plata;
    public:
    void copy(const Lekar &l) {
        faksimil = l.faksimil;
        strcpy(ime, l.ime);
        strcpy(prezime, l.prezime);
        osn_plata = l.osn_plata;
    }
    Lekar() {}
    Lekar(int faksimil,const char *ime="",const char *prezime="", double osn_plata=0) {
        this->faksimil=faksimil;
        strcpy(this->ime,ime);
        strcpy(this->prezime,prezime);
        this->osn_plata=osn_plata;
    }
    Lekar(const Lekar &l) {
        copy(l);
    }
    void pecati() {
        cout<<"faksimil: "<<ime<<" "<<prezime<<endl;
    }
    double platata() {
        return osn_plata;
    }
};
class MaticenLekar : public Lekar {
private:
    int br_pacienti;
    double *kotizacii;
    Lekar *lekari;
    public:
    MaticenLekar() {
        br_pacienti=0;
        kotizacii=NULL;
    }
    MaticenLekar(Lekar &l,int br_pacienti,double *kotizacii):Lekar(l) {
        this->br_pacienti=br_pacienti;
        this->kotizacii=new double[br_pacienti];
        for(int i=0;i<br_pacienti;i++) {
            this->kotizacii[i]=kotizacii[i];
        }
    }
    
    MaticenLekar(const MaticenLekar &l):Lekar(l) {
        br_pacienti=l.br_pacienti;
        kotizacii=new double[l.br_pacienti];
        for(int i=0;i<l.br_pacienti;i++) {
            this->kotizacii[i]=l.kotizacii[i];
        }
    }
    MaticenLekar& operator=(const MaticenLekar &l) {
        if(this!=&l) {
            delete [] kotizacii;
            copy(l);
            br_pacienti=l.br_pacienti;
            kotizacii=new double[l.br_pacienti];
            for(int i=0;i<l.br_pacienti;i++) {
                this->kotizacii[i]=l.kotizacii[i];
            }
        }
        return *this;
    }
    ~MaticenLekar() {
        delete [] kotizacii;
    }
    void pecati() {
        Lekar::pecati();
        cout<<"prosek na kotizacii: "<<kotizacija()<<endl;
    }
    double kotizacija() {
        double s=0;
        for(int i=0;i<br_pacienti;i++) {
            s+=this->kotizacii[i];
        }
        return s/br_pacienti;
    }
    double plata() {
        return Lekar::platata()+(0.3*kotizacija());
    }
};

int main()
{
    int n;
    cin >> n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime[20];
    char prezime[20];
    double osnovnaPlata;

    Lekar *lekari = new Lekar[n];
    MaticenLekar *maticni = new MaticenLekar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> faksimil >> ime >> prezime >> osnovnaPlata;
        lekari[i] = Lekar(faksimil, ime, prezime, osnovnaPlata);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> pacienti;
        for (int j = 0; j < pacienti; j++)
        {
            cin >> kotizacii[j];
        }
        maticni[i] = MaticenLekar(lekari[i], pacienti, kotizacii);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "===TESTIRANJE NA KLASATA LEKAR===" << endl;
        for (int i = 0; i < n; i++)
        {
            lekari[i].pecati();
            cout << "Osnovnata plata na gorenavedeniot lekar e: " << lekari[i].platata() << endl;
        }
    }
    else
    {
        cout << "===TESTIRANJE NA KLASATA MATICENLEKAR===" << endl;
        for (int i = 0; i < n; i++)
        {
            maticni[i].pecati();
            cout << "Platata na gorenavedeniot maticen lekar e: " << maticni[i].plata() << endl;
        }
    }

    delete[] lekari;
    delete[] maticni;

    return 0;
}