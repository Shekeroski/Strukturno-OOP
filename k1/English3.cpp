#include<iostream>
using namespace std;
int main() {
    int n,a,flag=1;
    cin>>n;
    a=n-1;
    if(n<9) {
        cout<<"The number is invalid"<<endl;
        flag=0;
    }
    for(int i=a;i>0;i--) {
        int tmp=i;
        int b=0;
        int brojac=0;
        while(tmp>0) {
            b=(b*10)+tmp%10;
            brojac++;
            tmp/=10;
        }
        if(flag){
        if(b%brojac==0) {
            cout<<i<<endl;
            break;
        }
    }
    }
    return 0;
}