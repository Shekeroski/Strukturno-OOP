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
    if(n%2!=0) {
        for(int j=0;j<m;j++) {
            int s1=0;
            int s2=0;
            for(int i=0;i<(n/2);i++) {
                s1+=a[i][j];
            }
            for(int k=(n/2)+1;k<n;k++) {
                s2+=a[k][j];
            }
            int diff=abs(s1-s2);
            for(int i=(n/2);i<=(n/2);i++) {
                a[i][j]=diff;
            }
        }
    }

    if(n%2==0) {
        for(int j=0;j<m;j++) {
            int s1=0;
            int s2=0;
            for(int i=0;i<(n/2);i++) {
                s1+=a[i][j];
            }
            for(int k=(n/2);k<n;k++) {
                s2+=a[k][j];
            }
            int diff=abs(s1-s2);
            for(int i=(n/2)-1;i<=(n/2);i++) {
                a[i][j]=diff;
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
