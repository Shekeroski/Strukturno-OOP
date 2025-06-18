#include<iostream>
using namespace std;
int main() {
    int n,m,brojac1=0,brojac2=0;
    cin>>n>>m;
    int a[n][m];
   for(int i=0;i<n;i++) {
       for(int j=0;j<m;j++) {
           cin>>a[i][j];
       }
   }                               //3 posledovatelni 1 po red i kolona
   for(int i=0;i<n;i++) {
       for(int j=0;j<m-2;j++) {
           if(a[i][j]==1) {
               if(a[i][j+1]==1 && a[i][j+2]==1) {
                   brojac1++;
                   break;
               }
           }
       }
   }
           for (int j = 0; j < m; j++) {
               for (int i = 0; i < n - 2; i++) {
                   if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1) {
                       brojac2++;
                       break;
                   }
               }
           }


    cout<<brojac1+brojac2<<endl;
    return 0;
}