#include<iostream>
#include<cstring>
using namespace std;
class Transport {
protected:
    char destinacija[10];
    int osnovnaCena;
    float rastojanie;
public:
    Transport(char *destinacija,int osnovnaCena=0,float rastojanie=0.0) {
        strcpy(this->destinacija,destinacija);
        this->osnovnaCena=osnovnaCena;
        this->rastojanie=rastojanie;
    }
    virtual float cenaTransport()=0;
    bool operator<(const Transport &t) {
        return this->rastojanie<t.rastojanie;
    }
    float getRastojanie() {
        return this->rastojanie;
    }
    int getOsnovnaCena() {
        return this->osnovnaCena;
    }
    char *getDestinacija() {
        return this->destinacija;
    }
};
class AvtomobilTransport : public Transport {
private:
    bool platensofer;
public:
    AvtomobilTransport(char *destinacija,int osnovnaCena=0,float rastojanie=0.0,bool platensofer=false): Transport(destinacija,osnovnaCena,rastojanie) {
        this->platensofer=platensofer;
    }
    float cenaTransport()override {
        if(platensofer) {
            return osnovnaCena+=osnovnaCena*0.20;
        }else {
            return osnovnaCena;
        }
    }
};
class KombeTransport : public Transport {
private:
    int brLjudze;
public:
    KombeTransport(char *destinacija,int osnovnaCena=0,float rastojanie=0.0,int brLjudze=0): Transport(destinacija,osnovnaCena,rastojanie) {
        this->brLjudze=brLjudze;
    }
   float cenaTransport()override {
        osnovnaCena-=(brLjudze*200);
        return osnovnaCena;
    }
};
void pecatiPoloshiPonudi(Transport **transport,int n,Transport &t) {
int count=0;
    Transport *temp[n];
    for(int i=0;i<n;i++) {
       if(transport[i]->cenaTransport()>t.cenaTransport()) {
           temp[count++]=transport[i];
       }
    }
    for(int i=0;i<count-1;i++) {
        for(int j=i+1;j<count;j++) {
            if(temp[i]->getRastojanie()>temp[j]->getRastojanie()) {
                swap(temp[i],temp[j]);
            }
        }
    }
    for(int i=0;i<count;i++) {
        cout<<temp[i]->getDestinacija()<<" ";
        cout<<temp[i]->getRastojanie()<<" ";
        cout<<temp[i]->getOsnovnaCena()<<endl;
    }
}
int main(){

    char destinacija[20];
    int tip,cena,rastojanie,lugje;
    bool shofer;
    int n;
    cin>>n;
    Transport  **ponudi;
    ponudi=new Transport *[n];

    for (int i=0;i<n;i++){

        cin>>tip>>destinacija>>cena>>rastojanie;
        if (tip==1) {
            cin>>shofer;
            ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

        }
        else {
            cin>>lugje;
            ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
        }


    }

    AvtomobilTransport nov("Ohrid",2000,600,false);
    pecatiPoloshiPonudi(ponudi,n,nov);

    for (int i=0;i<n;i++) delete ponudi[i];
    delete [] ponudi;
    return 0;
}
