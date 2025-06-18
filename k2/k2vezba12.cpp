#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n*2][n*2];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n*2;j++) {
            cin>>a[i][j];
        }
    }
                               //vnesvis n pa da ima redici n a koloni da ima n*2
    for(int i=0;i<=n;i++) {   // pa da se pecati primer 1. 123456,2. 123456,3. 123456
        int flag=1;          // pa da se ispecati 1. 123,2. 123,3. 123,4. 456,5. 456,6. 456
        for(int j=0;j<n;j++) {
            if(i>=n) {
                for( int k=0;k<n;k++) {
                    for( j=n;j<(n*2);j++) {
                        cout<<a[k][j]<<" ";
                        flag=0;
                    }
                    cout<<endl;
                }
            }
            if(flag) {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}