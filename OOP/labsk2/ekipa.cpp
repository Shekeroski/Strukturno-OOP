#include <iostream>
#include<cstring>

using namespace std;

class Ekipa
{
protected:
    char ime[10];
    int porazi;
    int pobedi;
public:
    void pecati()
    {
        cout << "Ime: " << ime <<endl;
        cout<<" Pobedi: " << pobedi <<endl;
        cout<<" Porazi: " << porazi;
    }
    Ekipa(const char* ime="",const int porazi=0,const int pobedi=0) {
        this->porazi = porazi;
        this->pobedi = pobedi;
        strcpy(this->ime, ime);
    }
};
class FudbalskaEkipa : public Ekipa
{
private:
    int crveni;
    int zolti;
    int nereseni;
public:
    FudbalskaEkipa(char *ime,int pobedi,int porazi, int crveni=0, int zolti=0, int nereseni=0):Ekipa(ime,pobedi,porazi){
        this->crveni = crveni;
        this->zolti = zolti;
        this->nereseni = nereseni;
    }

    void pecati()
    {
        Ekipa::pecati();
        cout << " Nereseni: " << nereseni << " Poeni: " << pobedi * 3 + nereseni << endl;
    }
};

int main()
{
    char ime[10];
    int pob, por, ck, zk, ner;
    cin >> ime >> pob >> por >> ck >> zk >> ner;
    FudbalskaEkipa f1(ime, por, pob, ck, zk, ner);
    f1.pecati();
    return 0;
}