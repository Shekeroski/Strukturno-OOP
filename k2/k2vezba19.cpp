#include<iostream>
using namespace std;
int main() {
    int n,m,r,k,min=999;
    cin>>n>>m>>r>>k;
    int arr[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]<min) {
                min=arr[i][j];
            }
        }
    }
    for(int i=r-1;i>=0;i--) {
        for(int j=0;j<k;j++) {
             arr[i][j]=min;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}