#include<iostream>
#include<string.h>
using namespace std;
class OutOfBoundException {
    public:
    void mssg() {
        cout<<"Brojot na pin kodovi ne moze da go nadmine dozvolenoto"<<endl;
    }
};
class Karticka{
protected:
    char smetka[16];
    int pin;
    bool povekjePin;
    static int p;
public:
    Karticka() {}
    Karticka(char* smetka,int pin){
        strcpy(this->smetka,smetka);
        this->pin=pin;
        this->povekjePin=false;
    }
    // дополниете ја класата
    bool getDopolnitelenPin() {
        return this->povekjePin;
    }
    friend ostream&operator<<(ostream& os,Karticka& k){
        os<<k.smetka<<": "<<k.tezinaProbivanje();
        return os;
    }
    char *getSmetka() {
        return smetka;
    }
    virtual int tezinaProbivanje() {
        int t = 0, tmp = pin;
        if(tmp==0) {
            return 1;
        }
        while (tmp) {
            t++;
            tmp /= 10;
        }
        return t;
    }

};

class SpecijalnaKarticka : public Karticka {
private:
    int *dopolnitelenpin;
    int broj;
public:
    SpecijalnaKarticka(){}
    SpecijalnaKarticka(char* smetka,int pin):Karticka(smetka,pin) {
        dopolnitelenpin=new int[0];
        broj=0;
        povekjePin=true;
    }
    SpecijalnaKarticka(const SpecijalnaKarticka& karticka):Karticka(karticka) {
        this->broj=karticka.broj;
        this->dopolnitelenpin=new int[broj];
        for(int i=0;i<broj;i++) {
            this->dopolnitelenpin[i]=karticka.dopolnitelenpin[i];
        }
    }
    SpecijalnaKarticka& operator=(const SpecijalnaKarticka& karticka) {
        if(this!=&karticka) {
            delete [] this->dopolnitelenpin;
            this->broj=karticka.broj;
            this->dopolnitelenpin=new int[broj];
            for(int i=0;i<broj;i++) {
                this->dopolnitelenpin[i]=karticka.dopolnitelenpin[i];
            }
            this->pin=karticka.pin;
            this->povekjePin=true;
            strcpy(this->smetka,karticka.smetka);
        }
        return *this;
    }
    ~SpecijalnaKarticka() {
        delete [] this->dopolnitelenpin;
    }
    SpecijalnaKarticka &operator+=(int pin) {
            if(broj>=p) {
             throw OutOfBoundException();
            }
        int *temp=new int[broj+1];
        for(int i=0;i<broj;i++) {
            temp[i]=dopolnitelenpin[i];
        }
        temp[broj++]=pin;
        delete [] dopolnitelenpin;
        dopolnitelenpin=temp;
        return *this;
    }
    int tezinaProbivanje() override {
        return Karticka::tezinaProbivanje()+broj;
    }
};
int Karticka::p=4;


class Banka : public Karticka,public SpecijalnaKarticka {
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;
public:
    Banka(char *naziv, Karticka** karticki,int broj ){
        strcpy(this->naziv,naziv);
        for (int i=0;i<broj;i++){
            //ako kartickata ima dopolnitelni pin kodovi
            if (karticki[i]->getDopolnitelenPin()){
                this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i]));
            }
            else this->karticki[i]=new Karticka(*karticki[i]);
        }
        this->broj=broj;
    }
    ~Banka(){
        for (int i=0;i<broj;i++) delete karticki[i];
    }
    static void setLIMIT(int limit) {
        LIMIT=limit;
    }
    void pecatiKarticki(){
        cout<<"Vo bankata "<<naziv<<" moze da se probijat kartickite:"<<endl;
        for(int i=0;i<broj;i++) {
            if(karticki[i]->tezinaProbivanje()<=LIMIT) {
                cout<<*karticki[i]<<endl;
            }
        }
    }
    void dodadiDopolnitelenPin(char *smetka,int novPin) {
        for(int i=0;i<broj;i++) {
            if(strcmp(smetka,karticki[i]->getSmetka())==0) {
                SpecijalnaKarticka *spc=dynamic_cast<SpecijalnaKarticka*>(karticki[i]);
                if(spc) {
                    try {
                        spc+=novPin;
                    }catch(OutOfBoundException &e) {
                        e.mssg();
                    }
                }
            }
        }
    }
};
int Banka::LIMIT=7;


int main(){

    Karticka **niza;
    int n,m,pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin>>n;
    niza=new Karticka*[n];
    for (int i=0;i<n;i++){
        cin>>smetka;
        cin>>pin;
        cin>>daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i]=new Karticka(smetka,pin);
        else
            niza[i]=new SpecijalnaKarticka(smetka,pin);
    }

    Banka komercijalna("Komercijalna",niza,n);
    for (int i=0;i<n;i++) delete niza[i];
    delete [] niza;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>smetka>>pin;

        komercijalna.dodadiDopolnitelenPin(smetka,pin);

    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();

}
