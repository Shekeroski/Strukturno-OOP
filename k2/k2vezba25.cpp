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
    for(int i=0;i<n;i++) {
        int counter=0;
        for(int j=0;j<m;j++) {
            int flag=1;
            int s=0;
            s+=i+j;
            int paren=(a[i][j]%2==0) ? 0 : 1;
            if(paren==(s%2)) {
                counter++;
            }
        }
        cout<<i<<" : "<<counter<<endl;
    }
    return 0;
}