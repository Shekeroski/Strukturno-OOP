#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n][n];
    int b[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int counter=0;
            if(i>0 && i<n-1 && j>0 && j<n-1) {
                if(a[i-1][j]==1) {
                    counter++;
                } if( a[i][j+1]==1) {
                    counter++;
                } if(a[i+1][j]==1) {
                    counter++;
                } if(a[i][j-1]==1) {
                    counter++;
                }
                if(counter>=3) {
                    a[i][j]=1;
                }
            }
            if(i>0 && i<n-1 && j==0) {
                if(a[i][j+1]==1) {
                    counter++;
                } if(a[i-1][j]==1) {
                    counter++;
                } if(a[i+1][j]==1) {
                    counter++;
                }
                if(counter>=3) {
                    a[i][j]=1;
                }
            }
            if(i>0 && i<n-1 && j==n-1) {
                if(a[i-1][j]==1) {
                    counter++;
                } if( a[i+1][j]==1) {
                    counter++;
                } if(a[i][j-1]==1) {
                    counter++;
                }
                if(counter>=3) {
                    a[i][j]=1;
                }
            }
            if(j>0 && j<n-1 && i==0) {
                if(a[i][j-1]==1) {
                    counter++;
                } if(a[i+1][j]==1) {
                    counter++;
                } if( a[i][j+1]==1) {
                    counter++;
                }
                if(counter>=3) {
                    a[i][j]=1;
                }
            }
            if(j>0 && j<n-1 && i==n-1) {
                if(a[i][j-1]==1) {
                    counter++;
                } if(a[i-1][j]==1) {
                    counter++;
                } if( a[i][j+1]==1) {
                    counter++;
                }
                if(counter>=3) {
                    a[i][j]=1;
                }
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