#include<iostream>
using namespace std;
int main() {
    int n,m,a;
    cin>>n>>m;
    for(int i=n;i<=m;i++) {
        int tmp=i;
        int flag=true;
        while(tmp>0) {
            a=tmp%10;
            if(a%2!=0) {
                flag=false;
            }
            tmp/=10;
        }
        if(flag) {
            cout<<i<<" ";
        }
    }
    return 0;
}
