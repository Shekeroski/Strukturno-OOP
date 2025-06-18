#include<iostream>
#include<cstring>
using namespace std;

class Patnik {
    char name[10];
    int br;
    bool velosiped;
public:
    void print() {
        cout<<name<<" "<<br<<" "<<velosiped<<endl;
    }
    bool getVelosiped() {
        return velosiped;
    }
};
class Voz {
    char kraj[10];
    Patnik patnik[20];
    int brelementi;
    int vkpvelosipedi;
public:
    void addPatnik(Patnik &p) {
        int broj=0;
        if(!patnik->getVelosiped()) {
            patnik[brelementi++]=p;
        }else {
            for(int i=0;i<brelementi;i++) {
                if(patnik[i].getVelosiped()) {
                    broj++;
            }
        }
            if(broj<vkpvelosipedi) {
                patnik[brelementi++]=p;
            }else {
                 cout<<"nema mesto za velosiped na vozot"<<endl;
            }
    }
};

int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++){
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
