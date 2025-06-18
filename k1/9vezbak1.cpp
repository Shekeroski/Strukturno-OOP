#include <iostream>
using namespace std;
int main() {
    int broj;
    cout << "Unesite broj: ";
    cin >> broj;

    while (broj >= 10) { // Dokle god broj ima dve ili više cifara
        int poslednja_cifra = broj % 10; // Uzmi poslednju cifru
        int pretposlednja_cifra = (broj / 10) % 10; // Uzmi pretposlednju cifru
        int zbir = poslednja_cifra + pretposlednja_cifra; // Izračunaj zbir

        // Ukloni poslednje dve cifre i dodaj zbir
        if(zbir>=10) {
            broj=broj/100 * 100 +zbir;
        }
        if (zbir<=9) {
            broj = broj / 100 * 10 + zbir;
        }
        // Ukloni poslednje dve cifre i dodaj zbir

        cout << broj << endl; // Ispisi novi broj
    }


    return 0; // Završava program
}