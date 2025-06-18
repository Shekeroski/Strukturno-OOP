#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void samoglaski(char str[], int k) {
    char result[100];  // Резултатниот стринг (доста голем за да собере дополнителните карактери)
    int len = strlen(str);
    int pos = 0;  // Позиција за пополнување на резултатниот стринг

    for (int i = 0; i < len; i++) {
        result[pos++] = str[i];  // Копирање на тековниот карактер

        // Проверка дали е самогласка
        char lowerChar = tolower(str[i]);
        if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u') {
            // Додавање на `k` копии од самогласката
            for (int j = 0; j < k; j++) {
                result[pos++] = str[i];
            }
        }
    }

    result[pos] = '\0';  // Завршување на резултатниот стринг

    cout << result << endl;  // Печатење на резултатот
}

int main() {
    char str[50];
    int k;

    cout << "Vnesi broj k: ";
    cin >> k;
    cin.ignore();  // Игнорирање на нов ред по внесот на `k`

    cout << "Vnesi recenica: ";
    cin.getline(str, 50);  // Внесување на стрингот

    samoglaski(str, k);  // Повик на функцијата

    return 0;
}