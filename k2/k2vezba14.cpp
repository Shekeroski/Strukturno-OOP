#include <iostream>
using namespace std;
int najgolemaCifra(int broj, int &najgolema) {
    if (broj == 0) {
        return najgolema;
    }
    int posledna_cifra = broj % 10;
    if (posledna_cifra > najgolema) {
        najgolema = posledna_cifra;
    }                                               //najgolema cifra rekurzija
    return najgolemaCifra(broj / 10, najgolema);
}

int main() {
    int broj;
    cout << "Внесете број: ";
   while( cin >> broj) {
       int najgolema=0;
       int najgolemaa = najgolemaCifra(broj, najgolema);
       cout << "Најголемата цифра во бројот е: " << najgolema << endl;
   }
    return 0;
}