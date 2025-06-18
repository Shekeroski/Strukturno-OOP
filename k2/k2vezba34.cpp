#include<iostream>
using namespace std;
int main() {
    char str[100];
    int indeks=0;
    int indeks2=0;
    int count=0;
    cin.getline(str, 100);
    int len = strlen(str);
    for(int i=0;i<len;i++) {
        if(isalpha(str[i])) {
            count++;
        }
    }
    if(count==len) {
        cout<<"No Digits"<<endl;
        return 0;
    }
    for(int i = 0; i < len; i++) {
        if(isdigit(str[i])) {
            indeks=i;
            break;
        }
    }
    char str2[100];
    strcpy(str2,str+indeks);
    int length=strlen(str2);
    for(int i = 1; i < length; i++) {
        if(isdigit(str2[i])) {
            indeks2=i;
            break;
        }
    }

    if(indeks2==0) {
        char str4[100];
        strcpy(str4,str+indeks);
        for(int i = 0; i < length; i++) {
            cout<<str4[i];
        }
    }

    if(indeks2>0) {
        char str3[100];
        strcpy(str3,str2);
        int length3=strlen(str3);
        for(int i = 0; i <=indeks2; i++) {
            cout<<str3[i];
        }
    }
    return 0;
}