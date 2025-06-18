#include<iostream>
using namespace std;
int main() {
    int a,b,c,d;
    cin>>a>>b;
    for(int i=a;i<b;i++) {
       int tmp=i;
        int s=1;
        int firstdigit=i;
        int lastdigit=tmp%10;
        while(firstdigit>=10) {
            firstdigit/=10;
        }
        int middledigits=(tmp/10)/10;
        s*=middledigits;
        if(s/firstdigit+lastdigit==0) {
            cout<<i<<endl;
        }
    }
}