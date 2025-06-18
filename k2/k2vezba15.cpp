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
    if(m%2!=0) {
        for(int i=0;i<n;i++) {
            int s=0;
            int s2=0;
            int razmena=0;
            for(int j=0;j<m/2;j++) {
                s+=a[i][j];
            }
            for( int k=(m/2)+1;k<m;k++) {
                s2+=a[i][k];
            }
            razmena=abs(s-s2);
            for(int d=m/2;d==m/2;d++) {
                a[i][d]=razmena;
            }
        }
    }

    if(m%2==0) {
        for(int i=0;i<n;i++) {
            int s3=0;
            int s4=0;
            int razmenaa=0;
            for(int j=0;j<=(m/2)-1;j++) {
                s3+=a[i][j];
            }
            for(int k=(m/2);k<m;k++) {
                s4+=a[i][k];
            }
            razmenaa=abs(s3-s4);
            for(int d=(m/2)-1;d==(m/2)-1;d++) {
                a[i][d]=razmenaa;
            }
            for(int d=(m/2);d==m/2;d++) {
                a[i][d]=razmenaa;
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}