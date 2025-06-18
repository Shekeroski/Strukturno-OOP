#include<iostream>
using namespace std;

void poramnet(int a,int nov) {
   if(a==0) {
      return;
   }
   else {
          poramnet(a/10,nov);
   }
   int digit=a%10;
   if(digit==9) {
      digit=7;
   }
   nov=nov*10+digit;
}

int main(){
   int n,nov=0,counter=0;
   int numbers[10];
   while(cin>>n) {
      poramnet(n,nov);
      numbers[counter++]=nov;
   }
      if(counter>=2) {
         for(int i=0;i<counter;i++) {
            for(int j=i+1;j<counter;j++) {
               if (numbers[j] < numbers[i]) {
                  // Разменете ги бројките
                  int temp = numbers[i];
                  numbers[i] = numbers[j];
                  numbers[j] = temp;
               }
            }
         }
      }
      cout << "Првите 5 најмали броеви по замена на 9 со 7:" << endl;
      for (int i = 0; i < 5 && i < counter; i++) {
         cout << numbers[i] << endl;
      }
}