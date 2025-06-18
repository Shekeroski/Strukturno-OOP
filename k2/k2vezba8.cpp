#include<iostream>
using namespace std;
int main() {
   int n,m,najdalecen=0;
   cin>>n>>m;
   int a[n][m];
   for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
         cin>>a[i][j];
      }                         //7kolokviumska
   }
   for(int i=0;i<n;i++) {
      float max=0;
      float s=0;
      float avg=0;
      float dif=0;
      for(int j=0;j<m;j++) {
         s+=a[i][j];
      }
      avg=s/(float)m;
      for(int j=0;j<m;j++) {
         dif=abs(a[i][j]-avg);
         if(dif>max) {
            max=dif;
            najdalecen=a[i][j];
         }
      }
      cout<<najdalecen<<endl;
   }
}