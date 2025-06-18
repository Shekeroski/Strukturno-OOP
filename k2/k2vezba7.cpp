#include<iostream>
using namespace std;
int main() {
    int n,m,s1=0,s2=0,s3=0,s4=0,flag2=1,flag3=1;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }                                      //kvadranti vezba 4
    int ind1,ind2;
    cin>>ind1>>ind2;
    if(ind1==n-1) {
        for(int i=0;i<=ind1-1;i++) {
            for(int j=0;j<=ind2-1;j++) {
                s2+=a[i][j];
                flag2=0;
            }
        }
    }
    if(flag2) {
        for(int i=0;i<ind1;i++) {
            for(int j=0;j<ind2;j++) {
                s2+=a[i][j];
            }
        }
    }
    for(int i=0;i<=ind1-1;i++) {
        for(int j=ind2;j<m;j++) {
            s1+=a[i][j];
        }
    }
    if(ind1==n-1) {
        for(int i=ind1,j=0;j<ind2;j++) {
            s3+=a[i][j];
            flag3=0;
        }
    }
    if(flag3) {
        for(int i=ind1;i<n;i++) {
            for(int j=0;j<ind2;j++) {
                s3+=a[i][j];
            }
        }
    }
    for(int i=ind1;i<n;i++) {
        for(int j=ind2;j<m;j++) {
            s4+=a[i][j];
        }
    }
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
}