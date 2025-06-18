#include<iostream>
using namespace std;
int main() {
    int a,zbir=0;
    char n;
    while(true) {
        cin>>n;
        if(n=='.') {
            break;
        }
        if(n>='0' && n<='9') {
            zbir+=n-'0';
        }
        else if(n>='A' && n<='F') {
            zbir+=n-'A'+10;
        }
    }
    cout<<zbir;
    return 0;
}
