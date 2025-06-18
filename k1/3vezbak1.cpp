/*Од стандарден влез се чита еден природен број n.
 *Меѓу природните броеви помали од n, да се најде оној чиј што збир на делителите е најголем.
Во пресметувањето на збирот на делителите на даден број, да не се зема предвид самиот број.
 */
#include<iostream>
using namespace std;
int main() {
 int n,max=0,maxn=0;
cin>>n;
 for(int i=1;i<n;i++) {
 int s=0;
  for(int j=1;j<i;j++) {
   if(i%j==0) {
    s+=j;
   }
  }
   if(s>max) {
    max=s;
    maxn=i;
   }
 }
 cout<<maxn<<endl;
 return 0;
}