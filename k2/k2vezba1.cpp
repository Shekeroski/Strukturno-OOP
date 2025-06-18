#include <iostream>
using namespace std;
int main() {
    char a;
    char c;
    int count=0;
    while(true) {
        cin >> a;
        if(a=='#') {
            break;
        }
        if(a>='A' && a<='Z') {
            a=a+('a'-'A');
        }
        if((c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ) && ( a=='a' || a=='e' || a=='i' || a=='o' || a=='u')) {
           cout<<c<<a<<endl;
            count++;
        }
        c=a;
    }
   cout<<count<<endl;
    return 0;
}