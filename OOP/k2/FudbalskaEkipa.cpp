#include <iostream>
#include<cstring>
using namespace std;

class FudbalskaEkipa {
protected:
    char name[100];
    int golovi[10];
public:
    FudbalskaEkipa() {
    }
    FudbalskaEkipa(char *name,int *golovi) {
        strcpy(this->name,name);
        for(int i=0;i<10;i++) {
            this->golovi[i]=golovi[i];
        }
    }
    virtual int uspeh()const=0;
    virtual void pecati(ostream &os)const=0;
    bool operator > (const FudbalskaEkipa &other2 ) {
        return this->uspeh()>other2.uspeh();
    }
    FudbalskaEkipa &operator+=(int golovi) {
        int p;
        for(int i=0;i<9;i++) {
            this->golovi[i]=this->golovi[i+1];
        }
        this->golovi[9]=golovi;
        return *this;
    }
};
class Klub:public FudbalskaEkipa {
private:
    char ime[20];
    int brtituli;
public:
    Klub(char *name,int *golovi,char *ime,int brtituli):FudbalskaEkipa(name,golovi) {
        strcpy(this->ime,ime);
        this->brtituli=brtituli;
    }
    int uspeh() const override {
        int s=0;
        for(int i=0;i<10;i++) {
            s+=golovi[i];
        }
        s*=3;
        s+=brtituli*1000;
        return s;
    }
    void pecati(ostream &os)const override {
        os <<ime<<endl;
        os<<name<<endl;
        os<<uspeh()<<endl;
    }
    Klub &operator+=(int golovi) {
        int p;
        for(int i=0;i<9;i++) {
            this->golovi[i]=this->golovi[i+1];
        }
        this->golovi[9]=golovi;
        return *this;
    }
};
class Reprezentacija:public FudbalskaEkipa {
private:
    char imedrzava[20];
    int nastani;
public:
    Reprezentacija(char *name,int *golovi,char *imedrzava,int nastani):FudbalskaEkipa(name,golovi) {
        strcpy(this->imedrzava,imedrzava);
        this->nastani=nastani;
    }
    int uspeh() const override{
        int s=0;
        for(int i=0;i<10;i++) {
            s+=golovi[i];
        }
        s*=3;
        s+=nastani*50;
        return s;
    }
    void pecati(ostream &os)const override {
        os <<imedrzava<<endl;
        os<<name<<endl;
        os<<uspeh()<<endl;
    }
    Reprezentacija &operator+=(int golovi) {
        for(int i=0;i<9;i++) {
            this->golovi[i]=this->golovi[i+1];
        }
        this->golovi[9]=golovi;
        return *this;
    }
};
ostream& operator<<(ostream& os, const FudbalskaEkipa& ekipa) {
    ekipa.pecati(os);
    return os;
}
void najdobarTrener(FudbalskaEkipa **f,int n) {
    FudbalskaEkipa * temp= f[0];
    for(int i=0;i<n;i++) {
        if(*f[i]>*temp) {
            temp=f[i];
        }
    }
   cout<<*temp;
}
int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}