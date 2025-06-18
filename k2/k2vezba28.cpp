#include<iostream>
using namespace std;
int main() {
    int n,m,max;
    cin>>n>>m;
    int a[n][m];
    int c[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
   for(int i=0;i<n;i++) {
       for(int j=0;j<m;j++) {
           c[i][j]=a[i][j];
       }
   }
    int n_size;
    int n1=1;
    int n2;
    int indeks;
    int b[10];
    cin>>n_size;
     for(int i=0;i<n_size;i++) {
         cin>>b[i];
     }
         cin>>n2;
         for(int i=0;i<n_size;i++) {
             int k=b[i];
                 int count=0;
                 for(int j=0;j<m;j++) {
                     int counter=0;
                     while(a[k][j]>0) {
                         int temp=a[k][j]%10;
                         a[k][j]/=10;
                         counter++;
                     }
                     if(counter==n2) {
                         count++;
                     }
                 }
                  if(count>max) {
                      max=count;
                       indeks=k;
                  }
         }
    for(int i=indeks+1;i==indeks+1;i++) {
        for(int j=0;j<m;j++) {
            cout<<c[i][j]<<" ";
        }
    }
    return 0;
}