#include<iostream>
#include<cstring>
using namespace std;
int main() {
int n;
    cin>>n;
    int a[n][n];
    int c[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
   int n1;
    cin>>n1;
    int b[n1];
    int counter=0;
    for(int i=0;i<n1;i++) {
        cin>>b[i];
        counter++;
    }
    int max=0;
    int flag=1;
    int klkcifri;
    cin>>klkcifri;
    int indeks=0;
    int redici;
    int indeksot=0;
    int counter2;
    int countercifri=0;
    while(indeks!=counter) {
        for(int j=0;j<n;j++) {
            redici=b[indeks];
             counter2=0;
            while(a[redici][j]>0) {
                int digit=a[redici][j]%10;
                a[redici][j]/=10;
                counter2++;
            }
            if(counter2==klkcifri) {
                countercifri++;
            }
        }
        if(countercifri>max) {
            max=countercifri;
            indeksot=redici;
        }
        indeks++;
    }
    for(int i=indeksot;i==indeksot;i++) {
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
    }
}