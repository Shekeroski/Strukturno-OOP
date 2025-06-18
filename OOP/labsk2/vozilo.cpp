#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class vozilo {
protected:
    float masa;
    int sirina;
    int visina;
public:
    virtual int vratiDnevnaCena()=0;
    vozilo(){}
    vozilo(float masa, int sirina, int visina) {
        this->masa = masa;
        this->sirina = sirina;
        this->visina = visina;
    }
    float getmasa() {
        return masa;
    }
    int getsirina() {
        return sirina;
    }
};
class Avtomobil : public vozilo {
private:
    int br_vrati;
public:
    Avtomobil() {}
    Avtomobil(float masa, int sirina, int visina,int br_vrati) : vozilo(masa,sirina,visina) {
        this->br_vrati = br_vrati;
    }
    int vratiDnevnaCena() {
        if(br_vrati<5) {
            return 100;
        }else {
            return 130;
        }
    }
};
class Avtobus : public vozilo {
    private:
    int br_patnici;
    public:
    Avtobus() {}
    Avtobus(float masa, int sirina, int visina,int br_patnici): vozilo(masa,sirina,visina) {
        this->br_patnici = br_patnici;
    }
    int vratiDnevnaCena() {
        return 5*br_patnici;
    }
};
class Kamion : public vozilo {
private:
    float maks_masa;
public:
    Kamion() {}
    Kamion(float masa, int sirina, int visina,float maks_masa): vozilo(masa,sirina,visina) {
        this->maks_masa = maks_masa;
    }
    int vratiDnevnaCena() {
        return (masa*maks_masa)*0.02;
    }
};
class ParkingPlac {
    private:
    vozilo **Vozilo;
    int n;
public:
    ParkingPlac() {
        Vozilo = new vozilo*[0];
        n=0;
    }
    ~ParkingPlac() {
        delete [] Vozilo;
    }
    ParkingPlac &operator+=(vozilo *v) {
        vozilo **temp = new vozilo*[n+1];
        for(int i=0; i<n; i++) {
            temp[i]=Vozilo[i];
        }
        temp[n]=v;
        delete [] Vozilo;
        Vozilo = temp;
        n++;
        return *this;
    }
    float presmetajVkupnaMasa() {
        double s=0;
        for(int i=0; i<n; i++) {
            s+=Vozilo[i]->getmasa();
        }
        return s;
    }
    int brojVozilaPoshirokiOd(int l) {
        int s=0;
        for(int i=0; i<n; i++) {
            if(Vozilo[i]->getsirina() > l) {
                s++;
            }
        }
        return s;
    }
    void pecati() {
        int avtomobili=0;
        int avtobusi=0;
        int kamioni=0;
        for(int i=0; i<n; i++) {
            if(dynamic_cast<Avtomobil *>(Vozilo[i])) {
                avtomobili++;
            }
            else if(dynamic_cast<Avtobus *>(Vozilo[i])) {
                avtobusi++;
            }
            else if(dynamic_cast<Kamion *>(Vozilo[i])) {
                kamioni++;
            }
        }
        cout<<"Brojot na avtomobili e: "<<avtomobili<<endl;
        cout<<"Brojot na avtobusi e: "<<avtobusi<<endl;
        cout<<"Brojot na kamioni e: "<<kamioni<<endl;
    }
    int pogolemaNosivostOd(vozilo &v) {
        int s=0;
        for(int i=0; i<n; i++) {
            if(dynamic_cast<Kamion *>(Vozilo[i]) && Vozilo[i]->getmasa()>v.getmasa()) {
                s++;
            }
        }
        return s;
    }
    int vratiDnevnaZarabotka() {
        int s=0;
        for(int i=0; i<n; i++) {
            s+=Vozilo[i]->vratiDnevnaCena();
        }
        return s;
    }
};
int main()
{
    ParkingPlac p;

    int n;
    cin >> n;
    int shirina, visina, broj;
    float masa, nosivost;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cin >> masa >> shirina >> visina >> broj;
            Avtomobil *a = new Avtomobil(masa, shirina, visina, broj);
            p += a;
        }
        if (type == 2)
        {
            cin >> masa >> shirina >> visina >> broj;
            p += new Avtobus(masa, shirina, visina, broj);
        }
        if (type == 3)
        {
            cin >> masa >> shirina >> visina >> nosivost;
            p += new Kamion(masa, shirina, visina, nosivost);
        }
    }

    p.pecati();

    cout << "\nZarabotkata e " << p.vratiDnevnaZarabotka() << endl;
    cout << "Vkupnata masa e " << p.presmetajVkupnaMasa() << endl;
    cout << "Brojot poshiroki od 5 e " << p.brojVozilaPoshirokiOd(5) << endl;
    Avtomobil a(1200, 4, 3, 5);
    cout << "Brojot na kamioni so nosivost pogolema od avtomobilot e " << p.pogolemaNosivostOd(a) << endl;
}