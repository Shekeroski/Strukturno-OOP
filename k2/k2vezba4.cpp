#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n;
    cin>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0,j=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i+j>n-1) {          //sporedna dijagonala desen dolu triagolnik a za lev gore treba samo i+j<n-1
                cout<<a[i][j]<<" "; // kaj glavna dijagonala lev dolu triagolnik trebit i>j a za gore desen trebit i<j
            }
        }
    }
return 0;
}