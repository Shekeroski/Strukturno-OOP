#include <iostream>
using namespace std;

struct Student {
    char name[10];
    int index;
    int courses;
    int codes[10];
};

struct Course {
    char name[10];
    int code;
};

int mostPopularCourse(Student s[], int n, Course co[], int c) {
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].courses; j++) {
            count[s[i].codes[j]]++;
        }
    }

    int maxCount = 0;
    int popularCourse = -1;
    for (int i = 0; i < c; i++) {
        if (count[co[i].code] > maxCount) {
            maxCount = count[co[i].code];
            popularCourse = co[i].code;
        }
    }

    return popularCourse;
}

int main() {
    int n, c;
    cin >> n >> c;

    Student s[n];
    Course co[c];

    for (int i = 0; i < c; i++) {
        cin >> co[i].name >> co[i].code;
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].index >> s[i].courses;
        for (int j = 0; j < s[i].courses; j++) {
            cin >> s[i].codes[j];
        }
    }

    int popularCourse = mostPopularCourse(s, n, co, c);
    cout << "The most popular course is: " << popularCourse << endl;

    return 0;
}