#include<iostream>
using namespace std;

struct Engine {
    int kojnskasila;
    int vrtezen_moment;
};

struct car {
    char ime[10];
    int godina;
    Engine engine;
    void print() {
        cout<<ime<<" "<<godina<<" "<<engine.kojnskasila<<" "<<engine.vrtezen_moment<<endl;
    }
};
void read(car &r) {
    cin>>r.ime;
    cin>>r.godina;
    cin>>r.engine.kojnskasila;
    cin>>r.engine.vrtezen_moment;
}

void sort(car *r,int n) {
    car temp;
    for(int i=0;i<n-1;i++) {
        for(int j=i;j<n;j++) {
            if(r[i].engine.kojnskasila>r[j].engine.kojnskasila) {
                temp=r[j];
                r[j]=r[i];
                r[i]=temp;
            }
        }
    }
}
void display(car *r, int n) {
    car temp;
    for (int i = 0; i < 2; i++) {
        for (int j = i; j < 2; j++) {
            if(r[i].engine.kojnskasila<r[j].engine.kojnskasila) {
                 temp=r[j];
                r[j]=r[i];
                r[i]=temp;
            }
        }
    }
}
int main() {
    car r[10];
   int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        read(r[i]);
    }
    sort(r,n);
   display(r,n);
    for(int i=0;i<1;i++) {
        cout<<r[i].ime<<""<<r[i].engine.kojnskasila <<endl;
    }
}