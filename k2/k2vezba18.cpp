#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[10][10];
    int d=1;
    while(d*d<n) {
        d++;
    }
        int b=1;
       for(int m=0;m<d;m++) {
           if(m%2==0) {
               for(int i=0;i<d;i++) {
                   if(b<=n) {
                       a[i][m]=b++;
                   }
               }
           }
           else {
               for(int i=d-1;i>=0;i--) {
                   if(b<=n) {
                       a[i][m]=b++;
                   }
               }
           }
       }
        for(int i=0;i<d;i++) {
            for(int j=0;j<d;j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
    }
