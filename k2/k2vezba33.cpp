#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int s=0;
            if(i+1<n && a[i+1][j]>0) {
                s+=a[i+1][j];
            }
            if(j+1<m && a[i][j+1]>0) {
                s+=a[i][j+1];
            }
            if(i-1>=0 && a[i-1][j]>0) {
                s+=a[i-1][j];
            }
            if(j-1>=0 && a[i][j-1]>0) {
                s+=a[i][j-1];
            }
            b[i][j]=s;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}