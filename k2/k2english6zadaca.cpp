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
    int n2,m2;
    cin>>n2>>m2;
    if(a[n2][m2]==1) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(a[n2][m2]==0) {
        for(int i=n2;i>0;i--) {
            int flag=0;
            for(int j=m2;j==m2;j++) {
                if(a[i][j]==0) {
                    a[i][j]=1;
                    flag=1;
                }
                else {
                    break;
                }
            }
            if(flag==0) {
                break;
            }
        }

        for(int i=n2;i<=n-1;i++) {
            int flag=0;
            for(int j=m2;j==m2;j++) {
                if(a[i+1][j]==0) {
                    a[i+1][j]=1;
                    flag=1;
                }
                else {
                    break;
                }
            }
            if(flag==0) {
                break;
            }
        }

     for(int j=m2;j>=0;j--) {
         int flag=0;
         for(int i=n2;i==n2;i++) {
             if(a[i][j-1]==0) {
                 a[i][j-1]=1;
                 flag=1;
             }
             else {
                 break;
             }
         }
         if(flag==0) {
             break;
         }
     }

        for(int j=m2;j<=m-1;j++) {
            int flag=0;
            for(int i=n2;i==n2;i++) {
                if(a[i][j+1]==0) {
                    a[i][j+1]=1;
                    flag=1;
                }
                else {
                    break;
                }
            }
            if(flag==0) {
                break;
            }
        }
       for(int i=0;i<n;i++) {
           for(int j=0;j<m;j++) {
               cout<<a[i][j]<<" ";
           }
           cout<<endl;
       }
    }
    return 0;
}