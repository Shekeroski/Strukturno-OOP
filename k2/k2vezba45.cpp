#include <iostream>
using namespace std;
void printLine(int current, int n) {
    if (current > n)
        return;
    cout << current;
    printLine(current + 1, n);
}

void triangle(int n, int currentLine = 1) {
    if (currentLine > n)
        return;
    printLine(1, currentLine);
    cout << endl;
    triangle(n, currentLine + 1);
}

int main() {
    int n;
    cout << "Внесете го бројот n: ";
    cin >> n;

    triangle(n);

    return 0;
}