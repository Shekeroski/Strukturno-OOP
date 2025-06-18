#include<iostream>
using namespace std;

int faktoriel(int n) {
   if (n==1) {
       return 1;
   }else {
       return n*faktoriel(n-1);
   }
}

int strongnumber(int n) {
    int sum=0;
    while(n!=0) {
        int c=n%10;
        n/=10;
        sum+=faktoriel(c);
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    int imastrong=false;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        if(strongnumber(a[i])==a[i]) {
            if (!imastrong) {
                cout << "Strong numbers:" << endl;
            }
            cout<<a[i]<<endl;
            imastrong=true;
        }
    }
    if (!imastrong) {
        cout << "Not a strong number" << endl;
    }
    return 0;
}