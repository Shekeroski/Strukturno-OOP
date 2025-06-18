#include<iostream>
using namespace std;

 int rekurzija(int a,int digit) {
     if(a==0) {
         return 0;
     }
     if (a%10==digit) {
             return 1+rekurzija(a/10,digit);
         }
         else {
             return rekurzija(a/10,digit);
         }
     }
int main() {
    int n,counter=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
     for(int i=0;i<n;i++) {
         int lastdigit=arr[i]%10;
         counter= rekurzija(arr[i],lastdigit);
         cout<<counter<<" ";
     }

    return 0;
}