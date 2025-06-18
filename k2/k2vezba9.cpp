#include<iostream>
using namespace std;

void niza(int n,int a[],int i){
    float sum=0;
    if(i==n) {
        return;
    }
    else {
        cout<<a[i]<<" ";
        niza(n,a,i+1);
    }
}
void formula(int n,int a[],int i) {
    int sum=0;
    if(i==n) {
        return;
    }
    else {

        sum+=a[i]+1/a[i+1];
        formula(n,a,i+2);
    }
    cout<<sum<<endl;
}
int main() {
 int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    niza(n,a,0);
}