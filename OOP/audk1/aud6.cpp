#include<iostream>
#include<string>
using namespace std;

class Momche {
private:
string name;
    string prezime;
    int godini;
public:
    Momche(){}
    Momche(string namee, string prezimee, int godinii) {
        this->name=namee;
        this->prezime=prezimee;
        this->godini=godini;
    }
    ~Momche(){}
    void setName(string name) {
        this->name=name;
    }
    void setPrezime(string prezime) {
        this->prezime=prezime;
    }
    void setGodini(int godini) {
        this->godini=godini;
    }
    string getName() {
        return name;
    }
    string getPrezime() {
        return prezime;
    }
    int getGodini() {
        return godini;
    }
    void read() {
        cin>>name;
        cin>>prezime;
        cin>>godini;
    }
    void pecati() {
        cout<<"Momche: "<<name<<" "<<prezime<<" "<<godini<<endl;
    }
};
class Devojche {
private:
    string name;
    string prezime;
    int godini;
    public:
    Devojche(){}
    Devojche(string namee, string prezimee, int godinii) {
        this->name=namee;
        this->prezime=prezimee;
        this->godini=godinii;
    }
    ~Devojche(){}
    void setName(string name) {
        this->name=name;
    }
    void setPrezime(string prezime) {
        this->prezime=prezime;
    }
    void setGodini(int godini) {
        this->godini=godini;
    }
    string getName() {
        return name;
    }
    string getPrezime() {
        return prezime;
    }
    int getGodini() {
        return godini;
    }
    void read() {
        cin>>name;
        cin>>prezime;
        cin>>godini;
    }
    void pecati() {
        cout<<"Devojche: "<<name<<" "<<prezime<<" "<<godini<<endl;
    }
};
class Date {
private:
    Momche momche;
    Devojche devojche;
public:
    Date(){}
    Date(Momche mo, Devojche de) {
        this->momche=mo;
        this->devojche=de;
    }
    ~Date(){}
    void print() {
        cout<<"sredba:";
        momche.pecati();
        devojche.pecati();
    }
};
void siodgovaraat(Momche m, Devojche d) {
    if(m.getGodini()-d.getGodini()<=5) {
        cout<<"Si odgovaraat"<<endl;
    }
    else {
        cout<<" ne si odgovaraat"<<endl;
    }
}
int main() {
  Momche momche;
    Devojche devojche;
    momche.read();
    devojche.read();
    Date date(momche,devojche);
    date.print();
    siodgovaraat(momche,devojche);
    return 0;
}