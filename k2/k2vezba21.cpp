#include<iostream>
using namespace std;

int nizaparenbrojpati(int niza[],int n) {
    int min=999;
    bool flag=false;
     for(int i=0;i<n;i++) {
         int count=0;
         for(int j=0;j<n;j++) {
             if(niza[i]==niza[j]) {
                 count++;
             }
         }
             if(count%2==0 && count>0) {
                 if(niza[i]<min) {
                     min=niza[i];
                     flag=true;
                 }
             }
     }if(flag) {
         cout<<min<<endl;
     } else {
         cout<<0<<endl;
     }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    nizaparenbrojpati(a,n);
    return 0;
}