#include<iostream>
using namespace std;

struct Grad {
    char ime[10];
    int ziteli;
};
struct Pretsedatel {
    char ime [10];
    char partija[10];
};
struct Drzava {
    char imedrzava[10];
    Pretsedatel p;
    Grad g;
    int populacija;
};
void read(Drzava *d,int n) {
    for(int i=0;i<n;i++) {
        cin>>d->imedrzava>>d->p.ime>>d->p.partija>>d->populacija>>d->g.ime>>d->g.ziteli;
    }
}
void write(Drzava *d,int n) {
    Drzava max=d[0];
    for(int i=0;i<n;i++) {
        if(d[i].g.ziteli>max.g.ziteli) {
            max=d[i];
        }
    }
    cout<<max.p.ime;
}
int main() {
    int n;
    cin>>n;
    Drzava d[n];
    read(d,n);
    write(d,n);
}