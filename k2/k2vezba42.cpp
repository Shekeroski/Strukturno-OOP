#include <iostream>
using namespace std;

int main() {
    char str[100];          // Линија од најмногу 100 карактери
    int maxDigits = 0;      // Максимален број на бројки во линија
    int maxLetters = 1;     // Максимален број на букви (иницијализирано на 1 за да се избегне делење со нула)
    double maxRatio = 0.0;  // Максимален однос
    int maxIndex = -1;      // Индекс на последната линија со најголем однос
    char bestLine[100];     // Линија со најголем однос
    int lineIndex = 0;      // Индекс на тековната линија

    while (cin.getline(str, 100)) {
        int digits = 0, letters = 0;

        // Броење на бројки и букви
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                digits++;
            } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                letters++;
            }
        }

        // Игнорирање на линиите без букви
        if (letters == 0) {
            continue;
        }

        // Пресметување на односот
        double ratio = (double)digits / letters;

        // Проверка дали оваа линија има најголем однос досега
        if (ratio > maxRatio || (ratio == maxRatio && lineIndex > maxIndex)) {
            maxRatio = ratio;
            maxIndex = lineIndex;
            maxDigits = digits;
            maxLetters = letters;

            // Зачувување на најдобрата линија
            int i = 0;
            while (str[i] != '\0') {
                bestLine[i] = str[i];
                i++;
            }
            bestLine[i] = '\0';
        }

        lineIndex++;
    }

    // Печатење на линијата со најголем однос
    cout << bestLine << endl;

    return 0;
}