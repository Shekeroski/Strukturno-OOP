#include<iostream>
using namespace std;
int main() {
   int n[10];
   int N;
   int a;
   int c=0;
   int s=0;
   cin>>N;
   for(int i=0;i<N;i++) {
      cin>>n[i];
   }
      cin>>a;
      if(a>N) {
         cout<<"netocen input"<<endl;
      }
      for(int i=a;i<N;i++) {
         s+=n[i];
      }

      cout<<s<<endl;
   return 0;
}