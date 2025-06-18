#include<iostream>
using namespace std;

int Odd (int a [], int n){
     if(n==0) {
          return 0;
     }
     else {
          if(a[n-1]%2!=0) {

               return a[n-1] + Odd(a,n-1);
          }
          else {
               return Odd(a,n-1);
          }
     }
}
int main() {
    int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++) {
          cin>>a[i];
     }
     cout<<Odd(a,n);
}