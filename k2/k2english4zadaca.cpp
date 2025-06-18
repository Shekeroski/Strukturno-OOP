#include<iostream>
using namespace std;

int tribroja(int a,int b,int c) {
    int flag=1;
    int counter1=0,counter2=0;
    int a1=a;
    int b1=b;
    while(a>0) {
        int temp=(a/10)%10;
        a/=100;
        if(temp==c) {
            counter1++;
        }
    }
    while(b>0) {
        int tmp=(b/10)%10;
        b/=100;
        if(tmp==c) {
            counter2++;
        }
    }if(counter1==counter2) {
        cout<<a1<<endl;
        flag=0;
    }if(flag) {
        if(counter1>counter2) {
            cout<<a1<<endl;
        }
        else {
            cout<<b1<<endl;
        }
    }

}

int main() {
    int a;
    int b;
    int c;
    while(cin>>a>>b>>c) {
        tribroja(a,b,c);
    }
    return 0;
}