#include<iostream>
using namespace std;
int main() {
    int n,m;
    float x=0,y=0;
    cin>>n>>m;
    float a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i>j) {
                x+=a[i][j];             //da se soberet pod glavna i pod sporedna
            }
        }                       //pod glavna zbirot da se smenit vo glavna dijagonala elementite//pod sporedna zbirot da se smenit vo sporedna elementite
    }                                //aku ima element so e na sredina odnosno e i vo glavna dijagonala i sporedna da se zamenit so zbirot od glv i sprd.
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i+j>n-1) {
                y+=a[i][j];
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==j) {
                a[i][j]=x;
            }
            else if(i+j==n-1) {
                a[i][j]=y;
            }
            else {
                a[i][j]=0;
            }
        }
    }

    if(n%2!=0 && m%2!=0) {
        for(int i=(m/2);i==(m/2);i++) {
            for(int j=0;j<m;j++) {
                if(i==j) {
                    a[i][j]=x+y;
                }
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