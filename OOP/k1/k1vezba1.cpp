#include <iostream>
#include <cstring>

using namespace std;

enum TipPesna { POP, RAP, ROCK };

class Pesna {
private:
    char *ime;
    int minuti;
    TipPesna tip;

public:
    Pesna(const char *ime = "", int minuti = 0, TipPesna tip = POP) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->minuti = minuti;
        this->tip = tip;
    }

    Pesna(const Pesna &p) {
        this->ime = new char[strlen(p.ime) + 1];
        strcpy(this->ime, p.ime);
        this->minuti = p.minuti;
        this->tip = p.tip;
    }

    Pesna &operator=(const Pesna &p) {
        if (this != &p) {
            delete[] ime;
            this->ime = new char[strlen(p.ime) + 1];
            strcpy(this->ime, p.ime);
            this->minuti = p.minuti;
            this->tip = p.tip;
        }
        return *this;
    }

    ~Pesna() {
        delete[] ime;
    }

    void pecati() const {
        cout << "\"" << ime << "\"-" << minuti << "min" << endl;
    }

    int getMinuti() const {
        return minuti;
    }

    TipPesna getTip() const {
        return tip;
    }
};

class CD {
private:
    Pesna pesni[10];
    int broj;
    int maxMinuti;

public:
    CD(int maxMinuti = 0) {
        this->broj = 0;
        this->maxMinuti = maxMinuti;
    }

    int getBroj() const {
        return broj;
    }

    Pesna getPesna(int i) const {
        return pesni[i];
    }

    void dodadiPesna(Pesna p) {
        int vkupnoVreme = 0;
        for (int i = 0; i < broj; i++) {
            vkupnoVreme += pesni[i].getMinuti();
        }

        if (broj < 10 && (vkupnoVreme + p.getMinuti() <= maxMinuti)) {
            pesni[broj++] = p;
        }
    }

    void pecatiPesniPoTip(TipPesna t) const {
        for (int i = 0; i < broj; i++) {
            if (pesni[i].getTip() == t) {
                pesni[i].pecati();
            }
        }
    }
};

// ================== MAIN FUNKCIJA ====================
int main() {
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip;
        Pesna p(ime, minuti, (TipPesna)kojtip);
        p.pecati();
    }
    else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip;
            Pesna p(ime, minuti, (TipPesna)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            omileno.getPesna(i).pecati();
    }
    else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip;
            Pesna p(ime, minuti, (TipPesna)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            omileno.getPesna(i).pecati();
    }
    else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip;
            Pesna p(ime, minuti, (TipPesna)kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((TipPesna)kojtip);
    }
    else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip;
            Pesna p(ime, minuti, (TipPesna)kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((TipPesna)kojtip);
    }

    return 0;
}