#include <iostream>
using namespace std;

int parcom(int a) {
    if (a == 0) return 0;

    int lastDigit = a % 10;
    int modifiedDigit;
    if (lastDigit % 2 == 0) {
        modifiedDigit = lastDigit + 1;
    } else {
        modifiedDigit = lastDigit - 1;
    }

    return parcom(a / 10) * 10 + modifiedDigit;
}

int main() {
    int numbers[100];
    int complements[100];
    int count = 0;
    while (count < 100) {
        int num;
        cin >> num;
        if (cin.fail()) break;
        numbers[count] = num;
        complements[count] = parcom(num);
        count++;
    }


    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (complements[i] > complements[j]) {

                int temp = complements[i];
                complements[i] = complements[j];
                complements[j] = temp;

                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }


    for (int i = 0; i < (count < 5 ? count : 5); i++) {
        cout << complements[i] << " ";
    }
    cout << endl;

    return 0;
}