#include<iostream>
using namespace std;

void zameniznaci(char *str,char *znaci1,char *znaci2) {
    for(int i=0;str[i]!='\0';i++) {
        for(int j=0;znaci1[j]!='\0';j++) {
            if(str[i]==znaci1[j]) {
                str[i]=znaci2[j];
            }
        }
    }
    for(int i=0;str[i]!='\0';i++) {
        cout<<str[i]<<" ";
    }
}

int main() {
    char znaci1[10],znaci2[10];
    cin.getline(znaci1,10);
    cin.getline(znaci2,10);
    int N;
    cin>>N;
    char chr[100];
    for(int i=0;i<N+1;i++) {
        cin.getline(chr,100);
        zameniznaci(chr,znaci1,znaci2);
    }
  return 0;
}