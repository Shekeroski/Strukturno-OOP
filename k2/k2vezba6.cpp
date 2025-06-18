#include<iostream>
using namespace std;
int main() {
    int n,N,max=0,maxbroj=0,maxr=0;
    cin>>n;
    int a[n],b[n],c,k;
    while(N!=0) {
        cin>>N;
        for(int i=0;i<N;i++) {
            int flag=1;
            cin>>a[i];
            b[N]=a[i];
            c=a[i];
          while(b[N]>=10) {
              b[N]/=10;
          }
            if(b[N]>max) {
                max=b[N];
                maxbroj=a[i];
                flag=0;
            }
            if(flag) {
                if(b[N]==max) {
                    while(c>99) {
                        c/=10;
                    }
                    while(k>99) {
                        k/=10;
                    }
                    if(c>k) {
                        maxbroj=a[i];
                    }
                }
            }
            if(!flag) {
                k=a[i];
            }
        }
        cout<<maxbroj<<endl;
    }

    return 0;
}