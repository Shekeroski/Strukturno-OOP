#include<iostream>
using namespace std;
int main() {
    int n,m,z;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
   cin>>z;
   for(int j=0;j<=m-z;j++) {
       for(int i=0;i<=n-z;i++) {
           int s=0;
           int counter=0;
           for(int k=i;k<z+i;k++) {
               counter++;
               for(int l=j;l<z+j;l++) {
                   if(counter==2) {
                       s+=a[k][j+1];
                       break;
                   }
                   s+=a[k][l];
               }
           }
           a[i][j]=s;
       }
   }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
