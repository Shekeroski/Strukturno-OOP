#include<iostream>
using namespace std;

int najprvacifra(int a) {
    int b=a;
        if(b>=10) {
            return najprvacifra(b/10);
        }
    int min=9;
    int c=a;
    if(c>0) {
        int d=c%10;
        if(d<min) {
            min=d;
        }
        c/=10;
    }
    if(min%2==0 && b%2!=0) {
        return a;
    }
}
void rekurzija(int a[],int n,int i) {
    if(i==n) {
        return;
    }else {
        if(najprvacifra(a[i])) {
            cout<<a[i]<<" ";
        }
        return rekurzija(a,n,i+1);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    rekurzija(a,n,1);
    return 0;
}