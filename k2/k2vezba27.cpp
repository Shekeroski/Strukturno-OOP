#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
   int N;
     cin>>N;
    for(int i=0;i<=n-N;i++) {
        for(int j=0;j<=m-N;j++) {
            int s=0;
            int counter=0;
              for(int l=j;l<N;l++) {
                  counter++;
                  for(int k=i;k<N;k++) {
                      if(counter==2) {
                          s+=a[k+1][l];
                          break;
                      }
                      s+=a[k][j];
                  }
              }
            a[i][j]=s;
        }
    }
     for(int i=0;i<n;i++) {
         for(int j=0;j<m;j++) {
             cout<<a[i][j]<<" ";
         }
     }
    return 0;
}
