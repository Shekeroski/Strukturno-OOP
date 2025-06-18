#include<iostream>
#include<cstring>
using namespace std;

class Nedviznina {
protected:
    char *adresa;
    int kvadratura;
    int cena;
    void copy(const Nedviznina &n) {
        this->adresa=new char[strlen(n.adresa)+1];
        strcpy(this->adresa,n.adresa);
        this->kvadratura=n.kvadratura;
        this->cena=n.cena;
    }
    public:
     Nedviznina(const char *adresa="",int kvadratura=0, int cena=0) {
        this->adresa=new char[strlen(adresa)+1];
        strcpy(this->adresa,adresa);
        this->kvadratura=kvadratura;
        this->cena=cena;
    }
    Nedviznina(const Nedviznina &n) {
        copy(n);
    }
    Nedviznina &operator=(const Nedviznina &n) {
        if(this!=&n) {
            delete [] this->adresa;
            copy(n);
        }
        return *this;
    }
    ~Nedviznina() {
        delete [] this->adresa;
    }
    int cenaa() {
        return this->cena*kvadratura;
    }
    char *getAdresa() {
        return this->adresa;
    }
     int danokNaImot() {
        return cenaa()*0.05;
    }
    void pecati() {
        cout<<"Nedviznina: "<<this->adresa<<endl;
        cout<<"kvadratura: "<<this->kvadratura<<endl;
        cout<<"cena: "<<this->cena<<endl;
    }
    friend istream &operator>>(istream &CIN, Nedviznina &n) {
        char buff[10];
         CIN>>buff;
         delete [] n.adresa;
         n.adresa=new char[strlen(buff)+1];
         strcpy(n.adresa,buff);
        CIN>>n.kvadratura>>n.cena;
        return CIN;
    }
};
class Vila : public Nedviznina {
private:
   int danok_luksuz;
public:
     Vila(const char *adresa="",int kvadratura=0,int cena=0,int danok_luksuz=0): Nedviznina(adresa,kvadratura,cena ) {
        this->danok_luksuz=danok_luksuz;
    }
    int danokNaImot() {
         int s=0;
        s += cenaa()*danok_luksuz;
         return s;
    }
    friend istream &operator>>(istream &CIN, Vila &n) {
         char buff[10];
         CIN>>buff;
         delete [] n.adresa;
         n.adresa=new char[strlen(buff)+1];
         strcpy(n.adresa,buff);
         CIN >> n.kvadratura >> n.cena>>n.danok_luksuz;
         return CIN;
     }
    void pecati() {
         Nedviznina::pecati();
         cout<<danok_luksuz<<endl;
     }
};
int main()
{
    Nedviznina n;
    Vila v;
    cin >> n;
    cin >> v;
    n.pecati();
    cout << "Danok za: " << n.getAdresa() << ", e: " << n.danokNaImot() << endl;
    v.pecati();
    cout << "Danok za: " << v.getAdresa() << ", e: " << v.danokNaImot() << endl;
    return 0;
}