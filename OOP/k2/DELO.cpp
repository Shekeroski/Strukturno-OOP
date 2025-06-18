#include<iostream>
#include<string.h>
using namespace std;
class Delo {
    char name[20];
    int godina;
    char zemja[20];
public:
    Delo(const char* name="",int godina=0,const char* zemja="") {
        strcpy(this->name,name);
        this->godina=godina;
        strcpy(this->zemja,zemja);
    }
    char* getIme() {
        return name;
    }
    int getGodina() {
        return godina;
    }
    char* getZemja() {
        return zemja;
    }
    void setName(const char* name) {
        strcpy(this->name,name);
    }
    void setGodina(int godina) {
        this->godina=godina;
    }
    void setZemja(const char* zemja) {
        strcpy(this->zemja,zemja);
    }
    bool operator==(const Delo &delo) {
        return strcmp(this->name,delo.name)==0;
    }
};
//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
class Pretstava {
protected:
    Delo delo;
    int brProdadeni;
    char dataPrikazuvanje[15];
public:
    Pretstava(Delo delo,int brProdadeni,char* dataPrikazuvanje) {
        this->delo=delo;
        this->brProdadeni=brProdadeni;
        strcpy(this->dataPrikazuvanje,dataPrikazuvanje);
    }
    Delo getDelo() {
        return delo;
    }
    int getBrProdadeni() {
        return brProdadeni;
    }
    char* getDataPrikazuvanje() {
        return dataPrikazuvanje;
    }
    void setDelo(Delo delo) {
        this->delo=delo;
    }
    void setBrProdadeni(int brProdadeni) {
        this->brProdadeni=brProdadeni;
    }
    void setDataPrikazuvanje(char* dataPrikazuvanje) {
        strcpy(this->dataPrikazuvanje,dataPrikazuvanje);
    }
    virtual float cena() {
        float s=0;
        if((delo.getGodina()/100)==19 || (delo.getGodina()/100)==20) {
            s=50;
        }else if((delo.getGodina()/100)==18) {
            s=75;
        }else if((delo.getGodina()/100)<18){
            s=100;
        }
        if((strcmp(delo.getZemja(),"Italija"))==0) {
            s+=100;
        }else if((strcmp(delo.getZemja(),"Rusija"))==0) {
            s+=150;
        }else {
            s+=80;
        }
        return s;
    }
};
class Balet:public Pretstava {
private:
    static int cenata;
public:
    Balet(Delo delo,int brProdadeni,char* dataPrikazuvanje):Pretstava(delo,brProdadeni,dataPrikazuvanje) {
    }
    static void setCenaBalet(int cenaa) {
        cenata=cenaa;
    }
    float cena() override{
        return Pretstava::cena()+cenata;
    }
};
int Balet::cenata=150;
class Opera:public Pretstava {
public:
    Opera(Delo delo,int brProdadeni,char* dataPrikazuvanje):Pretstava(delo,brProdadeni,dataPrikazuvanje){}
};
float prihod(Pretstava **p,int n) {
    float s=0;
    for(int i=0;i<n;i++) {
        s+=p[i]->getBrProdadeni()*p[i]->cena();

    }
    return s;
}
int brojPretstaviNaDelo(Pretstava **p,int n,Delo &delo) {
    int counter=0;
    for(int i=0;i<n;i++) {
        if(p[i]->getDelo()==delo) {
            counter++;
        }
    }
    return counter;
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;

    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;

    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();

        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

    }break;

    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();

        }
        cout<<prihod(pole,n);
    }break;

    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;

    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }

        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;

    };


return 0;
}
