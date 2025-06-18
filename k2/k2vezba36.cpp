#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
   int max=0;
    int min=9999;
   for(int i=0;i<n;i++) {
       for(int j=0;j<n;j++) {
           if(i>j) {
               if(a[i][j]>max) {
                   max=a[i][j];
               }
           }
           if(i<j) {
               if(a[i][j]<min) {
                   min=a[i][j];
               }
           }
       }
   }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i>j) {
                a[i][j]=max;
            }
            if(j>i) {
                a[i][j]=min;
            }
        }
    }


    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}