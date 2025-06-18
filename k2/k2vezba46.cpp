#include<iostream>
using namespace std;

int funkcija(int a[], int n, int k) {
    int max_abbreviated = 0;

    for(int i = 0; i < n; i++) {
        int b[10];
        int indeks = 0;
        int num = a[i];

        while(num > 0) {
            int temp = num % 10;
            if(temp > k) {
                b[indeks++] = temp;
            }
            num = num / 10;
        }
        int abbreviated_number = 0;
        for(int j = indeks - 1; j >= 0; j--) {
            abbreviated_number = abbreviated_number * 10 + b[j];
        }
        if(abbreviated_number > max_abbreviated) {
            max_abbreviated = abbreviated_number;
        }
    }
    return max_abbreviated;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    int max_number = funkcija(arr, n, k);
    cout << "Max abbreviated number: " << max_number << endl;

    return 0;
}