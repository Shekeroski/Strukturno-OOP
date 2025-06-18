#include <iostream>
#include <cstring>
using namespace std;
enum Type {
    FAILED=0,PARTIAL,SUCCESS
};
class Satellite {
    char name[51];
    char country[51];
public:
    Satellite(const char *name="", const char *country="") {
        strcpy(this->name,name);
        strcpy(this->country,country);
    }
    void print() const {
        cout<<name<<" ("<<country<<")"; //ne endl oti mora vo Mission vo ista linija ushte neshto
    }
};
class Mission {
    Satellite s;
    char name[11];
    char date[11]; //vo format dd.mm.yyyy, ne e bitno sho ima tochki, bitno da nema prazno mesto
    int memory; //vo terabajti
    Type type; //0 ako e failed, 1 ako e partial, 2 ako e success
public:
    Mission(Satellite s={}, const char *name="", const char *date="", int memory=0, int type=0) { //pozhelno e tuka casting na type vo int prom.
        this->s=s;
        strcpy(this->name,name);
        strcpy(this->date,date);
        this->memory=memory;
        this->type=(Type)type; //mora desnovo da go vratime vo Type nazad, oti inache kje ostane int kako vo arg. posleden
    }
    void print() const {
        cout<<"Mission name: "<<name<<endl;
        cout<<"Satellite: ";
        s.print();
        cout<<" with memory: "<<memory<<"TB"<<endl;
        cout<<"Mission's date at: "<<date<<" Status: ";
        if (type==FAILED) {
            cout<<"Failed";
        }else if (type==PARTIAL) {
            cout<<"Partial";
        }else {
            cout<<"Success";
        }
        cout<<endl;
    }
};
int main() {
    int n;
    cin>>n;
    char name[11],date[11],namee[51],country[51];
    int memory;
    int type;
    Mission m[100];
    for (int i=0;i<n;i++) {
        cin>>name>>date; //imeto i datumot na misijata
        cin.ignore(); //za ako treba nov red za narednive 2
        cin.getline(namee,51);
        cin.getline(country,51); //edno do drugo se vnesuvaat, i + ima prazni mesta i vo namee i vo country, mora so getline
        cin>>memory>>type; //obichni integers
        Satellite s=Satellite(namee,country);
        m[i]=Mission(s,name,date,memory,type);
        m[i].print();
    }
    return 0;
}