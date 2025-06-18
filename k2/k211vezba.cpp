#include<iostream>
using namespace std;
int main() {
    int n,m,X;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    cin>>X;
    for(int i=0;i<n;i++) {
        int suma=0;
        for(int j=0;j<m;j++) {
            suma+=a[i][j];
        }
        if(suma>X) {
            for(int j=0;j<m;j++) {
                a[i][j]=1;
            }
        }
        else if(suma<X) {
            for(int j=0;j<m;j++) {
                a[i][j]=-1;
            }
        }
        else {
            for(int j=0;j<m;j++) {
                a[i][j]=0;
            }
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