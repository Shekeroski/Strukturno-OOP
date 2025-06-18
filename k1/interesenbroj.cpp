#include<iostream>
using namespace std;
int main() {
    int n,a,obraten=0,flag=true,brojac=0;
    cin>>n;
    if(n<9) {
        cout<<"nevaliden broj"<<endl;
    }
    else {
        while(n>0) {
            a=n%10;
            brojac++;
            obraten=obraten*10+a;
            n/=10;
        }
        if(obraten%brojac!=0) {
            flag=false;
        }
        if(flag) {
            cout<<"brojot e interesen"<<endl;
        }
    }
    return 0;
}