#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char str[100];
    while (cin.getline(str, 100)) {
        int i = 0;

        while (str[i] != '\0') {
            if (isalpha(str[i])) {
                cout << str[i];
            }
            else if (isspace(str[i])) {
                cout << endl;
            }
            i++;
        }
    }
    return 0;
}