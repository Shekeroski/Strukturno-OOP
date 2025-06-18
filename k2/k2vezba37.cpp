#include<iostream>
using namespace std;
int main() {
    int n,counter=0;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }

   for(int i=0;i<n;i++) {
       for(int j=0;j<n;j++) {
           if(i==j) {
               if(a[i][j]!=0) {
                   a[i][j]=0;
                   counter++;
               }
           }
       }
   }

   for(int i=0;i<n;i++) {
       for(int j=0;j<n;j++) {
           if(a[i][j]!=a[j][i]) {
               a[i][j]=a[j][i];
               counter++;
           }
       }
   }
    cout<<counter;
    return 0;
}