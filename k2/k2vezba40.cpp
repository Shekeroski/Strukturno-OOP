#include<iostream>
#include<cstring>
using namespace std;

int brojSvrznici(char recenica[]) {
    int brojac=0;
    int zborDolz=0;

    for(int i=0;recenica[i]!='\0';i++) {
        if(isalpha(recenica[i])) {
            zborDolz++;
        } else {
            if(zborDolz>0 && zborDolz<=3) {
                brojac++;
            }
            zborDolz=0;
        }
    }

    if(zborDolz>0 && zborDolz<=3) {
        brojac++;
    }
    return brojac;
}

int main() {
    char recenica[101];
    char maxRecenica[101];
    int maxSvrznici=0;

    while(cin.getline(recenica, 101)) {
        int svrznici=brojSvrznici(recenica);

        if(svrznici>maxSvrznici) {
            maxSvrznici=svrznici;
            strcpy(maxRecenica, recenica);
        }
    }

    cout<<maxSvrznici<<": "<<maxRecenica;
}