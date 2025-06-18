#include<iostream>
#include<cstring>
using namespace std;

class Rabotnik {
    private:
    char ime[10];
    char prezime[10];
    int plata;
    public:
    Rabotnik() {}
    Rabotnik(char* _ime, char* _prezime, int _plata) {
        strcpy(ime, _ime);
        strcpy(prezime, _prezime);
        plata = _plata;
    }
    Rabotnik(const Rabotnik& r) {
        strcpy(ime, r.ime);
        strcpy(prezime, r.prezime);
        plata = r.plata;
    }
    int getplata() const {
        return plata;
    }
    void pecati() {
        cout << ime << " " << prezime <<" "<<plata<< endl;
    }
};
class Fabrika {
    private:
    Rabotnik rabotnik[100];
    int br_vraboteni;
    public:
    Fabrika() {}
    Fabrika(Rabotnik *_rabotnik, int _br_vraboteni) {
        br_vraboteni = _br_vraboteni;
        for(int i=0;i<br_vraboteni;i++) {
            rabotnik[i] = _rabotnik[i];
        }
    }
    Fabrika(const Fabrika& f) {
        br_vraboteni = f.br_vraboteni;
        for(int i=0;i<br_vraboteni;i++) {
            rabotnik[i] = f.rabotnik[i];
        }
    }
    void print() {
        for(int i=0;i<br_vraboteni;i++) {
            rabotnik[i].pecati();
        }
    }
    int getbr_vrabotni() const {
        return br_vraboteni;
    }
   Rabotnik &getrabotnik(int i) {
        return rabotnik[i];
    }
};


int printSalary(int min,Fabrika fabrika) {
    cout<<"vraboteni so plata povisoka od: "<<min<<": "<<endl;
    for(int i=0;i<fabrika.getbr_vrabotni();i++) {
        if(fabrika.getrabotnik(i).getplata()>=min) {
            fabrika.getrabotnik(i).pecati();
        }
    }
}

int main() {
    int n;
    int salary;
    int min;
    char name[30];
    char surname[30];
    Rabotnik r[100];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> surname >> salary;
        r[i] = Rabotnik(name, surname, salary);
    }
    cin >> min;

    Fabrika f(r, n);

    f.print();
    printSalary(min,f);

    return 0;
}