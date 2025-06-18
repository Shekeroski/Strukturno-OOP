#include <iostream>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;
    int cifraB, i = 1, cifraA, temp;
    if (b > a) {
        temp = b;
        b = a;
        a = temp;
    }

    if (a <= 0 || b <= 0) { cout << "Invalid input"; }
    else if (a < 10 || b < 10) { cout << "NE"; }
    else {
        while (b != 0) {
            cifraB = b % 10;
            cifraA = a % 10;
            if (cifraB == cifraA && i % 2 == 0) {
                b /= 10;
            }
            else {
                a /= 10;
                i++;
            }
            if (a == 0) { break; }
        }
        if (b == 0) { cout << "PAREN"; }
        else { cout << "NE"; }
    }
    return 0;
}