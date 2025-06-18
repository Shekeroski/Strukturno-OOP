#include<iostream>
using namespace std;

int calculate_sum(int a[10][10],int startrow,int startcolumn,int sizen) {
    int sum=0;
        for(int j=0;j<sizen;j++) {
            sum+=a[startrow][startcolumn+j];
    }
    return sum;
}

int main() {
    int n,N,m;
    cin>>n>>m>>N;
    int a[10][10];
    int b[10][10];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            b[i][j]=calculate_sum(a,i,j,N);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<b[i][j]<<" ";
        }
    }
    return 0;
}