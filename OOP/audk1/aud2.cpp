#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
struct Student {
    char name[100];
    char surname[100];
    char index[10];
    int totalPoints;
    void print() {
        cout << name << " " << surname << " " << index << " " << totalPoints << endl;
    }
};

void normalize (char *niza) {
    niza[0] = toupper(niza[0]);
    for (int i = 1; i < strlen(niza); i++) {
        niza[i] = tolower(niza[i]);
    }
}

void read (Student &s) {
    cin >> s.name >> s.surname >> s.index;
    normalize(s.name);
    normalize(s.surname);
    int z1, z2, z3, z4;
    cin >> z1 >> z2 >> z3 >> z4 ;
    s.totalPoints = z1 + z2 + z3 + z4;
}
void sort (Student *students, int n) {
    Student temp;
        for (int j = 0; j <= n - 2; j++) {
            if (students[j].totalPoints < students[j + 1].totalPoints) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
int main() {
    Student students[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        read(students[i]);
    }
    sort(students, n);
    for (int i = 0; i < n; i++) {
        students[i].print();
    }
}