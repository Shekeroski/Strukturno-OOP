#include<iostream>
using namespace std;

int pozitivnivoniza(int niza[],int n,int i) {
    if(i==n) {
        return 0;
    }
    else {
        if(niza[i]>0) {
            return 1+pozitivnivoniza(niza,n,i+1);
        }
    }                                             //pozitivni vo niza so rekurzija
}

int main() {
   int n,i,s=0,zbir=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<pozitivnivoniza(a,n,0);
}