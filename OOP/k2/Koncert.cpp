#include<iostream>
#include<cstring>
using namespace std;

class Koncert {
protected:
    char ime[20];
    char loc[20];
    static float sezonskiPopustt;
    int rd;
    float cenaa;
public:
    Koncert(){}
    Koncert(const char ime[], const char loc[],float cena) {
        strcpy(this->ime,ime);
        strcpy(this->loc,loc);
        this->cenaa=cena;
    }
    static void setSezonskiPopust(float sezonskiPopust) {
        sezonskiPopustt=sezonskiPopust;
    }
    static float getSezonskiPopust() {
        return sezonskiPopustt;
    }
    char *getNaziv() {
        return this->ime;
    }
   virtual float cena() {
        float s=cenaa;
        s-=cenaa*(sezonskiPopustt/100);
        return s;
    }
};
class ElektronskiKoncert : public Koncert {
private:
    char *Djname;
    float vremetraenje;
    bool dnevna;
public:
    ElektronskiKoncert():Koncert(){}
    ElektronskiKoncert(char *ime,char *loc,float cenaa,char *Djname,float vremetraenje,bool dnevna=true):Koncert(ime,loc,cenaa) {
        this->vremetraenje=vremetraenje;
        this->dnevna=dnevna;
        this->Djname=new char[strlen(Djname)+1];
        strcpy(this->Djname,Djname);
    }
    ElektronskiKoncert(const ElektronskiKoncert &e):Koncert(e) {
        this->vremetraenje=e.vremetraenje;
        this->dnevna=e.dnevna;
        this->Djname=new char[strlen(e.Djname)+1];
        strcpy(this->Djname,e.Djname);
    }
    ElektronskiKoncert& operator=(const ElektronskiKoncert &e) {
        if(this!=&e) {
            delete [] this->Djname;
            this->vremetraenje=e.vremetraenje;
            this->dnevna=e.dnevna;
            this->Djname=new char[strlen(e.Djname)+1];
            strcpy(this->Djname,e.Djname);
        }
        return *this;
    }
    ~ElektronskiKoncert() {
        delete[] this->Djname;
    }
    float cena() override {
        float s=Koncert::cena();
        if(vremetraenje>5 && vremetraenje<7) {
            s+=150;
        }else if(vremetraenje>7) {
            s+=360;
        }
        if(dnevna) {
            s-=50;
        }else {
            s+=100;
        }
        return s;
    }
};
void najskapKoncert(Koncert** koncerti,int n) {
    float najskap=0;
    int counter=0;
    int elektronski=0;
    int indeksNajskap=0;
    for(int i=0;i<n;i++) {
        counter++;
        if(koncerti[i]->cena()>najskap) {
            najskap=koncerti[i]->cena();
            indeksNajskap=i;
        }
        if(dynamic_cast<ElektronskiKoncert*>(koncerti[i])) {
            elektronski++;
        }
    }
    cout<<"Najskap koncert: "<<koncerti[indeksNajskap]->getNaziv()<<" ";
    cout<<koncerti[indeksNajskap]->cena()<<endl;
    cout<<"Elektronski koncerti: "<<elektronski<<" od vkupno "<<counter<<endl;
}
bool prebarajKoncert(Koncert **koncerti,int n,char *ime,bool elektronski) {
    int counter=0;
        for(int i=0;i<n;i++) {
            if(elektronski) {
                if(dynamic_cast<ElektronskiKoncert*>(koncerti[i])) {
                    if(strcmp(koncerti[i]->getNaziv(),ime)==0) {
                         cout<<koncerti[i]->getNaziv()<<" ";
                         cout<<koncerti[i]->cena()<<endl;
                        counter++;
                    }
                }
            }
            else{
                if(strcmp(koncerti[i]->getNaziv(),ime)==0) {
                    cout<<koncerti[i]->getNaziv()<<" ";
                    cout<<koncerti[i]->cena()<<endl;
                    counter++;
                }
            }
        }
    if(counter>0) {
        return true;
    }else {
        return false;
    }
}
float Koncert::sezonskiPopustt = 20;
int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
        	najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
            bool elektronski;
        	cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

            if(prebarajKoncert(koncerti,5, "Area",!elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

        }
        else if (tip==8){//smeni cena
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(0.9);
        	najskapKoncert(koncerti,4);
        }

    return 0;
}
