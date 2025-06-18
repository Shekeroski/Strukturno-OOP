#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i]==a[j]) {
                a[i]+=a[i];
                a[i+1]=0;
                break;
            }
            break;
        }
    }
    int index=0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            a[index] = a[i];
            if (index != i) {
                a[i] = 0;
            }
            index++;
        }
    }
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}