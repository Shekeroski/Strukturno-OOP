#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }

     for( int i=0;i<m;i++) {
         int flag=1;
         int counter=0;
         for(int j=0;j<n;j++) {
             if(i==0) {
                 if( a[j][i]%10==i && (a[j][i]/10)%10==j ) {
                     counter++;
                 }
                 flag=0;
             }
             if(flag) {
                 if(a[j][i]%10==i && (a[j][i]/10)%10==j) {
                     counter++;
                 }
                 else if(a[i][j]>99 && a[i][j]%100==i && (a[i][j]/100)%10==j) {
                     counter++;
                 }
             }
         }
         cout<<counter<<endl;
     }
    return 0;
}