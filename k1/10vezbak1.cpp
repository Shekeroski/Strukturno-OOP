#include<iostream>
using namespace std;
int main() {
    int n;
    float brojac=0;
    float art;
    float srednavrednost=0;
    cin>>n;
    if(n<0) {
        return 0;
    }
    for(int i=n;i>0;i--) {
        if(i%2==0) {
            int p=i*i;
            brojac++;
            cout<<i<<" * "<< i<<"= "<<p<<endl;
            srednavrednost+=p;
        }
    }
    cout<<srednavrednost<<endl;
    cout<<srednavrednost/brojac<<endl;
    return 0;
}